#include "../../include/ceetah/ast/fetch.hpp"

Ceetah::AST::NodeType Ceetah::AST::Fetch::nodeType() const {
  return NodeType::Fetch;
};

std::string Ceetah::AST::Fetch::toString() const {
  auto result = query;

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

bool Ceetah::AST::Fetch::operator ==(const Ceetah::AST::Fetch& other) const {
  return query == other.query;
};

std::shared_ptr<Ceetah::AST::Node> Ceetah::AST::Fetch::clone() const {
  auto node = std::make_shared<Ceetah::AST::Fetch>();
  cloneTo(node);
  return node;
};

void Ceetah::AST::Fetch::cloneTo(std::shared_ptr<Node> _node) const {
  auto node = std::dynamic_pointer_cast<Ceetah::AST::Fetch>(_node);
  Expression::cloneTo(node);
  node->query = query;
};
