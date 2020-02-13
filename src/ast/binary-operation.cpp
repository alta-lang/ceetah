#include "../../include/ceetah/ast/binary-operation.hpp"

Ceetah::AST::NodeType Ceetah::AST::BinaryOperation::nodeType() const {
  return NodeType::BinaryOperation;
};

std::string Ceetah::AST::BinaryOperation::toString() const {
  auto result = "((" + left->toString() + ") " + OperatorType_operators[(uint8_t)type];

  if (newlineOnExpressions) result += '\n';

  result += " (" + right->toString() + "))";

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

bool Ceetah::AST::BinaryOperation::operator ==(const Ceetah::AST::BinaryOperation& other) const {
  if (type != other.type) return false;
  if (*left != *other.left) return false;
  return *right == *other.right;
};

std::shared_ptr<Ceetah::AST::Node> Ceetah::AST::BinaryOperation::clone() const {
  auto node = std::make_shared<Ceetah::AST::BinaryOperation>();
  cloneTo(node);
  return node;
};

void Ceetah::AST::BinaryOperation::cloneTo(std::shared_ptr<Node> _node) const {
  auto node = std::dynamic_pointer_cast<Ceetah::AST::BinaryOperation>(_node);
  Expression::cloneTo(node);
  node->type = type;
  CEETAH_AST_CLONE_CHILD(left);
  CEETAH_AST_CLONE_CHILD(right);
};
