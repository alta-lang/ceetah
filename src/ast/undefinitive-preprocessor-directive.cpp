#include "../../include/ceetah/ast/undefinitive-preprocessor-directive.hpp"

const Ceetah::AST::NodeType Ceetah::AST::UndefinitivePreprocessorDirective::nodeType() {
  return NodeType::UndefinitivePreprocessorDirective;
};

std::string Ceetah::AST::UndefinitivePreprocessorDirective::toString() {
  return "#undef " + undefinition;
};

bool Ceetah::AST::UndefinitivePreprocessorDirective::operator ==(const Ceetah::AST::UndefinitivePreprocessorDirective& other) {
  return undefinition == other.undefinition;
};
