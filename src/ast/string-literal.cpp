#include "../../include/ceetah/ast/string-literal.hpp"

Ceetah::AST::NodeType Ceetah::AST::StringLiteral::nodeType() const {
  return NodeType::StringLiteral;
};

std::string Ceetah::AST::StringLiteral::toStringWithIndent(std::string indent) const {
  std::string result;

  result += '"';

  for (auto& ch: value) {
    // all printable characters except \ and "
    if (
      ch >= ' ' &&
      ch <= '~' &&
      ch != '\\' &&
      ch != '"'
    ) {
      result += ch;
    } else {
      result += '\\';
      if (ch == '\\' || ch == '"') {
        result += ch;
      } else if (ch == '\t') {
        result += 't';
      } else if (ch == '\r') {
        result += 'r';
      } else if (ch == '\n') {
        result += 'n';
      } else {
        result += 'x';
        result += hexDigits[(unsigned char)ch >> 4];  // upper half
        result += hexDigits[(unsigned char)ch & 0xf]; // lower half
      }
    }
  }

  result += '"';

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

bool Ceetah::AST::StringLiteral::operator ==(const Ceetah::AST::StringLiteral& other) const {
  return value == other.value;
};

std::shared_ptr<Ceetah::AST::Node> Ceetah::AST::StringLiteral::clone() const {
  auto node = std::make_shared<Ceetah::AST::StringLiteral>();
  cloneTo(node);
  return node;
};

void Ceetah::AST::StringLiteral::cloneTo(std::shared_ptr<Node> _node) const {
  auto node = std::dynamic_pointer_cast<Ceetah::AST::StringLiteral>(_node);
  Expression::cloneTo(node);
  node->value = value;
};
