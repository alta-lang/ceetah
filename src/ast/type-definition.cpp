#include "../../include/ceetah/ast/type-definition.hpp"

Ceetah::AST::NodeType Ceetah::AST::TypeDefinition::nodeType() const {
  return NodeType::TypeDefinition;
};

std::string Ceetah::AST::TypeDefinition::toString() const {
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

bool Ceetah::AST::TypeDefinition::operator ==(const Ceetah::AST::TypeDefinition& other) const {
  if (name != other.name) return false;
  return *type == *other.type;
};

std::shared_ptr<Ceetah::AST::Node> Ceetah::AST::TypeDefinition::clone() const {
  auto node = std::make_shared<Ceetah::AST::TypeDefinition>();
  cloneTo(node);
  return node;
};

void Ceetah::AST::TypeDefinition::cloneTo(std::shared_ptr<Node> _node) const {
  auto node = std::dynamic_pointer_cast<Ceetah::AST::TypeDefinition>(_node);
  Statement::cloneTo(node);
  node->name = name;
  CEETAH_AST_CLONE_CHILD(type);
};
