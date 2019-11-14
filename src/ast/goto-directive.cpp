#include "../../include/ceetah/ast/goto-directive.hpp"

const Ceetah::AST::NodeType Ceetah::AST::GotoDirective::nodeType() {
  return NodeType::GotoDirective;
};

std::string Ceetah::AST::GotoDirective::toString() {
  std::string result = "goto " + label + ';';

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

bool Ceetah::AST::GotoDirective::operator ==(const Ceetah::AST::GotoDirective& other) {
  return label == other.label;
};
