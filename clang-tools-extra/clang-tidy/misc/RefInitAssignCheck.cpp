//===--- RefInitAssignCheck.cpp - clang-tidy ------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "RefInitAssignCheck.h"
#include "clang/AST/ASTContext.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"

using namespace clang::ast_matchers;

namespace clang {
namespace tidy {
namespace misc {

void RefInitAssignCheck::registerMatchers(MatchFinder *Finder) {
  Finder->addMatcher(
      binaryOperator(
          isAssignmentOperator(),
          hasLHS(declRefExpr(to(varDecl(hasType(lValueReferenceType()),
                                        hasInitializer(declRefExpr()))))))
          .bind("ref_init_assign"),
      this);
}

void RefInitAssignCheck::check(const MatchFinder::MatchResult &Result) {
  const BinaryOperator *RefInitAssign =
      Result.Nodes.getNodeAs<BinaryOperator>("ref_init_assign");

  if (RefInitAssign) {
    diag(RefInitAssign->getBeginLoc(),
         "reference type variable '%0' is assigned after initialization")
        << RefInitAssign->getLHS();
  }

  return;
}

} // namespace misc
} // namespace tidy
} // namespace clang
