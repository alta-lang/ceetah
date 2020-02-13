#include "../../include/ceetah/ast/preprocessor-directive.hpp"

Ceetah::AST::NodeType Ceetah::AST::PreprocessorDirective::nodeType() const {
  return NodeType::PreprocessorDirective;
};

std::shared_ptr<Ceetah::AST::Node> Ceetah::AST::PreprocessorDirective::clone() const {
  auto node = std::make_shared<Ceetah::AST::PreprocessorDirective>();
  cloneTo(node);
  return node;
};

void Ceetah::AST::PreprocessorDirective::cloneTo(std::shared_ptr<Node> _node) const {
  auto node = std::dynamic_pointer_cast<Ceetah::AST::PreprocessorDirective>(_node);
  Statement::cloneTo(node);
};
