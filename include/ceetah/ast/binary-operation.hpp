#ifndef CEETAH_AST_BINARY_OPERATION_HPP
#define CEETAH_AST_BINARY_OPERATION_HPP

#include "expression.hpp"
#include <string>
#include <vector>

namespace Ceetah {
  namespace AST {
    // this is a binary operation, not in the sense
    // that it performs any binary manipulation, but in
    // literal sense of the word:
    //     bi(n)-ary = 2-arguments
    class BinaryOperation: public Expression {
      public:
        virtual NodeType nodeType() const override;

        OperatorType type;
        std::shared_ptr<Expression> left;
        std::shared_ptr<Expression> right;

        virtual std::shared_ptr<Node> clone() const override;
        void cloneTo(std::shared_ptr<Node> node) const;
        virtual std::string toStringWithIndent(std::string indent = "") const override;
        virtual bool operator ==(const BinaryOperation& other) const;
    };
  };
};

#endif // CEETAH_AST_BINARY_OPERATION_HPP
