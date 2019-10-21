#include "../../include/ceetah/ast/conditional-statement.hpp"

const Ceetah::AST::NodeType Ceetah::AST::ConditionalStatement::nodeType() {
  return NodeType::ConditionalStatement;
};

std::string Ceetah::AST::ConditionalStatement::toString() {
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

bool Ceetah::AST::ConditionalStatement::operator ==(const Ceetah::AST::ConditionalStatement& other) {
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
