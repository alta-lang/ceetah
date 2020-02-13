#ifndef CEETAH_AST_MULTI_EXPRESSION_HPP
#define CEETAH_AST_MULTI_EXPRESSION_HPP

#include "expression.hpp"
#include <string>
#include <vector>

namespace Ceetah {
  namespace AST {
    class MultiExpression: public Expression {
      public:
        virtual NodeType nodeType() const override;

        std::vector<std::shared_ptr<Expression>> expressions;

        virtual std::shared_ptr<Node> clone() const override;
        void cloneTo(std::shared_ptr<Node> node) const;
        virtual std::string toString() const override;
        virtual bool operator ==(const MultiExpression& other) const;
    };
  };
};

#endif // CEETAH_AST_MULTI_EXPRESSION_HPP
