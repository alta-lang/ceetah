#include "../../include/ceetah/ast/type-definition.hpp"

const Ceetah::AST::NodeType Ceetah::AST::TypeDefinition::nodeType() {
  return NodeType::TypeDefinition;
};

std::string Ceetah::AST::TypeDefinition::toString() {
  std::string result;

  if (type->isFunction) {
    result = "typedef " + type->returnType->toString() + " (*" + name + ")(";
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
  } else {
    result = "typedef " + type->toString() + ' ' + name + ";";
  }

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

bool Ceetah::AST::TypeDefinition::operator ==(const Ceetah::AST::TypeDefinition& other) {
  if (name != other.name) return false;
  return *type == *other.type;
};
