#include "../../include/ceetah/ast/function-declaration.hpp"

const Ceetah::AST::NodeType Ceetah::AST::FunctionDeclaration::nodeType() {
  return NodeType::FunctionDeclaration;
};

std::string Ceetah::AST::FunctionDeclaration::toString() {
  std::string result;

  result += returnType->toString();
  result += ' ';
  result += name;
  result += '(';

  bool isFirst = true;
  for (auto& [name, type]: parameters) {
    if (isFirst) {
      isFirst = false;
    } else {
      result += ", ";
    }
    result += type->toString();
    result += ' ';
    result += name;
  }

  result += ");";

  return result;
};

bool Ceetah::AST::FunctionDeclaration::operator ==(const Ceetah::AST::FunctionDeclaration& other) {
  if (other.name != name) return false;
  if (other.parameters.size() != parameters.size()) return false;
  bool match = true;
  for (size_t i = 0; i < parameters.size(); i++) {
    auto& param = parameters[i];
    auto& otherParam = other.parameters[i];
    auto& [paramName, paramType] = param;
    auto& [otherParamName, otherParamType] = otherParam;

    if (paramName != otherParamName) {
      match = false;
      break;
    }
    if (*paramType != *otherParamType) {
      match = false;
      break;
    }
  }
  if (!match) return false;
  if (*returnType != *other.returnType) return false;
  return true;
};
