#include "../../include/ceetah/ast/root-node.hpp"
#include <cinttypes>

Ceetah::AST::NodeType Ceetah::AST::RootNode::nodeType() const {
  return NodeType::RootNode;
};

std::string Ceetah::AST::RootNode::toStringWithIndent(std::string indent) const {
  std::string result;

  for (auto& stmt: statements) {
    result += stmt->toStringWithIndent(indent) + '\n' + indent;
  }

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

bool Ceetah::AST::RootNode::operator ==(const Ceetah::AST::RootNode& other) const {
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

std::shared_ptr<Ceetah::AST::Node> Ceetah::AST::RootNode::clone() const {
  auto node = std::make_shared<Ceetah::AST::RootNode>();
  cloneTo(node);
  return node;
};

void Ceetah::AST::RootNode::cloneTo(std::shared_ptr<Node> _node) const {
  auto node = std::dynamic_pointer_cast<Ceetah::AST::RootNode>(_node);
  Node::cloneTo(node);
  CEETAH_AST_CLONE_CHILDREN(statements);
};
