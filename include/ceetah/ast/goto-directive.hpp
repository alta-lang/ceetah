#ifndef CEETAH_AST_GOTO_DIRECTIVE_HPP
#define CEETAH_AST_GOTO_DIRECTIVE_HPP

#include "statement.hpp"
#include <string>
#include <vector>

namespace Ceetah {
  namespace AST {
    class GotoDirective: public Statement {
      public:
        virtual const NodeType nodeType();

        std::string label;

        virtual std::string toString();
        virtual bool operator ==(const GotoDirective& other);
    };
  };
};

#endif // CEETAH_AST_GOTO_DIRECTIVE_HPP
