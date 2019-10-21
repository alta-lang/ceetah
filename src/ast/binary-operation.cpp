#include "../../include/ceetah/ast/binary-operation.hpp"

const Ceetah::AST::NodeType Ceetah::AST::BinaryOperation::nodeType() {
  return NodeType::BinaryOperation;
};

std::string Ceetah::AST::BinaryOperation::toString() {
  auto result = "((" + left->toString() + ") " + OperatorType_operators[(uint8_t)type];

  if (newlineOnExpressions) result += '\n';

  result += " (" + right->toString() + "))";

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

bool Ceetah::AST::BinaryOperation::operator ==(const Ceetah::AST::BinaryOperation& other) {
  if (type != other.type) return false;
  if (*left != *other.left) return false;
  return *right == *other.right;
};
