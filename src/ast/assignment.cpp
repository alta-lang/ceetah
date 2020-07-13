#include "../../include/ceetah/ast/assignment.hpp"

Ceetah::AST::NodeType Ceetah::AST::Assignment::nodeType() const {
  return NodeType::Assignment;
};

std::string Ceetah::AST::Assignment::toStringWithIndent(std::string indent) const {
  auto result = "((" + target->toStringWithIndent(indent) + ") " + AssignmentType_operators[(uint8_t)type];

  if (newlineOnExpressions) result += '\n' + indent + '\t';

  result += " (" + value->toStringWithIndent(indent + '\t') + "))";

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

bool Ceetah::AST::Assignment::operator ==(const Ceetah::AST::Assignment& other) const {
  if (*target != *other.target) return false;
  return *value == *other.value;
};

std::shared_ptr<Ceetah::AST::Node> Ceetah::AST::Assignment::clone() const {
  auto node = std::make_shared<Ceetah::AST::Assignment>();
  cloneTo(node);
  return node;
};

void Ceetah::AST::Assignment::cloneTo(std::shared_ptr<Node> _node) const {
  auto node = std::dynamic_pointer_cast<Ceetah::AST::Assignment>(_node);
  Expression::cloneTo(node);
  CEETAH_AST_CLONE_CHILD(target);
  CEETAH_AST_CLONE_CHILD(value);
  node->type = type;
};
