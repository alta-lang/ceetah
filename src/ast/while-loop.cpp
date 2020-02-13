#include "../../include/ceetah/ast/while-loop.hpp"

Ceetah::AST::NodeType Ceetah::AST::WhileLoop::nodeType() const {
  return NodeType::WhileLoop;
};

std::string Ceetah::AST::WhileLoop::toString() const {
  auto result = "while (" + test->toString() + ") ";
  if (newlineOnExpressions) result += '\n';
  result += body->toString() + ";";

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

bool Ceetah::AST::WhileLoop::operator ==(const Ceetah::AST::WhileLoop& other) const {
  if (*test != *other.test) return false;
  if (*body != *other.body) return false;
  return true;
};

std::shared_ptr<Ceetah::AST::Node> Ceetah::AST::WhileLoop::clone() const {
  auto node = std::make_shared<Ceetah::AST::WhileLoop>();
  cloneTo(node);
  return node;
};

void Ceetah::AST::WhileLoop::cloneTo(std::shared_ptr<Node> _node) const {
  auto node = std::dynamic_pointer_cast<Ceetah::AST::WhileLoop>(_node);
  Statement::cloneTo(node);
  CEETAH_AST_CLONE_CHILD(test);
  CEETAH_AST_CLONE_CHILD(body);
};
