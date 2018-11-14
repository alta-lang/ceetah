#ifndef CEETAH_AST_MULTI_EXPRESSION_HPP
#define CEETAH_AST_MULTI_EXPRESSION_HPP

#include "expression.hpp"
#include <string>
#include <vector>

namespace Ceetah {
  namespace AST {
    class MultiExpression: public Expression {
      public:
        virtual const NodeType nodeType();

        std::vector<std::shared_ptr<Expression>> expressions;

        virtual std::string toString();
        virtual bool operator ==(const MultiExpression& other);
    };
  };
};

#endif // CEETAH_AST_MULTI_EXPRESSION_HPP
