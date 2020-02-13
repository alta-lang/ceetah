#ifndef CEETAH_AST_CONDITIONAL_PREPROCESSOR_DIRECTIVE_HPP
#define CEETAH_AST_CONDITIONAL_PREPROCESSOR_DIRECTIVE_HPP

#include "preprocessor-directive.hpp"
#include <vector>

namespace Ceetah {
  namespace AST {
    class ConditionalPreprocessorDirective: public PreprocessorDirective {
      public:
        virtual NodeType nodeType() const override;

        std::string test;
        std::vector<std::shared_ptr<Node>> nodes;

        virtual std::shared_ptr<Node> clone() const override;
        void cloneTo(std::shared_ptr<Node> node) const;
        virtual std::string toString() const override;
        virtual bool operator ==(const ConditionalPreprocessorDirective& other) const;
    };
  };
};

#endif // CEETAH_AST_CONDITIONAL_PREPROCESSOR_DIRECTIVE_HPP
