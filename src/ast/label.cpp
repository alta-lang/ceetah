#include "../../include/ceetah/ast/label.hpp"

Ceetah::AST::NodeType Ceetah::AST::Label::nodeType() const {
  return NodeType::Label;
};

std::string Ceetah::AST::Label::toStringWithIndent(std::string indent) const {
  std::string result = label + ':';

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

bool Ceetah::AST::Label::operator ==(const Ceetah::AST::Label& other) const {
  return label == other.label;
};

std::shared_ptr<Ceetah::AST::Node> Ceetah::AST::Label::clone() const {
  auto node = std::make_shared<Ceetah::AST::Label>();
  cloneTo(node);
  return node;
};

void Ceetah::AST::Label::cloneTo(std::shared_ptr<Node> _node) const {
  auto node = std::dynamic_pointer_cast<Ceetah::AST::Label>(_node);
  Statement::cloneTo(node);
  node->label = label;
};
