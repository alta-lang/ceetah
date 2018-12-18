#include "../../include/ceetah/ast/ternary-operation.hpp"

const Ceetah::AST::NodeType Ceetah::AST::TernaryOperation::nodeType() {
  return NodeType::TernaryOperation;
};

std::string Ceetah::AST::TernaryOperation::toString() {
  return "((" + test->toString() + ") ? (" + primary->toString() + ") : (" + secondary->toString() + "))";
};

bool Ceetah::AST::TernaryOperation::operator ==(const Ceetah::AST::TernaryOperation& other) {
  if (*test != *other.test) return false;
  if (*primary != *other.primary) return false;
  return *secondary == *other.secondary;
};
