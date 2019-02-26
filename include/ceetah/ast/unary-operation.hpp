#ifndef CEETAH_AST_UNARY_OPERATION_HPP
#define CEETAH_AST_UNARY_OPERATION_HPP

#include "expression.hpp"
#include <string>
#include <vector>

namespace Ceetah {
  namespace AST {
    class UnaryOperation: public Expression {
      public:
        virtual const NodeType nodeType();

        UOperatorType type;
        bool post = false;
        std::shared_ptr<Expression> target;

        virtual std::string toString();
        virtual bool operator ==(const UnaryOperation& other);
    };
  };
};

#endif // CEETAH_AST_UNARY_OPERATION_HPP
