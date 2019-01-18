#include "../../include/ceetah/ast/sizeof.hpp"

const Ceetah::AST::NodeType Ceetah::AST::Sizeof::nodeType() {
  return NodeType::Sizeof;
};

std::string Ceetah::AST::Sizeof::toString() {
  return "sizeof(" + type->toString() + ")";
};

bool Ceetah::AST::Sizeof::operator ==(const Ceetah::AST::Sizeof& other) {
  if (*type != *other.type) return false;
  return true;
};
