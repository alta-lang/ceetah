#include "../../include/ceetah/ast/while-loop.hpp"

const Ceetah::AST::NodeType Ceetah::AST::WhileLoop::nodeType() {
  return NodeType::WhileLoop;
};

std::string Ceetah::AST::WhileLoop::toString() {
  auto result = "while (" + test->toString() + ") ";
  if (newlineOnExpressions) result += '\n';
  result += body->toString() + ";";

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

bool Ceetah::AST::WhileLoop::operator ==(const Ceetah::AST::WhileLoop& other) {
  if (*test != *other.test) return false;
  if (*body != *other.body) return false;
  return true;
};
