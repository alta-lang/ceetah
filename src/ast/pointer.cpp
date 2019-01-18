#include "../../include/ceetah/ast/pointer.hpp"
#include "../../include/ceetah/ast/dereference.hpp"

const Ceetah::AST::NodeType Ceetah::AST::Pointer::nodeType() {
  return NodeType::Pointer;
};

std::string Ceetah::AST::Pointer::toString() {
  return "(&(" + target->toString() + "))";
};

bool Ceetah::AST::Pointer::operator ==(const Ceetah::AST::Pointer& other) {
  return *target == *other.target;
};
