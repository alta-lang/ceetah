#include "../../include/ceetah/ast/array-literal.hpp"

const Ceetah::AST::NodeType Ceetah::AST::ArrayLiteral::nodeType() {
  return NodeType::ArrayLiteral;
};

std::string Ceetah::AST::ArrayLiteral::toString() {
  std::string result = "";

  if (type) {
    result += '(';
    result += type->toString();
    result += ')';
  }

  result += '{';
  
  bool isFirst = true;
  for (auto& item: items) {
    if (isFirst) {
      isFirst = false;
    } else {
      result += ',';
    }

    result += '(';
    result += item->toString();
    result += ')';
  }
  
  result += '}';

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

bool Ceetah::AST::ArrayLiteral::operator ==(const Ceetah::AST::ArrayLiteral& other) {
  if ((!!type) != (!!other.type)) return false;

  if (type && *type != *other.type) return false;

  if (items.size() != other.items.size()) return false;

  bool match = true;
  for (size_t i = 0; i < items.size(); i++) {
    if (*items[i] != *other.items[i]) {
      match = false;
      break;
    }
  }
  if (!match) return false;

  return true;
};
