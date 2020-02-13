#ifndef CEETAH_AST_CHARACTER_LITERAL_HPP
#define CEETAH_AST_CHARACTER_LITERAL_HPP

#include "expression.hpp"
#include <string>
#include <vector>

namespace Ceetah {
  namespace AST {
    class CharacterLiteral: public Expression {
      public:
        virtual NodeType nodeType() const override;

        std::string value;
        bool escaped = false;

        virtual std::shared_ptr<Node> clone() const override;
        void cloneTo(std::shared_ptr<Node> node) const;
        virtual std::string toString() const override;
        virtual bool operator ==(const CharacterLiteral& other) const;
    };
  };
};

#endif // CEETAH_AST_CHARACTER_LITERAL_HPP
