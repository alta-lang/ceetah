#include "../../include/ceetah/ast/integer-literal.hpp"

Ceetah::AST::NodeType Ceetah::AST::IntegerLiteral::nodeType() const {
  return NodeType::IntegerLiteral;
};

std::string Ceetah::AST::IntegerLiteral::toString() const {
  auto result = raw;

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

bool Ceetah::AST::IntegerLiteral::operator ==(const Ceetah::AST::IntegerLiteral& other) const {
  return raw == other.raw;
};

std::shared_ptr<Ceetah::AST::Node> Ceetah::AST::IntegerLiteral::clone() const {
  auto node = std::make_shared<Ceetah::AST::IntegerLiteral>();
  cloneTo(node);
  return node;
};

void Ceetah::AST::IntegerLiteral::cloneTo(std::shared_ptr<Node> _node) const {
  auto node = std::dynamic_pointer_cast<Ceetah::AST::IntegerLiteral>(_node);
  Expression::cloneTo(node);
  node->raw = raw;
};
