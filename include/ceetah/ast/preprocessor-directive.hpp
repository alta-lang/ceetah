#ifndef CEETAH_AST_PREPROCESSOR_DIRECTIVE_HPP
#define CEETAH_AST_PREPROCESSOR_DIRECTIVE_HPP

#include "statement.hpp"

namespace Ceetah {
  namespace AST {
    class PreprocessorDirective: public Statement {
      public:
        virtual NodeType nodeType() const override;
        virtual std::shared_ptr<Node> clone() const override;
        void cloneTo(std::shared_ptr<Node> node) const;
    };
  };
};

#endif // CEETAH_AST_PREPROCESSOR_DIRECTIVE_HPP
