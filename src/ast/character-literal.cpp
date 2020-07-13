#include "../../include/ceetah/ast/character-literal.hpp"

Ceetah::AST::NodeType Ceetah::AST::CharacterLiteral::nodeType() const {
  return NodeType::CharacterLiteral;
};

std::string Ceetah::AST::CharacterLiteral::toStringWithIndent(std::string indent) const {
  std::string result;
  result += '\'';
  if (escaped) result += '\\';
  result += value;
  result += '\'';

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

bool Ceetah::AST::CharacterLiteral::operator ==(const Ceetah::AST::CharacterLiteral& other) const {
  if (value != other.value) return false;
  return escaped == other.escaped;
};

std::shared_ptr<Ceetah::AST::Node> Ceetah::AST::CharacterLiteral::clone() const {
  auto node = std::make_shared<Ceetah::AST::CharacterLiteral>();
  cloneTo(node);
  return node;
};

void Ceetah::AST::CharacterLiteral::cloneTo(std::shared_ptr<Node> _node) const {
  auto node = std::dynamic_pointer_cast<Ceetah::AST::CharacterLiteral>(_node);
  Expression::cloneTo(node);
  node->value = value;
  node->escaped = escaped;
};
