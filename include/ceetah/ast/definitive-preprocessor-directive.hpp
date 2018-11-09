#ifndef CEETAH_AST_DEFINITIVE_PREPROCESSOR_DIRECTIVE_HPP
#define CEETAH_AST_DEFINITIVE_PREPROCESSOR_DIRECTIVE_HPP

#include "preprocessor-directive.hpp"
#include <string>

namespace Ceetah {
  namespace AST {
    class DefinitivePreprocessorDirective: public PreprocessorDirective {
      public:
        virtual const NodeType nodeType();

        std::string definition;
        std::string value = "";

        virtual std::string toString();
        virtual bool operator ==(const DefinitivePreprocessorDirective& other);
    };
  };
};

#endif // CEETAH_AST_DEFINITIVE_PREPROCESSOR_DIRECTIVE_HPP