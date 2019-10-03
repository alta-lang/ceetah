#include "../../include/ceetah/ast/return-directive.hpp"

const Ceetah::AST::NodeType Ceetah::AST::ReturnDirective::nodeType() {
  return NodeType::ReturnDirective;
};

std::string Ceetah::AST::ReturnDirective::toString() {
  std::string result;

  if (value != nullptr) {
    result = "return " + value->toString() + ";";
  } else {
    result = "return;";
  }

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

bool Ceetah::AST::ReturnDirective::operator ==(const Ceetah::AST::ReturnDirective& other) {
  if ((other.value == nullptr) != (value == nullptr)) {
    return false;
  }
  // we only have to test one now, since we already confirmed that
  // they're either both nullptr or both non-nullptr
  if (value != nullptr) {
    return *value == *other.value;
  }
  return true;
};
