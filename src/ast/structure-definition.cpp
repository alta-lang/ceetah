#include "../../include/ceetah/ast/structure-definition.hpp"

const Ceetah::AST::NodeType Ceetah::AST::StructureDefinition::nodeType() {
  return NodeType::StructureDefinition;
};

std::string Ceetah::AST::StructureDefinition::toString() {
  std::string result = "struct " + name + " {";

  for (auto [name, type]: members) {
    result += '\n';
    result += type->toString() + " " + name + ";";
  }

  if (members.size() > 0) {
    result += '\n';
  }

  result += "};";

  return result;
};

bool Ceetah::AST::StructureDefinition::operator ==(const Ceetah::AST::StructureDefinition& other) {
  if (name != other.name) return false;

  if (members.size() != other.members.size()) return false;
  for (size_t i = 0; i < members.size(); i++) {
    if (members[i].first != other.members[i].first) return false;
    if (*members[i].second != *other.members[i].second) return false;
  }

  return true;
};
