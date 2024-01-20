/*
    SPDX-FileCopyrightText: 2015 Klarälvdalens Datakonsult AB a KDAB Group company info@kdab.com
    SPDX-FileContributor: Sérgio Martins <sergio.martins@kdab.com>

    SPDX-FileCopyrightText: 2015 Sergio Martins <smartins@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "qdatetime-utc.h"
#include "FixItUtils.h"
#include "SourceCompatibilityHelpers.h"
#include "Utils.h"

#include <clang/AST/Decl.h>
#include <clang/AST/DeclCXX.h>
#include <clang/AST/Expr.h>
#include <clang/AST/ExprCXX.h>
#include <clang/AST/Stmt.h>
#include <clang/Basic/Diagnostic.h>
#include <clang/Basic/LLVM.h>
#include <llvm/Support/Casting.h>

#include <vector>

class ClazyContext;

using namespace clang;

QDateTimeUtc::QDateTimeUtc(const std::string &name, ClazyContext *context)
    : CheckBase(name, context)
{
}

void QDateTimeUtc::VisitStmt(clang::Stmt *stmt)
{
    auto *secondCall = dyn_cast<CXXMemberCallExpr>(stmt);
    if (!secondCall || !secondCall->getMethodDecl()) {
        return;
    }
    CXXMethodDecl *secondMethod = secondCall->getMethodDecl();
    const std::string secondMethodName = secondMethod->getQualifiedNameAsString();
    const bool isTimeT = secondMethodName == "QDateTime::toTime_t";
    const bool isMsecSinceEpoc = secondMethodName == "QDateTime::toMSecsSinceEpoch"; // Qt6 version and undeprecated of the above
    if (!(isTimeT || isMsecSinceEpoc) && secondMethodName != "QDateTime::toUTC") {
        return;
    }

    std::vector<CallExpr *> chainedCalls = Utils::callListForChain(secondCall);
    if (chainedCalls.size() < 2) {
        return;
    }

    CallExpr *firstCall = chainedCalls[chainedCalls.size() - 1];
    FunctionDecl *firstFunc = firstCall->getDirectCallee();
    if (!firstFunc) {
        return;
    }

    auto *firstMethod = dyn_cast<CXXMethodDecl>(firstFunc);
    if (!firstMethod || firstMethod->getQualifiedNameAsString() != "QDateTime::currentDateTime") {
        return;
    }

    std::string replacement = "::currentDateTimeUtc()";
    if (isTimeT || isMsecSinceEpoc) {
        replacement = "::currentMSecsSinceEpoch()";
    }

    std::vector<FixItHint> fixits;
    const bool success = clazy::transformTwoCallsIntoOneV2(&m_astContext, secondCall, replacement, fixits);
    if (!success) {
        queueManualFixitWarning(clazy::getLocStart(secondCall));
    }

    emitWarning(clazy::getLocStart(stmt), "Use QDateTime" + replacement + " instead. It is significantly faster", fixits);
}
