#include "../../include/ceetah/ast/sizeof.hpp"

Ceetah::AST::NodeType Ceetah::AST::Sizeof::nodeType() const {
  return NodeType::Sizeof;
};

std::string Ceetah::AST::Sizeof::toString() const {
  auto result = "sizeof(" + type->toString() + ")";

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

bool Ceetah::AST::Sizeof::operator ==(const Ceetah::AST::Sizeof& other) const {
  if (*type != *other.type) return false;
  return true;
};

std::shared_ptr<Ceetah::AST::Node> Ceetah::AST::Sizeof::clone() const {
  auto node = std::make_shared<Ceetah::AST::Sizeof>();
  cloneTo(node);
  return node;
};

void Ceetah::AST::Sizeof::cloneTo(std::shared_ptr<Node> _node) const {
  auto node = std::dynamic_pointer_cast<Ceetah::AST::Sizeof>(_node);
  Expression::cloneTo(node);
  CEETAH_AST_CLONE_CHILD(type);
};
