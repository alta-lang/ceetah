#include "../include/ceetah/ast/variable-definition.hpp"

const Ceetah::AST::NodeType Ceetah::AST::VariableDefinition::nodeType() {
  return NodeType::VariableDefinition;
};

std::string Ceetah::AST::VariableDefinition::toString() {
  auto result = type->toString() + " " + name;

  if (initializationExpression != nullptr) {
    result += " = " + initializationExpression->toString();
  }

  result += ';';

  return result;
};

bool Ceetah::AST::VariableDefinition::operator ==(const Ceetah::AST::VariableDefinition& other) {
  if (name != other.name) return false;
  if (*type != *other.type) return false;
  return *initializationExpression == *other.initializationExpression;
};