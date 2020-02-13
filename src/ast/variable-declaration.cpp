#include "../../include/ceetah/ast/variable-declaration.hpp"

Ceetah::AST::NodeType Ceetah::AST::VariableDeclaration::nodeType() const {
  return NodeType::VariableDeclaration;
};

std::string Ceetah::AST::VariableDeclaration::toString() const {
  auto result = "extern " + type->toString() + " " + name + ";";

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

bool Ceetah::AST::VariableDeclaration::operator ==(const Ceetah::AST::VariableDeclaration& other) const {
  if (name != other.name) return false;
  return *type == *other.type;
};

std::shared_ptr<Ceetah::AST::Node> Ceetah::AST::VariableDeclaration::clone() const {
  auto node = std::make_shared<Ceetah::AST::VariableDeclaration>();
  cloneTo(node);
  return node;
};

void Ceetah::AST::VariableDeclaration::cloneTo(std::shared_ptr<Node> _node) const {
  auto node = std::dynamic_pointer_cast<Ceetah::AST::VariableDeclaration>(_node);
  Statement::cloneTo(node);
  node->name = name;
  CEETAH_AST_CLONE_CHILD(type);
};
