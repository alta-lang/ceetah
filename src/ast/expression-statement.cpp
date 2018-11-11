#include "../../include/ceetah/ast/expression-statement.hpp"

const Ceetah::AST::NodeType Ceetah::AST::ExpressionStatement::nodeType() {
  return NodeType::ExpressionStatement;
};

std::string Ceetah::AST::ExpressionStatement::toString() {
  return expression->toString() + ";";
};

bool Ceetah::AST::ExpressionStatement::operator ==(const Ceetah::AST::ExpressionStatement& other) {
  return *expression == *other.expression;
};