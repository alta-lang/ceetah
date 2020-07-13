#ifndef CEETAH_AST_POINTER_HPP
#define CEETAH_AST_POINTER_HPP

#include "expression.hpp"
#include <string>

namespace Ceetah {
  namespace AST {
    class Pointer: public Expression {
      public:
        virtual NodeType nodeType() const override;

        std::shared_ptr<AST::Expression> target;

        virtual std::shared_ptr<Node> clone() const override;
        void cloneTo(std::shared_ptr<Node> node) const;
        virtual std::string toStringWithIndent(std::string indent = "") const override;
        virtual bool operator ==(const Pointer& other) const;
    };
  };
};

#endif // CEETAH_AST_POINTER_HPP
