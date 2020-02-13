#include "../../include/ceetah/ast/block.hpp"

Ceetah::AST::NodeType Ceetah::AST::Block::nodeType() const {
  return NodeType::Block;
};

std::string Ceetah::AST::Block::toString() const {
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

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

bool Ceetah::AST::Block::operator ==(const Ceetah::AST::Block& other) const {
  if (statements.size() != other.statements.size()) return false;
  for (size_t i = 0; i < statements.size(); i++) {
    if (*statements[i] != *other.statements[i]) return false;
  }
  return true;
};

std::shared_ptr<Ceetah::AST::Node> Ceetah::AST::Block::clone() const {
  auto node = std::make_shared<Ceetah::AST::Block>();
  cloneTo(node);
  return node;
};

void Ceetah::AST::Block::cloneTo(std::shared_ptr<Node> _node) const {
  auto node = std::dynamic_pointer_cast<Ceetah::AST::Block>(_node);
  Statement::cloneTo(node);
  CEETAH_AST_CLONE_CHILDREN(statements);
};
