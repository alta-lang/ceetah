#include "../../include/ceetah/ast/cast.hpp"

Ceetah::AST::NodeType Ceetah::AST::Cast::nodeType() const {
  return NodeType::Cast;
};

std::string Ceetah::AST::Cast::toString() const {
  auto result = "((" + type->toString() + ')' + target->toString() + ')';

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

bool Ceetah::AST::Cast::operator ==(const Ceetah::AST::Cast& other) const {
  if (*type != *other.type) return false;
  if (*target != *other.target) return false;
  return true;
};

std::shared_ptr<Ceetah::AST::Node> Ceetah::AST::Cast::clone() const {
  auto node = std::make_shared<Ceetah::AST::Cast>();
  cloneTo(node);
  return node;
};

void Ceetah::AST::Cast::cloneTo(std::shared_ptr<Node> _node) const {
  auto node = std::dynamic_pointer_cast<Ceetah::AST::Cast>(_node);
  Expression::cloneTo(node);
  CEETAH_AST_CLONE_CHILD(target);
  CEETAH_AST_CLONE_CHILD(type);
};
