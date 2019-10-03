#include "../../include/ceetah/ast/character-literal.hpp"

const Ceetah::AST::NodeType Ceetah::AST::CharacterLiteral::nodeType() {
  return NodeType::CharacterLiteral;
};

std::string Ceetah::AST::CharacterLiteral::toString() {
  std::string result;
  result += '\'';
  if (escaped) result += '\\';
  result += value;
  result += '\'';

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

bool Ceetah::AST::CharacterLiteral::operator ==(const Ceetah::AST::CharacterLiteral& other) {
  if (value != other.value) return false;
  return escaped == other.escaped;
};
