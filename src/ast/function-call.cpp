#include "../../include/ceetah/ast/function-call.hpp"

const Ceetah::AST::NodeType Ceetah::AST::FunctionCall::nodeType() {
  return NodeType::FunctionCall;
};

std::string Ceetah::AST::FunctionCall::toString() {
  std::string result = '(' + target->toString() + ")(";
  bool isFirst = true;
  for (auto& arg: arguments) {
    if (isFirst) {
      isFirst = false;
    } else {
      result += ", ";
    }
    result += arg->toString();
  }
  result += ')';
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
  return true;
};
