#include "../../include/ceetah/ast/integer-literal.hpp"

const Ceetah::AST::NodeType Ceetah::AST::IntegerLiteral::nodeType() {
  return NodeType::IntegerLiteral;
};

std::string Ceetah::AST::IntegerLiteral::toString() {
  return raw;
};

bool Ceetah::AST::IntegerLiteral::operator ==(const Ceetah::AST::IntegerLiteral& other) {
  return raw == other.raw;
};