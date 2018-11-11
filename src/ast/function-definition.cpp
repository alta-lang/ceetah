#include "../../include/ceetah/ast/function-definition.hpp"

const Ceetah::AST::NodeType Ceetah::AST::FunctionDefinition::nodeType() {
  return NodeType::FunctionDefinition;
};

std::string Ceetah::AST::FunctionDefinition::toString() {
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

  result += ") {";
  if (body.size() > 0) {
    result += '\n';
    for (auto& stmt: body) {
      result += stmt->toString();
      result += '\n';
    }
  }
  result += "};";

  return result;
};

bool Ceetah::AST::FunctionDefinition::operator ==(const Ceetah::AST::FunctionDefinition& other) {
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

  if (other.body.size() != body.size()) return false;
  for (size_t i = 0; i < body.size(); i++) {
    auto& stmt = body[i];
    auto& otherStmt = other.body[i];
    
    if (*stmt != *otherStmt) {
      return false;
    }
  }

  return true;
};