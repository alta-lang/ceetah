#include "../../include/ceetah/ast/multi-expression.hpp"

Ceetah::AST::NodeType Ceetah::AST::MultiExpression::nodeType() const {
  return NodeType::MultiExpression;
};

std::string Ceetah::AST::MultiExpression::toString() const {
  if (expressions.size() == 0) return "";

  std::string result = "(";

  bool isFirst = true;
  for (auto& expr: expressions) {
    if (newlineOnExpressions) result += '\n';
    if (isFirst) {
      isFirst = false;
    } else {
      result += ',';
    }
    result += '(' + expr->toString() + ')';
  }

  if (newlineOnExpressions) result += '\n';
  result += ')';

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

bool Ceetah::AST::MultiExpression::operator ==(const Ceetah::AST::MultiExpression& other) const {
  if (expressions.size() != other.expressions.size()) return false;
  bool ok = true;
  for (size_t i = 0; i < expressions.size(); i++) {
    if (*expressions[i] != *other.expressions[i]) {
      ok = false;
      break;
    }
  }
  return ok;
};

std::shared_ptr<Ceetah::AST::Node> Ceetah::AST::MultiExpression::clone() const {
  auto node = std::make_shared<Ceetah::AST::MultiExpression>();
  cloneTo(node);
  return node;
};

void Ceetah::AST::MultiExpression::cloneTo(std::shared_ptr<Node> _node) const {
  auto node = std::dynamic_pointer_cast<Ceetah::AST::MultiExpression>(_node);
  Expression::cloneTo(node);
  CEETAH_AST_CLONE_CHILDREN(expressions);
};
