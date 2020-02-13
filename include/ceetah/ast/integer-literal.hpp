#ifndef CEETAH_AST_INTEGER_LITERAL_HPP
#define CEETAH_AST_INTEGER_LITERAL_HPP

#include "expression.hpp"
#include <string>
#include <vector>

namespace Ceetah {
  namespace AST {
    class IntegerLiteral: public Expression {
      public:
        virtual NodeType nodeType() const override;

        std::string raw;

        virtual std::shared_ptr<Node> clone() const override;
        void cloneTo(std::shared_ptr<Node> node) const;
        virtual std::string toString() const override;
        virtual bool operator ==(const IntegerLiteral& other) const;
    };
  };
};

#endif // CEETAH_AST_INTEGER_LITERAL_HPP
