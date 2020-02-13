#include "../../include/ceetah/ast/conditional-statement.hpp"

Ceetah::AST::NodeType Ceetah::AST::ConditionalStatement::nodeType() const {
  return NodeType::ConditionalStatement;
};

std::string Ceetah::AST::ConditionalStatement::toString() const {
  std::string result = "if (" + test->toString() + ") ";
  if (newlineOnExpressions) result += '\n';
  result += primaryResult->toString();

  for (auto& [altTest, altResult]: alternatives) {
    result += " else if (" + altTest->toString() + ") ";
    if (newlineOnExpressions) result += '\n';
    result += altResult->toString();
  }

  if (finalAlternative) {
    result += " else ";
    if (newlineOnExpressions) result += '\n';
    result += finalAlternative->toString();
  }

  result += ';';

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

bool Ceetah::AST::ConditionalStatement::operator ==(const Ceetah::AST::ConditionalStatement& other) const {
  if (*test != *other.test) return false;
  if (*primaryResult != *other.primaryResult) return false;
  
  if (alternatives.size() != other.alternatives.size()) return false;
  for (size_t i = 0; i < alternatives.size(); i++) {
    if (*alternatives[i].first != *other.alternatives[i].first) return false;
    if (*alternatives[i].second != *other.alternatives[i].second) return false;
  }

  if ((bool)finalAlternative != (bool)other.finalAlternative) return false;
  if (finalAlternative && *finalAlternative != *other.finalAlternative) return false;

  return true;
};

std::shared_ptr<Ceetah::AST::Node> Ceetah::AST::ConditionalStatement::clone() const {
  auto node = std::make_shared<Ceetah::AST::ConditionalStatement>();
  cloneTo(node);
  return node;
};

void Ceetah::AST::ConditionalStatement::cloneTo(std::shared_ptr<Node> _node) const {
  auto node = std::dynamic_pointer_cast<Ceetah::AST::ConditionalStatement>(_node);
  Statement::cloneTo(node);
  CEETAH_AST_CLONE_CHILD(test);
  CEETAH_AST_CLONE_CHILD(primaryResult);
  CEETAH_AST_CLONE_CHILD(finalAlternative);
  for (size_t i = 0; i < alternatives.size(); ++i) {
    node->alternatives.emplace_back(
      alternatives[i].first ? std::dynamic_pointer_cast<decltype(node->alternatives)::value_type::first_type::element_type>(alternatives[i].first->clone()) : nullptr,
      alternatives[i].second ? std::dynamic_pointer_cast<decltype(node->alternatives)::value_type::second_type::element_type>(alternatives[i].second->clone()) : nullptr
    );
    if (node->alternatives[i].first) {
      node->alternatives[i].first->parent = node;
    }
    if (node->alternatives[i].second) {
      node->alternatives[i].second->parent = node;
    }
  }
};
