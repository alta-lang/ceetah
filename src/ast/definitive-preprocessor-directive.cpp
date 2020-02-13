#include "../../include/ceetah/ast/definitive-preprocessor-directive.hpp"

Ceetah::AST::NodeType Ceetah::AST::DefinitivePreprocessorDirective::nodeType() const {
  return NodeType::DefinitivePreprocessorDirective;
};

std::string Ceetah::AST::DefinitivePreprocessorDirective::toString() const {
  auto result = "#define " + definition;
  if (value != "") {
    result += ' ' + value;
  }

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

bool Ceetah::AST::DefinitivePreprocessorDirective::operator ==(const Ceetah::AST::DefinitivePreprocessorDirective& other) const {
  if (definition != other.definition) return false;
  return value == other.value;
};

std::shared_ptr<Ceetah::AST::Node> Ceetah::AST::DefinitivePreprocessorDirective::clone() const {
  auto node = std::make_shared<Ceetah::AST::DefinitivePreprocessorDirective>();
  cloneTo(node);
  return node;
};

void Ceetah::AST::DefinitivePreprocessorDirective::cloneTo(std::shared_ptr<Node> _node) const {
  auto node = std::dynamic_pointer_cast<Ceetah::AST::DefinitivePreprocessorDirective>(_node);
  PreprocessorDirective::cloneTo(node);
  node->definition = definition;
  node->value = value;
};
