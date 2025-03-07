/*
    SPDX-FileCopyrightText: 2015 Sergio Martins <smartins@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "isempty-vs-count.h"
#include "QtUtils.h"
#include "StringUtils.h"

#include <clang/AST/DeclCXX.h>
#include <clang/AST/Expr.h>
#include <clang/AST/ExprCXX.h>
#include <clang/AST/OperationKinds.h>
#include <clang/AST/Stmt.h>
#include <clang/AST/StmtIterator.h>
#include <clang/Basic/LLVM.h>
#include <llvm/ADT/StringRef.h>
#include <llvm/Support/Casting.h>

using namespace clang;

IsEmptyVSCount::IsEmptyVSCount(const std::string &name, ClazyContext *context)
    : CheckBase(name, context, Option_CanIgnoreIncludes)
{
}

void IsEmptyVSCount::VisitStmt(clang::Stmt *stmt)
{
    auto *cast = dyn_cast<ImplicitCastExpr>(stmt);
    if (!cast || cast->getCastKind() != clang::CK_IntegralToBoolean) {
        return;
    }

    auto *memberCall = dyn_cast<CXXMemberCallExpr>(*(cast->child_begin()));
    CXXMethodDecl *method = memberCall ? memberCall->getMethodDecl() : nullptr;

    if (!clazy::functionIsOneOf(method, {"size", "count", "length"})) {
        return;
    }

    if (!clazy::classIsOneOf(method->getParent(), clazy::qtContainers())) {
        return;
    }

    if (clazy::classIsOneOf(method->getParent(), {"QMultiHash", "QMultiMap"}) && memberCall->getNumArgs() == 2) {
        emitWarning(stmt->getBeginLoc(), "use contains() instead");
        return;
    }

    if (clazy::classIsOneOf(method->getParent(), {"QHash", "QMap", "QMultiHash", "QMultiMap"}) && memberCall->getNumArgs() == 1) {
        emitWarning(stmt->getBeginLoc(), "use contains() instead");
        return;
    }

    emitWarning(stmt->getBeginLoc(), "use isEmpty() instead");
}
