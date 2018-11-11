#include "../../include/ceetah/ast/conditional-preprocessor-directive.hpp"

const Ceetah::AST::NodeType Ceetah::AST::ConditionalPreprocessorDirective::nodeType() {
  return NodeType::ConditionalPreprocessorDirective;
};

std::string Ceetah::AST::ConditionalPreprocessorDirective::toString() {
  std::string result = "#if " + test + "\n";
  for (auto& node: nodes) {
    result += node->toString();
    result += "\n";
  }
  result += "#endif // " + test;
  return result;
};

bool Ceetah::AST::ConditionalPreprocessorDirective::operator ==(const Ceetah::AST::ConditionalPreprocessorDirective& other) {
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