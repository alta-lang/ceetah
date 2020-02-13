#ifndef CEETAH_AST_UNARY_OPERATION_HPP
#define CEETAH_AST_UNARY_OPERATION_HPP

#include "expression.hpp"
#include <string>
#include <vector>

namespace Ceetah {
  namespace AST {
    class UnaryOperation: public Expression {
      public:
        virtual NodeType nodeType() const override;

        UOperatorType type;
        bool post = false;
        std::shared_ptr<Expression> target;

        virtual std::shared_ptr<Node> clone() const override;
        void cloneTo(std::shared_ptr<Node> node) const;
        virtual std::string toString() const override;
        virtual bool operator ==(const UnaryOperation& other) const;
    };
  };
};

#endif // CEETAH_AST_UNARY_OPERATION_HPP
