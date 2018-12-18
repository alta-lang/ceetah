#include "../../include/ceetah/ast/block.hpp"

const Ceetah::AST::NodeType Ceetah::AST::Block::nodeType() {
  return NodeType::Block;
};

std::string Ceetah::AST::Block::toString() {
  std::string result = "{";
  bool isFirst = true;
  for (auto& stmt: statements) {
    if (isFirst) {
      result += '\n';
      isFirst = false;
    }
    result += stmt->toString() + '\n';
  }
  result += "}";
  return result;
};

bool Ceetah::AST::Block::operator ==(const Ceetah::AST::Block& other) {
  if (statements.size() != other.statements.size()) return false;
  for (size_t i = 0; i < statements.size(); i++) {
    if (*statements[i] != *other.statements[i]) return false;
  }
  return true;
};
