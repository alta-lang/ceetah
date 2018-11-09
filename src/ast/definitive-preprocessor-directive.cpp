#include "../include/ceetah/ast/definitive-preprocessor-directive.hpp"

const Ceetah::AST::NodeType Ceetah::AST::DefinitivePreprocessorDirective::nodeType() {
  return NodeType::DefinitivePreprocessorDirective;
};

std::string Ceetah::AST::DefinitivePreprocessorDirective::toString() {
  auto result = "#define " + definition;
  if (value != "") {
    result += ' ' + value;
  }
  return result;
};

bool Ceetah::AST::DefinitivePreprocessorDirective::operator ==(const Ceetah::AST::DefinitivePreprocessorDirective& other) {
  if (definition != other.definition) return false;
  return value == other.value;
};