#include "../../include/ceetah/ast/string-literal.hpp"

const Ceetah::AST::NodeType Ceetah::AST::StringLiteral::nodeType() {
  return NodeType::StringLiteral;
};

std::string Ceetah::AST::StringLiteral::toString() {
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

bool Ceetah::AST::StringLiteral::operator ==(const Ceetah::AST::StringLiteral& other) {
  return value == other.value;
};
