#ifndef CEETAH_AST_UNDEFINITIVE_PREPROCESSOR_DIRECTIVE_HPP
#define CEETAH_AST_UNDEFINITIVE_PREPROCESSOR_DIRECTIVE_HPP

#include "preprocessor-directive.hpp"
#include <string>

namespace Ceetah {
  namespace AST {
    class UndefinitivePreprocessorDirective: public PreprocessorDirective {
      public:
        virtual NodeType nodeType() const override;

        std::string undefinition;

        virtual std::shared_ptr<Node> clone() const override;
        void cloneTo(std::shared_ptr<Node> node) const;
        virtual std::string toStringWithIndent(std::string indent = "") const override;
        virtual bool operator ==(const UndefinitivePreprocessorDirective& other) const;
    };
  };
};

#endif // CEETAH_AST_UNDEFINITIVE_PREPROCESSOR_DIRECTIVE_HPP
