#include "../../include/ceetah/ast/cast.hpp"

const Ceetah::AST::NodeType Ceetah::AST::Cast::nodeType() {
  return NodeType::Cast;
};

std::string Ceetah::AST::Cast::toString() {
  return "((" + type->toString() + ')' + target->toString() + ')';
};

bool Ceetah::AST::Cast::operator ==(const Ceetah::AST::Cast& other) {
  if (*type != *other.type) return false;
  if (*target != *other.target) return false;
  return true;
};
