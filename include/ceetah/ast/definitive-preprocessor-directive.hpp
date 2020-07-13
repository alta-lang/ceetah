#ifndef CEETAH_AST_DEFINITIVE_PREPROCESSOR_DIRECTIVE_HPP
#define CEETAH_AST_DEFINITIVE_PREPROCESSOR_DIRECTIVE_HPP

#include "preprocessor-directive.hpp"
#include <string>

namespace Ceetah {
  namespace AST {
    class DefinitivePreprocessorDirective: public PreprocessorDirective {
      public:
        virtual NodeType nodeType() const override;

        std::string definition;
        std::string value = "";

        virtual std::shared_ptr<Node> clone() const override;
        void cloneTo(std::shared_ptr<Node> node) const;
        virtual std::string toStringWithIndent(std::string indent = "") const override;
        virtual bool operator ==(const DefinitivePreprocessorDirective& other) const;
    };
  };
};

#endif // CEETAH_AST_DEFINITIVE_PREPROCESSOR_DIRECTIVE_HPP
