#include "../../include/ceetah/ast/dereference.hpp"

const Ceetah::AST::NodeType Ceetah::AST::Dereference::nodeType() {
  return NodeType::Dereference;
};

std::string Ceetah::AST::Dereference::toString() {
  auto result = "(*(" + target->toString() + "))";

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

bool Ceetah::AST::Dereference::operator ==(const Ceetah::AST::Dereference& other) {
  return *target == *other.target;
};
