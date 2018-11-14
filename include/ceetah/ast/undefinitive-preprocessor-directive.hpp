#ifndef CEETAH_AST_UNDEFINITIVE_PREPROCESSOR_DIRECTIVE_HPP
#define CEETAH_AST_UNDEFINITIVE_PREPROCESSOR_DIRECTIVE_HPP

#include "preprocessor-directive.hpp"
#include <string>

namespace Ceetah {
  namespace AST {
    class UndefinitivePreprocessorDirective: public PreprocessorDirective {
      public:
        virtual const NodeType nodeType();

        std::string undefinition;

        virtual std::string toString();
        virtual bool operator ==(const UndefinitivePreprocessorDirective& other);
    };
  };
};

#endif // CEETAH_AST_UNDEFINITIVE_PREPROCESSOR_DIRECTIVE_HPP
