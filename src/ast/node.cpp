#include "../../include/ceetah/ast/node.hpp"

const Ceetah::AST::NodeType Ceetah::AST::Node::nodeType() {
  return NodeType::Node;
};

std::string Ceetah::AST::Node::toString() {
  return "";
};

bool Ceetah::AST::Node::operator ==(const Ceetah::AST::Node& other) {
  // by default, nodes are inequal
  return false;
};

bool Ceetah::AST::Node::operator !=(const Ceetah::AST::Node& other) {
  return !(*this == other);
};