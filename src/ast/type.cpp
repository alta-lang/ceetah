#include "../include/ceetah/ast/type.hpp"
#include <cinttypes>

const Ceetah::AST::NodeType Ceetah::AST::Type::nodeType() {
  return NodeType::Type;
};

Ceetah::AST::Type::Type(std::string _name, std::vector<uint8_t> _modifiers):
  name(_name),
  modifiers(_modifiers)
  {};

std::string Ceetah::AST::Type::toString() {
  std::string result = name;
  for (auto rit = modifiers.rbegin(); rit != modifiers.rend(); rit++) {
    uint8_t& level = *rit;
    if (level & (uint8_t)TypeModifierFlag::Pointer) {
      result += " *";
    }
    if (level & (uint8_t)TypeModifierFlag::Constant) {
      result += " const";
    }
  }
  return result;
};

bool Ceetah::AST::Type::operator ==(const Ceetah::AST::Type& other) {
  if (other.name != name) return false;
  if (other.modifiers.size() != modifiers.size()) return false;
  bool modsEqual = true;
  for (size_t i = 0; i < modifiers.size(); i++) {
    auto& mod = modifiers[i];
    auto& otherMod = other.modifiers[i];
    modsEqual = mod == otherMod;
    if (!modsEqual) break;
  }
  return modsEqual;
};