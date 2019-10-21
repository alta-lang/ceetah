#include "../../include/ceetah/ast/ternary-operation.hpp"

const Ceetah::AST::NodeType Ceetah::AST::TernaryOperation::nodeType() {
  return NodeType::TernaryOperation;
};

std::string Ceetah::AST::TernaryOperation::toString() {
  auto result = "((" + test->toString() + ") ?";
  if (newlineOnExpressions) result += '\n';
  result += '(' + primary->toString() + ") : ";
  if (newlineOnExpressions) result += '\n';
  result += '(' + secondary->toString() + "))";

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

bool Ceetah::AST::TernaryOperation::operator ==(const Ceetah::AST::TernaryOperation& other) {
  if (*test != *other.test) return false;
  if (*primary != *other.primary) return false;
  return *secondary == *other.secondary;
};
