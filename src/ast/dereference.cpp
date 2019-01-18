#include "../../include/ceetah/ast/dereference.hpp"

const Ceetah::AST::NodeType Ceetah::AST::Dereference::nodeType() {
  return NodeType::Dereference;
};

std::string Ceetah::AST::Dereference::toString() {
  return "(*(" + target->toString() + "))";
};

bool Ceetah::AST::Dereference::operator ==(const Ceetah::AST::Dereference& other) {
  return *target == *other.target;
};
