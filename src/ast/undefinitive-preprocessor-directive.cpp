#include "../../include/ceetah/ast/undefinitive-preprocessor-directive.hpp"

Ceetah::AST::NodeType Ceetah::AST::UndefinitivePreprocessorDirective::nodeType() const {
  return NodeType::UndefinitivePreprocessorDirective;
};

std::string Ceetah::AST::UndefinitivePreprocessorDirective::toString() const {
  auto result = "#undef " + undefinition;

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

bool Ceetah::AST::UndefinitivePreprocessorDirective::operator ==(const Ceetah::AST::UndefinitivePreprocessorDirective& other) const {
  return undefinition == other.undefinition;
};

std::shared_ptr<Ceetah::AST::Node> Ceetah::AST::UndefinitivePreprocessorDirective::clone() const {
  auto node = std::make_shared<Ceetah::AST::UndefinitivePreprocessorDirective>();
  cloneTo(node);
  return node;
};

void Ceetah::AST::UndefinitivePreprocessorDirective::cloneTo(std::shared_ptr<Node> _node) const {
  auto node = std::dynamic_pointer_cast<Ceetah::AST::UndefinitivePreprocessorDirective>(_node);
  PreprocessorDirective::cloneTo(node);
  node->undefinition = undefinition;
};
