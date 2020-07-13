#include "../../include/ceetah/ast/goto-directive.hpp"

Ceetah::AST::NodeType Ceetah::AST::GotoDirective::nodeType() const {
  return NodeType::GotoDirective;
};

std::string Ceetah::AST::GotoDirective::toStringWithIndent(std::string indent) const {
  std::string result = "goto " + label + ';';

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

bool Ceetah::AST::GotoDirective::operator ==(const Ceetah::AST::GotoDirective& other) const {
  return label == other.label;
};

std::shared_ptr<Ceetah::AST::Node> Ceetah::AST::GotoDirective::clone() const {
  auto node = std::make_shared<Ceetah::AST::GotoDirective>();
  cloneTo(node);
  return node;
};

void Ceetah::AST::GotoDirective::cloneTo(std::shared_ptr<Node> _node) const {
  auto node = std::dynamic_pointer_cast<Ceetah::AST::GotoDirective>(_node);
  Statement::cloneTo(node);
  node->label = label;
};
