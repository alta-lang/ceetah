#include "../../include/ceetah/ast/inclusional-preprocessor-directive.hpp"

const Ceetah::AST::NodeType Ceetah::AST::InclusionalPreprocessorDirective::nodeType() {
  return NodeType::InclusionalPreprocessorDirective;
};

std::string Ceetah::AST::InclusionalPreprocessorDirective::toString() {
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

bool Ceetah::AST::InclusionalPreprocessorDirective::operator ==(const Ceetah::AST::InclusionalPreprocessorDirective& other) {
  if (includeQuery != other.includeQuery) return false;
  return type == other.type;
};
