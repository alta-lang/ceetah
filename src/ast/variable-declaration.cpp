#include "../../include/ceetah/ast/variable-declaration.hpp"

const Ceetah::AST::NodeType Ceetah::AST::VariableDeclaration::nodeType() {
  return NodeType::VariableDeclaration;
};

std::string Ceetah::AST::VariableDeclaration::toString() {
  auto result = "extern " + type->toString() + " " + name + ";";

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

bool Ceetah::AST::VariableDeclaration::operator ==(const Ceetah::AST::VariableDeclaration& other) {
  if (name != other.name) return false;
  return *type == *other.type;
};
