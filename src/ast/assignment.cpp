#include "../../include/ceetah/ast/assignment.hpp"

const Ceetah::AST::NodeType Ceetah::AST::Assignment::nodeType() {
  return NodeType::Assignment;
};

std::string Ceetah::AST::Assignment::toString() {
  return "((" + target->toString() + ") " + AssignmentType_operators[(uint8_t)type] + " (" + value->toString() + "))";
};

bool Ceetah::AST::Assignment::operator ==(const Ceetah::AST::Assignment& other) {
  if (*target != *other.target) return false;
  return *value == *other.value;
};
