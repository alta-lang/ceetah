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
        virtual const NodeType nodeType();

        std::shared_ptr<Expression> test;
        std::shared_ptr<Statement> body;

        virtual std::string toString();
        virtual bool operator ==(const WhileLoop& other);
    };
  };
};

#endif // CEETAH_AST_WHILE_LOOP_HPP
