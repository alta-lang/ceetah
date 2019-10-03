#include "../../include/ceetah/ast/expression-statement.hpp"

const Ceetah::AST::NodeType Ceetah::AST::ExpressionStatement::nodeType() {
  return NodeType::ExpressionStatement;
};

std::string Ceetah::AST::ExpressionStatement::toString() {
  auto result = expression->toString() + ";";

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

bool Ceetah::AST::ExpressionStatement::operator ==(const Ceetah::AST::ExpressionStatement& other) {
  return *expression == *other.expression;
};
