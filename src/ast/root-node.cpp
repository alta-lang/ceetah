#include "../../include/ceetah/ast/root-node.hpp"
#include <cinttypes>

const Ceetah::AST::NodeType Ceetah::AST::RootNode::nodeType() {
  return NodeType::RootNode;
};

std::string Ceetah::AST::RootNode::toString() {
  std::string result;

  for (auto& stmt: statements) {
    result += stmt->toString();
    result += '\n';
  }

  return result;
};

bool Ceetah::AST::RootNode::operator ==(const Ceetah::AST::RootNode& other) {
  if (other.statements.size() != statements.size()) return false;
  bool stmtsEqual = true;
  for (size_t i = 0; i < statements.size(); i++) {
    auto& stmt = statements[i];
    auto& otherStmt = other.statements[i];
    stmtsEqual = *stmt == *otherStmt;
    if (!stmtsEqual) break;
  }
  return stmtsEqual;
};