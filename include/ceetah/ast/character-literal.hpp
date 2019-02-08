#ifndef CEETAH_AST_CHARACTER_LITERAL_HPP
#define CEETAH_AST_CHARACTER_LITERAL_HPP

#include "expression.hpp"
#include <string>
#include <vector>

namespace Ceetah {
  namespace AST {
    class CharacterLiteral: public Expression {
      public:
        virtual const NodeType nodeType();

        std::string value;
        bool escaped = false;

        virtual std::string toString();
        virtual bool operator ==(const CharacterLiteral& other);
    };
  };
};

#endif // CEETAH_AST_CHARACTER_LITERAL_HPP
