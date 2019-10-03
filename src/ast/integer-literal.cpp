#include "../../include/ceetah/ast/integer-literal.hpp"

const Ceetah::AST::NodeType Ceetah::AST::IntegerLiteral::nodeType() {
  return NodeType::IntegerLiteral;
};

std::string Ceetah::AST::IntegerLiteral::toString() {
  auto result = raw;

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

bool Ceetah::AST::IntegerLiteral::operator ==(const Ceetah::AST::IntegerLiteral& other) {
  return raw == other.raw;
};
