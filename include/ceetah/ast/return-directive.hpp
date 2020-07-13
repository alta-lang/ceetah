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
        virtual NodeType nodeType() const override;

        std::shared_ptr<AST::Expression> value = nullptr;

        virtual std::shared_ptr<Node> clone() const override;
        void cloneTo(std::shared_ptr<Node> node) const;
        virtual std::string toStringWithIndent(std::string indent = "") const override;
        virtual bool operator ==(const ReturnDirective& other) const;
    };
  };
};

#endif // CEETAH_AST_RETURN_DIRECTIVE_HPP
