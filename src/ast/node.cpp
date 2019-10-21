#include "../../include/ceetah/ast/node.hpp"

namespace Ceetah {
  namespace AST {
    bool newlineOnExpressions = false;
  };
};

const Ceetah::AST::NodeType Ceetah::AST::Node::nodeType() {
  return NodeType::Node;
};

std::string Ceetah::AST::Node::toString() {
  std::string result;

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

bool Ceetah::AST::Node::operator ==(const Ceetah::AST::Node& other) {
  // by default, nodes are inequal
  return false;
};

bool Ceetah::AST::Node::operator !=(const Ceetah::AST::Node& other) {
  return !(*this == other);
};
