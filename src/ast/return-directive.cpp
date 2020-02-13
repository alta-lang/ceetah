#include "../../include/ceetah/ast/return-directive.hpp"

Ceetah::AST::NodeType Ceetah::AST::ReturnDirective::nodeType() const {
  return NodeType::ReturnDirective;
};

std::string Ceetah::AST::ReturnDirective::toString() const {
  std::string result;

  if (value != nullptr) {
    result = "return " + value->toString() + ";";
  } else {
    result = "return;";
  }

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

bool Ceetah::AST::ReturnDirective::operator ==(const Ceetah::AST::ReturnDirective& other) const {
  if ((other.value == nullptr) != (value == nullptr)) {
    return false;
  }
  // we only have to test one now, since we already confirmed that
  // they're either both nullptr or both non-nullptr
  if (value != nullptr) {
    return *value == *other.value;
  }
  return true;
};

std::shared_ptr<Ceetah::AST::Node> Ceetah::AST::ReturnDirective::clone() const {
  auto node = std::make_shared<Ceetah::AST::ReturnDirective>();
  cloneTo(node);
  return node;
};

void Ceetah::AST::ReturnDirective::cloneTo(std::shared_ptr<Node> _node) const {
  auto node = std::dynamic_pointer_cast<Ceetah::AST::ReturnDirective>(_node);
  Statement::cloneTo(node);
  CEETAH_AST_CLONE_CHILD(value);
};
