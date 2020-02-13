#include "../../include/ceetah/ast/function-call.hpp"

Ceetah::AST::NodeType Ceetah::AST::FunctionCall::nodeType() const {
  return NodeType::FunctionCall;
};

std::string Ceetah::AST::FunctionCall::toString() const {
  auto result = target->toString();
  if (!macro) {
    result = '(' + result;
    result += ')';
  }
  result += '(';
  bool isFirst = true;
  for (auto& arg: arguments) {
    if (newlineOnExpressions) result += '\n';
    if (isFirst) {
      isFirst = false;
    } else {
      result += ", ";
    }
    result += arg->toString();
  }
  if (newlineOnExpressions) result += '\n';
  result += ')';

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

bool Ceetah::AST::FunctionCall::operator ==(const Ceetah::AST::FunctionCall& other) const {
  if (arguments.size() != other.arguments.size()) {
    return false;
  }
  if (*target != *other.target) return false;
  for (size_t i = 0; i < arguments.size(); i++) {
    if (*arguments[i] != *other.arguments[i]) {
      return false;
    }
  }
  if (macro != other.macro) return false;
  return true;
};

std::shared_ptr<Ceetah::AST::Node> Ceetah::AST::FunctionCall::clone() const {
  auto node = std::make_shared<Ceetah::AST::FunctionCall>();
  cloneTo(node);
  return node;
};

void Ceetah::AST::FunctionCall::cloneTo(std::shared_ptr<Node> _node) const {
  auto node = std::dynamic_pointer_cast<Ceetah::AST::FunctionCall>(_node);
  Expression::cloneTo(node);
  CEETAH_AST_CLONE_CHILD(target);
  CEETAH_AST_CLONE_CHILDREN(arguments);
  node->macro = macro;
};
