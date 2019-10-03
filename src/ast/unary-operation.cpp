#include "../../include/ceetah/ast/unary-operation.hpp"

const Ceetah::AST::NodeType Ceetah::AST::UnaryOperation::nodeType() {
  return NodeType::UnaryOperation;
};

std::string Ceetah::AST::UnaryOperation::toString() {
  std::string result;

  if (post) {
    result = "((" + target->toString() + ')' + UOperatorType_operators[(uint8_t)type] + ')';
  } else {
    result = std::string("(") + UOperatorType_operators[(uint8_t)type] + '(' + target->toString() + "))";
  }

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

bool Ceetah::AST::UnaryOperation::operator ==(const Ceetah::AST::UnaryOperation& other) {
  if (type != other.type) return false;
  return *target == *other.target;
};
