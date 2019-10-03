#include "../../include/ceetah/ast/cast.hpp"

const Ceetah::AST::NodeType Ceetah::AST::Cast::nodeType() {
  return NodeType::Cast;
};

std::string Ceetah::AST::Cast::toString() {
  auto result = "((" + type->toString() + ')' + target->toString() + ')';

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

bool Ceetah::AST::Cast::operator ==(const Ceetah::AST::Cast& other) {
  if (*type != *other.type) return false;
  if (*target != *other.target) return false;
  return true;
};
