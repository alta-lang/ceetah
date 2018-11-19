#include "../../include/ceetah/ast/type-definition.hpp"

const Ceetah::AST::NodeType Ceetah::AST::TypeDefinition::nodeType() {
  return NodeType::TypeDefinition;
};

std::string Ceetah::AST::TypeDefinition::toString() {
  if (type->isFunction) {
    std::string result = "typedef " + type->returnType->toString() + " (*" + name + ")(";
    bool isFirst = true;
    for (auto& param: type->parameters) {
      if (isFirst) {
        isFirst = false;
      } else {
        result += ", ";
      }
      result += param->toString();
    }
    result += ");";
    return result;
  } else {
    return "typedef " + type->toString() + ' ' + name + ";";
  }
};

bool Ceetah::AST::TypeDefinition::operator ==(const Ceetah::AST::TypeDefinition& other) {
  if (name != other.name) return false;
  return *type == *other.type;
};
