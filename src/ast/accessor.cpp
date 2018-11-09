#include "../include/ceetah/ast/accessor.hpp"

const Ceetah::AST::NodeType Ceetah::AST::Accessor::nodeType() {
  return NodeType::Accessor;
};

std::string Ceetah::AST::Accessor::toString() {
  return target->toString() + '.' + query;
};

Ceetah::AST::Accessor* Ceetah::AST::Accessor::access(std::string subquery) {
  auto newAcc = new Accessor();
  newAcc->target = this;
  newAcc->query = subquery;
  return newAcc;
};

bool Ceetah::AST::Accessor::operator ==(const Ceetah::AST::Accessor& other) {
  if (*target != *other.target) return false;
  return query == other.query;
};