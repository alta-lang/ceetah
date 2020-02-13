#include "../../include/ceetah/ast/structure-definition.hpp"

Ceetah::AST::NodeType Ceetah::AST::StructureDefinition::nodeType() const {
  return NodeType::StructureDefinition;
};

std::string Ceetah::AST::StructureDefinition::toString() const {
  std::string result = "";

  if (packed) {
    result += "#ifdef __GNUC__\n";
    result += "#define CEETAH_PACKED_STRUCT __attribute__((__packed__))\n";
    result += "#else\n";
    result += "#define CEETAH_PACKED_STRUCT\n";
    result += "#pragma pack(push, 1)\n";
    result += "#endif // __GNUC__\n";
  }
  
  result += "struct " + std::string(packed ? "CEETAH_PACKED_STRUCT " : "") + name + " {";

  for (auto [name, type]: members) {
    result += '\n';
    result += type->toString() + " " + name + ";";
  }

  if (members.size() > 0) {
    result += '\n';
  }

  result += "};\n";

  if (packed) {
    result += "#ifndef __GNUC__\n";
    result += "#pragma pack(pop)\n";
    result += "#endif // __GNUC__\n";
    result += "#undef CEETAH_PACKED_STRUCT\n";
  }

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

bool Ceetah::AST::StructureDefinition::operator ==(const Ceetah::AST::StructureDefinition& other) const {
  if (name != other.name) return false;

  if (members.size() != other.members.size()) return false;
  for (size_t i = 0; i < members.size(); i++) {
    if (members[i].first != other.members[i].first) return false;
    if (*members[i].second != *other.members[i].second) return false;
  }

  return true;
};

std::shared_ptr<Ceetah::AST::Node> Ceetah::AST::StructureDefinition::clone() const {
  auto node = std::make_shared<Ceetah::AST::StructureDefinition>();
  cloneTo(node);
  return node;
};

void Ceetah::AST::StructureDefinition::cloneTo(std::shared_ptr<Node> _node) const {
  auto node = std::dynamic_pointer_cast<Ceetah::AST::StructureDefinition>(_node);
  Statement::cloneTo(node);
  node->name = name;
  for (size_t i = 0; i < members.size(); ++i) {
    node->members.emplace_back(
      members[i].first,
      members[i].second ? std::dynamic_pointer_cast<decltype(node->members)::value_type::second_type::element_type>(members[i].second->clone()) : nullptr
    );
    if (node->members[i].second) {
      node->members[i].second->parent = node;
    }
  }
  node->packed = packed;
};
