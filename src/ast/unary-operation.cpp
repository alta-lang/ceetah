#include "../../include/ceetah/ast/unary-operation.hpp"

const Ceetah::AST::NodeType Ceetah::AST::UnaryOperation::nodeType() {
  return NodeType::UnaryOperation;
};

std::string Ceetah::AST::UnaryOperation::toString() {
  if (post) {
    return "((" + target->toString() + ')' + UOperatorType_operators[(uint8_t)type] + ')';
  } else {
    return std::string("(") + UOperatorType_operators[(uint8_t)type] + '(' + target->toString() + "))";
  }
};

bool Ceetah::AST::UnaryOperation::operator ==(const Ceetah::AST::UnaryOperation& other) {
  if (type != other.type) return false;
  return *target == *other.target;
};
