#ifndef CEETAH_AST_INTEGER_LITERAL_HPP
#define CEETAH_AST_INTEGER_LITERAL_HPP

#include "expression.hpp"
#include <string>
#include <vector>

namespace Ceetah {
  namespace AST {
    class IntegerLiteral: public Expression {
      public:
        virtual const NodeType nodeType();

        std::string raw;

        virtual std::string toString();
        virtual bool operator ==(const IntegerLiteral& other);
    };
  };
};

#endif // CEETAH_AST_INTEGER_LITERAL_HPP