#include "../../include/ceetah/ast/statement.hpp"

Ceetah::AST::NodeType Ceetah::AST::Statement::nodeType() const {
  return NodeType::Statement;
};

std::shared_ptr<Ceetah::AST::Node> Ceetah::AST::Statement::clone() const {
  auto node = std::make_shared<Ceetah::AST::Statement>();
  cloneTo(node);
  return node;
};

void Ceetah::AST::Statement::cloneTo(std::shared_ptr<Node> _node) const {
  auto node = std::dynamic_pointer_cast<Ceetah::AST::Statement>(_node);
};
