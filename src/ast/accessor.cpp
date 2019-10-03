#include "../../include/ceetah/ast/accessor.hpp"

const Ceetah::AST::NodeType Ceetah::AST::Accessor::nodeType() {
  return NodeType::Accessor;
};

std::string Ceetah::AST::Accessor::toString() {
  auto result = target->toString() + '.' + query;

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

std::shared_ptr<Ceetah::AST::Accessor> Ceetah::AST::Accessor::access(std::string subquery) {
  auto newAcc = std::make_shared<Accessor>();
  newAcc->target = std::make_shared<Accessor>(*this);
  newAcc->query = subquery;
  return newAcc;
};

bool Ceetah::AST::Accessor::operator ==(const Ceetah::AST::Accessor& other) {
  if (*target != *other.target) return false;
  return query == other.query;
};
