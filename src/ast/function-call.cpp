#include "../../include/ceetah/ast/function-call.hpp"

const Ceetah::AST::NodeType Ceetah::AST::FunctionCall::nodeType() {
  return NodeType::FunctionCall;
};

std::string Ceetah::AST::FunctionCall::toString() {
  auto result = target->toString();
  if (!macro) {
    result = '(' + result;
    result += ')';
  }
  result += '(';
  bool isFirst = true;
  for (auto& arg: arguments) {
    if (newlineOnExpressions) result += '\n';
    if (isFirst) {
      isFirst = false;
    } else {
      result += ", ";
    }
    result += arg->toString();
  }
  if (newlineOnExpressions) result += '\n';
  result += ')';

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

bool Ceetah::AST::FunctionCall::operator ==(const Ceetah::AST::FunctionCall& other) {
  if (arguments.size() != other.arguments.size()) {
    return false;
  }
  if (*target != *other.target) return false;
  for (size_t i = 0; i < arguments.size(); i++) {
    if (*arguments[i] != *other.arguments[i]) {
      return false;
    }
  }
  if (macro != other.macro) return false;
  return true;
};
