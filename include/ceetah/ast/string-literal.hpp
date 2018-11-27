#ifndef CEETAH_AST_STRING_LITERAL_HPP
#define CEETAH_AST_STRING_LITERAL_HPP

#include "expression.hpp"
#include <string>
#include <vector>

namespace Ceetah {
  namespace AST {
    static const char* const hexDigits = "0123456789abcdef";

    class StringLiteral: public Expression {
      public:
        virtual const NodeType nodeType();

        std::string value;

        virtual std::string toString();
        virtual bool operator ==(const StringLiteral& other);
    };
  };
};

#endif // CEETAH_AST_STRING_LITERAL_HPP
