#ifndef CEETAH_AST_PREPROCESSOR_DIRECTIVE_HPP
#define CEETAH_AST_PREPROCESSOR_DIRECTIVE_HPP

#include "statement.hpp"

namespace Ceetah {
  namespace AST {
    class PreprocessorDirective: public Statement {
      public:
        virtual const NodeType nodeType();
    };
  };
};

#endif // CEETAH_AST_PREPROCESSOR_DIRECTIVE_HPP