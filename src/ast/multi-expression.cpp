#include "../../include/ceetah/ast/multi-expression.hpp"

const Ceetah::AST::NodeType Ceetah::AST::MultiExpression::nodeType() {
  return NodeType::MultiExpression;
};

std::string Ceetah::AST::MultiExpression::toString() {
  if (expressions.size() == 0) return "";

  std::string result = "(";

  bool isFirst = true;
  for (auto& expr: expressions) {
    if (isFirst) {
      isFirst = false;
    } else {
      result += ',';
    }
    result += '(' + expr->toString() + ')';
  }

  result += ')';

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

bool Ceetah::AST::MultiExpression::operator ==(const Ceetah::AST::MultiExpression& other) {
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
