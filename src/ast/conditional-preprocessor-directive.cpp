#include "../../include/ceetah/ast/conditional-preprocessor-directive.hpp"

Ceetah::AST::NodeType Ceetah::AST::ConditionalPreprocessorDirective::nodeType() const {
  return NodeType::ConditionalPreprocessorDirective;
};

std::string Ceetah::AST::ConditionalPreprocessorDirective::toString() const {
  std::string result = "#if " + test + "\n";
  for (auto& node: nodes) {
    result += node->toString();
    result += "\n";
  }
  result += "#endif // " + test;

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

bool Ceetah::AST::ConditionalPreprocessorDirective::operator ==(const Ceetah::AST::ConditionalPreprocessorDirective& other) const {
  if (test != other.test) return false;
  if (nodes.size() != other.nodes.size()) return false;
  bool ok = true;
  for (size_t i = 0; i < nodes.size(); i++) {
    if (*nodes[i] != *other.nodes[i]) {
      ok = false;
      break;
    }
  }
  return ok;
};

std::shared_ptr<Ceetah::AST::Node> Ceetah::AST::ConditionalPreprocessorDirective::clone() const {
  auto node = std::make_shared<Ceetah::AST::ConditionalPreprocessorDirective>();
  cloneTo(node);
  return node;
};

void Ceetah::AST::ConditionalPreprocessorDirective::cloneTo(std::shared_ptr<Node> _node) const {
  auto node = std::dynamic_pointer_cast<Ceetah::AST::ConditionalPreprocessorDirective>(_node);
  PreprocessorDirective::cloneTo(node);
  node->test = test;
  CEETAH_AST_CLONE_CHILDREN(nodes);
};
