#ifndef CEETAH_AST_WHILE_LOOP_HPP
#define CEETAH_AST_WHILE_LOOP_HPP

#include "expression.hpp"
#include "statement.hpp"
#include <string>
#include <vector>

namespace Ceetah {
  namespace AST {
    class WhileLoop: public Statement {
      public:
        virtual NodeType nodeType() const override;

        std::shared_ptr<Expression> test;
        std::shared_ptr<Statement> body;

        virtual std::shared_ptr<Node> clone() const override;
        void cloneTo(std::shared_ptr<Node> node) const;
        virtual std::string toString() const override;
        virtual bool operator ==(const WhileLoop& other) const;
    };
  };
};

#endif // CEETAH_AST_WHILE_LOOP_HPP
