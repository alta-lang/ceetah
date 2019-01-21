#include "../../include/ceetah/ast/while-loop.hpp"

const Ceetah::AST::NodeType Ceetah::AST::WhileLoop::nodeType() {
  return NodeType::WhileLoop;
};

std::string Ceetah::AST::WhileLoop::toString() {
  return "while (" + test->toString() + ") " + body->toString() + ";";
};

bool Ceetah::AST::WhileLoop::operator ==(const Ceetah::AST::WhileLoop& other) {
  if (*test != *other.test) return false;
  if (*body != *other.body) return false;
  return true;
};
