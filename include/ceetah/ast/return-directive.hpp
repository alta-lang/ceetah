#ifndef CEETAH_AST_RETURN_DIRECTIVE_HPP
#define CEETAH_AST_RETURN_DIRECTIVE_HPP

#include "statement.hpp"
#include "expression.hpp"
#include <string>
#include <vector>

namespace Ceetah {
  namespace AST {
    class ReturnDirective: public Statement {
      public:
        virtual const NodeType nodeType();

        std::shared_ptr<AST::Expression> value = nullptr;

        virtual std::string toString();
        virtual bool operator ==(const ReturnDirective& other);
    };
  };
};

#endif // CEETAH_AST_RETURN_DIRECTIVE_HPP
