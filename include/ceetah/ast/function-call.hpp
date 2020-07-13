#ifndef CEETAH_AST_FUNCTION_CALL_HPP
#define CEETAH_AST_FUNCTION_CALL_HPP

#include "expression.hpp"
#include <string>
#include <vector>

namespace Ceetah {
  namespace AST {
    class FunctionCall: public Expression {
      public:
        virtual NodeType nodeType() const override;

        std::shared_ptr<Expression> target;
        std::vector<std::shared_ptr<Expression>> arguments;
        bool macro = false;

        virtual std::shared_ptr<Node> clone() const override;
        void cloneTo(std::shared_ptr<Node> node) const;
        virtual std::string toStringWithIndent(std::string indent = "") const override;
        virtual bool operator ==(const FunctionCall& other) const;
    };
  };
};

#endif // CEETAH_AST_FUNCTION_CALL_HPP
