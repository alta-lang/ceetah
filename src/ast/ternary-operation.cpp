#include "../../include/ceetah/ast/ternary-operation.hpp"

Ceetah::AST::NodeType Ceetah::AST::TernaryOperation::nodeType() const {
  return NodeType::TernaryOperation;
};

std::string Ceetah::AST::TernaryOperation::toStringWithIndent(std::string indent) const {
  auto result = "((" + test->toStringWithIndent(indent) + ") ?";
  if (newlineOnExpressions) result += '\n' + indent;
  result += '(' + primary->toStringWithIndent(indent) + ") : ";
  if (newlineOnExpressions) result += '\n' + indent;
  result += '(' + secondary->toStringWithIndent(indent) + "))";

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

bool Ceetah::AST::TernaryOperation::operator ==(const Ceetah::AST::TernaryOperation& other) const {
  if (*test != *other.test) return false;
  if (*primary != *other.primary) return false;
  return *secondary == *other.secondary;
};

std::shared_ptr<Ceetah::AST::Node> Ceetah::AST::TernaryOperation::clone() const {
  auto node = std::make_shared<Ceetah::AST::TernaryOperation>();
  cloneTo(node);
  return node;
};

void Ceetah::AST::TernaryOperation::cloneTo(std::shared_ptr<Node> _node) const {
  auto node = std::dynamic_pointer_cast<Ceetah::AST::TernaryOperation>(_node);
  Expression::cloneTo(node);
  CEETAH_AST_CLONE_CHILD(test);
  CEETAH_AST_CLONE_CHILD(primary);
  CEETAH_AST_CLONE_CHILD(secondary);
};
