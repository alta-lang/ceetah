#ifndef CEETAH_AST_INCLUSIONAL_PREPROCESSOR_DIRECTIVE_HPP
#define CEETAH_AST_INCLUSIONAL_PREPROCESSOR_DIRECTIVE_HPP

#include "preprocessor-directive.hpp"
#include <string>

namespace Ceetah {
  namespace AST {
    enum class InclusionType {
      Local,
      System,
      Computed,
    };

    class InclusionalPreprocessorDirective: public PreprocessorDirective {
      public:
        virtual const NodeType nodeType();

        std::string includeQuery;
        InclusionType type;

        virtual std::string toString();
        virtual bool operator ==(const InclusionalPreprocessorDirective& other);
    };
  };
};

#endif // CEETAH_AST_INCLUSIONAL_PREPROCESSOR_DIRECTIVE_HPP