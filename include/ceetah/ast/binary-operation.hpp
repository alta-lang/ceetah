#ifndef CEETAH_AST_BINARY_OPERATION_HPP
#define CEETAH_AST_BINARY_OPERATION_HPP

#include "expression.hpp"
#include <string>
#include <vector>

namespace Ceetah {
  namespace AST {
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
