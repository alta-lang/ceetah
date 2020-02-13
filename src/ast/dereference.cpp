#include "../../include/ceetah/ast/dereference.hpp"

Ceetah::AST::NodeType Ceetah::AST::Dereference::nodeType() const {
  return NodeType::Dereference;
};

std::string Ceetah::AST::Dereference::toString() const {
  auto result = "(*(" + target->toString() + "))";

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

bool Ceetah::AST::Dereference::operator ==(const Ceetah::AST::Dereference& other) const {
  return *target == *other.target;
};

std::shared_ptr<Ceetah::AST::Node> Ceetah::AST::Dereference::clone() const {
  auto node = std::make_shared<Ceetah::AST::Dereference>();
  cloneTo(node);
  return node;
};

void Ceetah::AST::Dereference::cloneTo(std::shared_ptr<Node> _node) const {
  auto node = std::dynamic_pointer_cast<Ceetah::AST::Dereference>(_node);
  Expression::cloneTo(node);
  CEETAH_AST_CLONE_CHILD(target);
};
