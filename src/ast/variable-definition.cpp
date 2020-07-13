#include "../../include/ceetah/ast/variable-definition.hpp"

Ceetah::AST::NodeType Ceetah::AST::VariableDefinition::nodeType() const {
  return NodeType::VariableDefinition;
};

std::string Ceetah::AST::VariableDefinition::toStringWithIndent(std::string indent) const {
  auto result = type->toStringWithIndent(indent) + " " + name;

  if (initializationExpression != nullptr) {
    result += " = " + initializationExpression->toStringWithIndent(indent);
  }

  result += ';';

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

bool Ceetah::AST::VariableDefinition::operator ==(const Ceetah::AST::VariableDefinition& other) const {
  if (name != other.name) return false;
  if (*type != *other.type) return false;
  return *initializationExpression == *other.initializationExpression;
};

std::shared_ptr<Ceetah::AST::Node> Ceetah::AST::VariableDefinition::clone() const {
  auto node = std::make_shared<Ceetah::AST::VariableDefinition>();
  cloneTo(node);
  return node;
};

void Ceetah::AST::VariableDefinition::cloneTo(std::shared_ptr<Node> _node) const {
  auto node = std::dynamic_pointer_cast<Ceetah::AST::VariableDefinition>(_node);
  Statement::cloneTo(node);
  node->name = name;
  CEETAH_AST_CLONE_CHILD(type);
  CEETAH_AST_CLONE_CHILD(initializationExpression);
};
