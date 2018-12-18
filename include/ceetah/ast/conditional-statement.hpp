#ifndef CEETAH_AST_CONDITIONAL_STATEMENT_HPP
#define CEETAH_AST_CONDITIONAL_STATEMENT_HPP

#include "statement.hpp"
#include "expression.hpp"
#include <vector>

namespace Ceetah {
  namespace AST {
    class ConditionalStatement: public Statement {
      public:
        virtual const NodeType nodeType();

        std::shared_ptr<Expression> test;
        std::shared_ptr<Statement> primaryResult;
        std::vector<std::pair<std::shared_ptr<Expression>, std::shared_ptr<Statement>>> alternatives;
        std::shared_ptr<Statement> finalAlternative = nullptr;

        virtual std::string toString();
        virtual bool operator ==(const ConditionalStatement& other);
    };
  };
};

#endif // CEETAH_AST_CONDITIONAL_STATEMENT_HPP
