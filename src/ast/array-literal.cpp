#include "../../include/ceetah/ast/array-literal.hpp"

Ceetah::AST::NodeType Ceetah::AST::ArrayLiteral::nodeType() const {
  return NodeType::ArrayLiteral;
};

std::string Ceetah::AST::ArrayLiteral::toStringWithIndent(std::string indent) const {
  std::string result = "";

  if (type) {
    result += '(';
    result += type->toStringWithIndent(indent);
    result += ')';
  }

  result += '{';

  bool isFirst = true;
  for (auto& item: items) {
    if (newlineOnExpressions) result += '\n' + indent + '\t';

    if (isFirst) {
      isFirst = false;
    } else {
      result += ',';
    }

    result += '(';
    result += item->toStringWithIndent(indent + "\t\t");
    result += ')';
  }

  if (newlineOnExpressions) result += '\n' + indent;

  result += '}';

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

bool Ceetah::AST::ArrayLiteral::operator ==(const Ceetah::AST::ArrayLiteral& other) const {
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

std::shared_ptr<Ceetah::AST::Node> Ceetah::AST::ArrayLiteral::clone() const {
  auto node = std::make_shared<Ceetah::AST::ArrayLiteral>();
  cloneTo(node);
  return node;
};

void Ceetah::AST::ArrayLiteral::cloneTo(std::shared_ptr<Node> _node) const {
  auto node = std::dynamic_pointer_cast<Ceetah::AST::ArrayLiteral>(_node);
  Expression::cloneTo(node);
  CEETAH_AST_CLONE_CHILD(type);
  CEETAH_AST_CLONE_CHILDREN(items);
};
