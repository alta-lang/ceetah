#include "../../include/ceetah/ast/fetch.hpp"

const Ceetah::AST::NodeType Ceetah::AST::Fetch::nodeType() {
  return NodeType::Fetch;
};

std::string Ceetah::AST::Fetch::toString() {
  return query;
};

bool Ceetah::AST::Fetch::operator ==(const Ceetah::AST::Fetch& other) {
  return query == other.query;
};