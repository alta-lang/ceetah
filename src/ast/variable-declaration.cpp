#include "../../include/ceetah/ast/variable-declaration.hpp"

const Ceetah::AST::NodeType Ceetah::AST::VariableDeclaration::nodeType() {
  return NodeType::VariableDeclaration;
};

std::string Ceetah::AST::VariableDeclaration::toString() {
  return "extern " + type->toString() + " " + name + ";";
};

bool Ceetah::AST::VariableDeclaration::operator ==(const Ceetah::AST::VariableDeclaration& other) {
  if (name != other.name) return false;
  return *type == *other.type;
};
