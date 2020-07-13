#include "../../include/ceetah/ast/expression-statement.hpp"

Ceetah::AST::NodeType Ceetah::AST::ExpressionStatement::nodeType() const {
  return NodeType::ExpressionStatement;
};

std::string Ceetah::AST::ExpressionStatement::toStringWithIndent(std::string indent) const {
  auto result = expression->toStringWithIndent(indent) + ";";

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

bool Ceetah::AST::ExpressionStatement::operator ==(const Ceetah::AST::ExpressionStatement& other) const {
  return *expression == *other.expression;
};

std::shared_ptr<Ceetah::AST::Node> Ceetah::AST::ExpressionStatement::clone() const {
  auto node = std::make_shared<Ceetah::AST::ExpressionStatement>();
  cloneTo(node);
  return node;
};

void Ceetah::AST::ExpressionStatement::cloneTo(std::shared_ptr<Node> _node) const {
  auto node = std::dynamic_pointer_cast<Ceetah::AST::ExpressionStatement>(_node);
  Statement::cloneTo(node);
  CEETAH_AST_CLONE_CHILD(expression);
};
