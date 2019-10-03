#include "../../include/ceetah/ast/undefinitive-preprocessor-directive.hpp"

const Ceetah::AST::NodeType Ceetah::AST::UndefinitivePreprocessorDirective::nodeType() {
  return NodeType::UndefinitivePreprocessorDirective;
};

std::string Ceetah::AST::UndefinitivePreprocessorDirective::toString() {
  auto result = "#undef " + undefinition;

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

bool Ceetah::AST::UndefinitivePreprocessorDirective::operator ==(const Ceetah::AST::UndefinitivePreprocessorDirective& other) {
  return undefinition == other.undefinition;
};
