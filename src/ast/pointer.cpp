#include "../../include/ceetah/ast/pointer.hpp"
#include "../../include/ceetah/ast/dereference.hpp"

Ceetah::AST::NodeType Ceetah::AST::Pointer::nodeType() const {
  return NodeType::Pointer;
};

std::string Ceetah::AST::Pointer::toStringWithIndent(std::string indent) const {
  auto result = "(&(" + target->toStringWithIndent(indent) + "))";

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

bool Ceetah::AST::Pointer::operator ==(const Ceetah::AST::Pointer& other) const {
  return *target == *other.target;
};

std::shared_ptr<Ceetah::AST::Node> Ceetah::AST::Pointer::clone() const {
  auto node = std::make_shared<Ceetah::AST::Pointer>();
  cloneTo(node);
  return node;
};

void Ceetah::AST::Pointer::cloneTo(std::shared_ptr<Node> _node) const {
  auto node = std::dynamic_pointer_cast<Ceetah::AST::Pointer>(_node);
  Expression::cloneTo(node);
  CEETAH_AST_CLONE_CHILD(target);
};
