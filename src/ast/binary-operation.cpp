#include "../../include/ceetah/ast/binary-operation.hpp"

const Ceetah::AST::NodeType Ceetah::AST::BinaryOperation::nodeType() {
  return NodeType::BinaryOperation;
};

std::string Ceetah::AST::BinaryOperation::toString() {
  return '(' + left->toString() + ") " + OperatorType_operators[(uint8_t)type] + " (" + right->toString() + ')';
};

bool Ceetah::AST::BinaryOperation::operator ==(const Ceetah::AST::BinaryOperation& other) {
  if (type != other.type) return false;
  if (*left != *other.left) return false;
  return *right == *other.right;
};
