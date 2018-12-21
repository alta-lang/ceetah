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
        virtual const NodeType nodeType();

        OperatorType type;
        std::shared_ptr<Expression> left;
        std::shared_ptr<Expression> right;

        virtual std::string toString();
        virtual bool operator ==(const BinaryOperation& other);
    };
  };
};

#endif // CEETAH_AST_BINARY_OPERATION_HPP
