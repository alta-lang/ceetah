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
        virtual NodeType nodeType() const override;

        std::string includeQuery;
        InclusionType type;

        virtual std::shared_ptr<Node> clone() const override;
        void cloneTo(std::shared_ptr<Node> node) const;
        virtual std::string toString() const override;
        virtual bool operator ==(const InclusionalPreprocessorDirective& other) const;
    };
  };
};

#endif // CEETAH_AST_INCLUSIONAL_PREPROCESSOR_DIRECTIVE_HPP
