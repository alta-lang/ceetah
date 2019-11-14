#include "../../include/ceetah/ast/label.hpp"

const Ceetah::AST::NodeType Ceetah::AST::Label::nodeType() {
  return NodeType::Label;
};

std::string Ceetah::AST::Label::toString() {
  std::string result = label + ':';

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

bool Ceetah::AST::Label::operator ==(const Ceetah::AST::Label& other) {
  return label == other.label;
};
