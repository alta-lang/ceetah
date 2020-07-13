#include "../../include/ceetah/ast/inclusional-preprocessor-directive.hpp"

Ceetah::AST::NodeType Ceetah::AST::InclusionalPreprocessorDirective::nodeType() const {
  return NodeType::InclusionalPreprocessorDirective;
};

std::string Ceetah::AST::InclusionalPreprocessorDirective::toStringWithIndent(std::string indent) const {
  auto result = std::string("#include ") +
                (type == InclusionType::Computed ? ' ' : (type == InclusionType::Local ? '\"' : '<')) +
                includeQuery +
                (type == InclusionType::Computed ? ' ' : (type == InclusionType::Local ? '\"' : '>'));

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

bool Ceetah::AST::InclusionalPreprocessorDirective::operator ==(const Ceetah::AST::InclusionalPreprocessorDirective& other) const {
  if (includeQuery != other.includeQuery) return false;
  return type == other.type;
};

std::shared_ptr<Ceetah::AST::Node> Ceetah::AST::InclusionalPreprocessorDirective::clone() const {
  auto node = std::make_shared<Ceetah::AST::InclusionalPreprocessorDirective>();
  cloneTo(node);
  return node;
};

void Ceetah::AST::InclusionalPreprocessorDirective::cloneTo(std::shared_ptr<Node> _node) const {
  auto node = std::dynamic_pointer_cast<Ceetah::AST::InclusionalPreprocessorDirective>(_node);
  PreprocessorDirective::cloneTo(node);
  node->includeQuery = includeQuery;
  node->type = type;
};
