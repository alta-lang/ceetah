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
        virtual NodeType nodeType() const override;

        std::shared_ptr<Expression> expression;

        virtual std::shared_ptr<Node> clone() const override;
        void cloneTo(std::shared_ptr<Node> node) const;
        virtual std::string toString() const override;
        virtual bool operator ==(const ExpressionStatement& other) const;
    };
  };
};

#endif // CEETAH_AST_EXPRESSION_STATEMENT_HPP
