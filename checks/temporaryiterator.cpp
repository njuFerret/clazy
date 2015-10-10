/*
   This file is part of the clang-lazy static checker.

  Copyright (C) 2015 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com
  Author: Sérgio Martins <sergio.martins@kdab.com>

  Copyright (C) 2015 Sergio Martins <smartins@kde.org>
  Copyright (C) 2015 Nyall Dawson <nyall.dawson@gmail.com>

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License along
  with this program; if not, write to the Free Software Foundation, Inc.,
  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.

  As a special exception, permission is given to link this program
  with any edition of Qt, and distribute the resulting executable,
  without including the source code for Qt in the source distribution.
*/

#include "checkmanager.h"
#include "temporaryiterator.h"
#include "Utils.h"
#include "StringUtils.h"

#include <clang/AST/DeclCXX.h>
#include <clang/AST/Expr.h>
#include <clang/AST/ExprCXX.h>

using namespace clang;
using namespace std;

TemporaryIterator::TemporaryIterator(const std::string &name)
    : CheckBase(name)
{
    m_methodsByType["vector"] = {"begin", "end", "cbegin", "cend" }; // TODO: More stl support
    m_methodsByType["QList"] = { "begin", "end", "constBegin", "constEnd", "cbegin", "cend" };
    m_methodsByType["QVector"] = { "begin", "end","constBegin","constEnd", "cbegin", "cend", "insert" };
    m_methodsByType["QMap"] = {"begin", "end", "constBegin", "constEnd", "find", "constFind", "lowerBound","upperBound", "cbegin", "cend", "equal_range" };
    m_methodsByType["QHash"] = {"begin", "end", "constBegin", "constEnd", "cbegin", "cend", "find", "constFind", "insert", "insertMulti" };
    m_methodsByType["QLinkedList"] = {"begin", "end", "constBegin", "constEnd", "cbegin", "cend"};
    m_methodsByType["QSet"] = {"begin", "end", "constBegin", "constEnd", "find", "constFind", "cbegin", "cend"};
    m_methodsByType["QStack"] = m_methodsByType["QVector"];
    m_methodsByType["QQueue"] = m_methodsByType["QList"];
    m_methodsByType["QMultiMap"] = m_methodsByType["QMap"];
    m_methodsByType["QMultiHash"] = m_methodsByType["QHash"];
}

static bool isBlacklistedFunction(const string &name)
{
    // These are fine
    static const vector<string> list = {"QVariant::toList"};
    return std::find(list.cbegin(), list.cend(), name) != list.cend();
}

void TemporaryIterator::VisitStmt(clang::Stmt *stm)
{
    CXXMemberCallExpr *memberExpr = dyn_cast<CXXMemberCallExpr>(stm);
    if (!memberExpr)
        return;

    CXXRecordDecl *classDecl = memberExpr->getRecordDecl();
    CXXMethodDecl *methodDecl = memberExpr->getMethodDecl();
    if (!classDecl || !methodDecl)
        return;

    // Check if it's a container
    const std::string className = classDecl->getNameAsString();
    auto it = m_methodsByType.find(className);
    if (it == m_methodsByType.end())
        return;

    // Check if it's a method returning an iterator
    const std::string functionName = methodDecl->getNameAsString();
    const auto &allowedFunctions = it->second;
    if (std::find(allowedFunctions.cbegin(), allowedFunctions.cend(), functionName) == allowedFunctions.cend())
        return;


    // Catch variant.toList().cbegin(), which is ok
    CXXMemberCallExpr *chainedMemberCall = Utils::getFirstChildOfType<CXXMemberCallExpr>(memberExpr);
    if (chainedMemberCall) {

        if (isBlacklistedFunction(StringUtils::qualifiedMethodName(chainedMemberCall->getMethodDecl())))
            return;
    }

    Expr *expr = memberExpr->getImplicitObjectArgument();

    if (!expr || !expr->isRValue()) // This check is about detaching temporaries, so check for r value
        return;

    const Type *containerType = expr->getType().getTypePtrOrNull();
    if (!containerType || containerType->isPointerType())
        return;

    {
        // *really* check for rvalue
        ImplicitCastExpr *impl = dyn_cast<ImplicitCastExpr>(expr);
        if (impl) {
            if (impl->getCastKind() == CK_LValueToRValue)
                return;
            auto childs = Utils::childs(impl);
            if (!childs.empty() && isa<ImplicitCastExpr>(childs[0]) && dyn_cast<ImplicitCastExpr>(childs[0])->getCastKind() == CK_LValueToRValue)
                return;
        }
    }

    CXXConstructExpr *possibleCtorCall = dyn_cast_or_null<CXXConstructExpr>(Utils::getFirstChildAtDepth(expr, 2));
    if (possibleCtorCall)
        return;

    CXXThisExpr *possibleThisCall = dyn_cast_or_null<CXXThisExpr>(Utils::getFirstChildAtDepth(expr, 1));
    if (possibleThisCall)
        return;

    // llvm::errs() << "Expression: " << expr->getStmtClassName() << "\n";

    std::string error = std::string("Don't call ") + StringUtils::qualifiedMethodName(methodDecl) + std::string("() on temporary");
    emitWarning(stm->getLocStart(), error.c_str());
}

REGISTER_CHECK("temporary-iterator", TemporaryIterator)