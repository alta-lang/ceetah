#include "../../include/ceetah/ast/type.hpp"
#include <cinttypes>

Ceetah::AST::NodeType Ceetah::AST::Type::nodeType() const {
  return NodeType::Type;
};

Ceetah::AST::Type::Type()
  {};
Ceetah::AST::Type::Type(std::string _name, std::vector<uint8_t> _modifiers, bool _isStructure):
  name(_name),
  modifiers(_modifiers),
  isStructure(_isStructure)
  {};
Ceetah::AST::Type::Type(std::shared_ptr<Ceetah::AST::Type> _returnType, std::vector<std::shared_ptr<Ceetah::AST::Type>> _parameters, std::vector<uint8_t> _modifiers):
  isFunction(true),
  returnType(_returnType),
  parameters(_parameters),
  modifiers(_modifiers)
  {};

std::string Ceetah::AST::Type::toString() const {
  std::string result;
  if (isFunction) {
    result = returnType->toString() + "(*)(";
    bool isFirst = true;
    for (auto& param: parameters) {
      if (isFirst) {
        isFirst = false;
      } else {
        result += ", ";
      }
      result += param->toString();
    }
    result += ')';
  } else {
    if (isStructure) {
      result += "struct ";
    }
    result += name;
  }
  for (auto rit = modifiers.rbegin(); rit != modifiers.rend(); rit++) {
    auto& level = *rit;
    if (level & (uint8_t)TypeModifierFlag::Pointer) {
      result += " *";
    }
    if (level & (uint8_t)TypeModifierFlag::Constant) {
      result += " const";
    }
    if (level & (uint8_t)TypeModifierFlag::Unsigned) {
      result += " unsigned";
    }
    if (level & (uint8_t)TypeModifierFlag::Signed) {
      result += " signed";
    }
    if (level & (uint8_t)TypeModifierFlag::Long) {
      result += " long";
    }
    if (level & (uint8_t)TypeModifierFlag::Short) {
      result += " short";
    }
  }
  if (arraySize > 0) {
    result += '[';
    if (arraySize != SIZE_MAX) {
      result += std::to_string(arraySize);
    }
    result += ']';
  }

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

bool Ceetah::AST::Type::operator ==(const Ceetah::AST::Type& other) const {
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

std::shared_ptr<Ceetah::AST::Node> Ceetah::AST::Type::clone() const {
  auto node = std::make_shared<Ceetah::AST::Type>();
  cloneTo(node);
  return node;
};

void Ceetah::AST::Type::cloneTo(std::shared_ptr<Node> _node) const {
  auto node = std::dynamic_pointer_cast<Ceetah::AST::Type>(_node);
  Node::cloneTo(node);
  node->isFunction = isFunction;
  node->isStructure = isStructure;
  CEETAH_AST_CLONE_CHILD(returnType);
  CEETAH_AST_CLONE_CHILDREN(parameters);
  node->name = name;
  node->modifiers = modifiers;
  node->arraySize = arraySize;
};
