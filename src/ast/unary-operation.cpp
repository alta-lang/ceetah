#include "../../include/ceetah/ast/unary-operation.hpp"

Ceetah::AST::NodeType Ceetah::AST::UnaryOperation::nodeType() const {
  return NodeType::UnaryOperation;
};

std::string Ceetah::AST::UnaryOperation::toStringWithIndent(std::string indent) const {
  std::string result;

  if (post) {
    result = "((" + target->toStringWithIndent(indent) + ')' + UOperatorType_operators[(uint8_t)type] + ')';
  } else {
    result = std::string("(") + UOperatorType_operators[(uint8_t)type] + '(' + target->toStringWithIndent(indent) + "))";
  }

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

bool Ceetah::AST::UnaryOperation::operator ==(const Ceetah::AST::UnaryOperation& other) const {
  if (type != other.type) return false;
  return *target == *other.target;
};

std::shared_ptr<Ceetah::AST::Node> Ceetah::AST::UnaryOperation::clone() const {
  auto node = std::make_shared<Ceetah::AST::UnaryOperation>();
  cloneTo(node);
  return node;
};

void Ceetah::AST::UnaryOperation::cloneTo(std::shared_ptr<Node> _node) const {
  auto node = std::dynamic_pointer_cast<Ceetah::AST::UnaryOperation>(_node);
  Expression::cloneTo(node);
  node->type = type;
  node->post = post;
  CEETAH_AST_CLONE_CHILD(target);
};
