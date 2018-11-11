#ifndef CEETAH_AST_EXPRESSION_STATEMENT_HPP
#define CEETAH_AST_EXPRESSION_STATEMENT_HPP

#include "statement.hpp"
#include "expression.hpp"
#include <string>
#include <vector>

namespace Ceetah {
  namespace AST {
    class ExpressionStatement: public Statement {
      public:
        virtual const NodeType nodeType();

        std::shared_ptr<Expression> expression;

        virtual std::string toString();
        virtual bool operator ==(const ExpressionStatement& other);
    };
  };
};

#endif // CEETAH_AST_EXPRESSION_STATEMENT_HPP
