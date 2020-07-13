#include "../../include/ceetah/ast/node.hpp"
#include <sstream>

namespace Ceetah {
  namespace AST {
    bool newlineOnExpressions = false;
  };
};

Ceetah::AST::NodeType Ceetah::AST::Node::nodeType() const {
  return NodeType::Node;
};

std::string Ceetah::AST::Node::toString() const {
  std::stringstream stream(toStringWithIndent());
  std::string line;
  std::string result;

  while (std::getline(stream, line, '\n')) {
    auto pos = line.find_first_not_of('\t');
    if (pos == std::string::npos) {
      result += '\n';
    } else {
      result += line.substr(pos) + '\n';
    }
  }

  return result;
};

bool Ceetah::AST::Node::operator ==(const Ceetah::AST::Node& other) const {
  // by default, nodes are inequal
  return false;
};

bool Ceetah::AST::Node::operator !=(const Ceetah::AST::Node& other) {
  return !(*this == other);
};

std::shared_ptr<Ceetah::AST::Node> Ceetah::AST::Node::clone() const {
  auto node = std::make_shared<Ceetah::AST::Node>();
  cloneTo(node);
  return node;
};

void Ceetah::AST::Node::cloneTo(std::shared_ptr<Node> _node) const {
  auto node = std::dynamic_pointer_cast<Ceetah::AST::Node>(_node);
  node->preComment = preComment;
  node->postComment = postComment;
};

std::string Ceetah::AST::Node::toStringWithIndent(std::string indent) const {
  std::string result;

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};
