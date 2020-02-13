#ifndef CEETAH_AST_GOTO_DIRECTIVE_HPP
#define CEETAH_AST_GOTO_DIRECTIVE_HPP

#include "statement.hpp"
#include <string>
#include <vector>

namespace Ceetah {
  namespace AST {
    class GotoDirective: public Statement {
      public:
        virtual NodeType nodeType() const override;

        std::string label;

        virtual std::shared_ptr<Node> clone() const override;
        void cloneTo(std::shared_ptr<Node> node) const;
        virtual std::string toString() const override;
        virtual bool operator ==(const GotoDirective& other) const;
    };
  };
};

#endif // CEETAH_AST_GOTO_DIRECTIVE_HPP
