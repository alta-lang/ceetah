#include "../include/ceetah/ast/return-directive.hpp"

const Ceetah::AST::NodeType Ceetah::AST::ReturnDirective::nodeType() {
  return NodeType::ReturnDirective;
};

std::string Ceetah::AST::ReturnDirective::toString() {
  if (value != nullptr) {
    return "return " + value->toString() + ";";
  } else {
    return "return;";
  }
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