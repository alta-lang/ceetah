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
        virtual NodeType nodeType() const override;

        std::string value;

        virtual std::shared_ptr<Node> clone() const override;
        void cloneTo(std::shared_ptr<Node> node) const;
        virtual std::string toStringWithIndent(std::string indent = "") const override;
        virtual bool operator ==(const StringLiteral& other) const;
    };
  };
};

#endif // CEETAH_AST_STRING_LITERAL_HPP
