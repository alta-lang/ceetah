#include "../../include/ceetah/ast/accessor.hpp"

Ceetah::AST::NodeType Ceetah::AST::Accessor::nodeType() const {
  return NodeType::Accessor;
};

std::string Ceetah::AST::Accessor::toStringWithIndent(std::string indent) const {
  auto result = target->toStringWithIndent(indent) + '.' + query;

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

std::shared_ptr<Ceetah::AST::Accessor> Ceetah::AST::Accessor::access(std::string subquery) {
  auto newAcc = std::make_shared<Accessor>();
  newAcc->target = std::make_shared<Accessor>(*this);
  newAcc->query = subquery;
  return newAcc;
};

bool Ceetah::AST::Accessor::operator ==(const Ceetah::AST::Accessor& other) const {
  if (*target != *other.target) return false;
  return query == other.query;
};

std::shared_ptr<Ceetah::AST::Node> Ceetah::AST::Accessor::clone() const {
  auto node = std::make_shared<Ceetah::AST::Accessor>();
  cloneTo(node);
  return node;
};

void Ceetah::AST::Accessor::cloneTo(std::shared_ptr<Node> _node) const {
  auto node = std::dynamic_pointer_cast<Ceetah::AST::Accessor>(_node);
  Expression::cloneTo(node);
  CEETAH_AST_CLONE_CHILD(target);
  node->query = query;
};
