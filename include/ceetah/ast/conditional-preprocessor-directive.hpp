#ifndef CEETAH_AST_CONDITIONAL_PREPROCESSOR_DIRECTIVE_HPP
#define CEETAH_AST_CONDITIONAL_PREPROCESSOR_DIRECTIVE_HPP

#include "preprocessor-directive.hpp"
#include <vector>

namespace Ceetah {
  namespace AST {
    class ConditionalPreprocessorDirective: public PreprocessorDirective {
      public:
        virtual const NodeType nodeType();

        std::string test;
        std::vector<Node*> nodes;

        virtual std::string toString();
        virtual bool operator ==(const ConditionalPreprocessorDirective& other);
    };
  };
};

#endif // CEETAH_AST_CONDITIONAL_PREPROCESSOR_DIRECTIVE_HPP