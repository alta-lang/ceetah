#include "../../include/ceetah/ast/expression.hpp"

Ceetah::AST::NodeType Ceetah::AST::Expression::nodeType() const {
  return NodeType::Expression;
};

std::shared_ptr<Ceetah::AST::Node> Ceetah::AST::Expression::clone() const {
  auto node = std::make_shared<Ceetah::AST::Expression>();
  cloneTo(node);
  return node;
};

void Ceetah::AST::Expression::cloneTo(std::shared_ptr<Node> _node) const {
  auto node = std::dynamic_pointer_cast<Ceetah::AST::Expression>(_node);
  Node::cloneTo(node);
};
