#include "../../include/ceetah/ast/pointer.hpp"
#include "../../include/ceetah/ast/dereference.hpp"

const Ceetah::AST::NodeType Ceetah::AST::Pointer::nodeType() {
  return NodeType::Pointer;
};

std::string Ceetah::AST::Pointer::toString() {
  auto result = "(&(" + target->toString() + "))";

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

bool Ceetah::AST::Pointer::operator ==(const Ceetah::AST::Pointer& other) {
  return *target == *other.target;
};
