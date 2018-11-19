#ifndef CEETAH_AST_FUNCTION_CALL_HPP
#define CEETAH_AST_FUNCTION_CALL_HPP

#include "expression.hpp"
#include <string>
#include <vector>

namespace Ceetah {
  namespace AST {
    class FunctionCall: public Expression {
      public:
        virtual const NodeType nodeType();

        std::shared_ptr<Expression> target;
        std::vector<std::shared_ptr<Expression>> arguments;

        virtual std::string toString();
        virtual bool operator ==(const FunctionCall& other);
    };
  };
};

#endif // CEETAH_AST_FUNCTION_CALL_HPP
