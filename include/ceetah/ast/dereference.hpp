#ifndef CEETAH_AST_DEREFERENCE_HPP
#define CEETAH_AST_DEREFERENCE_HPP

#include "expression.hpp"
#include <string>

namespace Ceetah {
  namespace AST {
    class Dereference: public Expression {
      public:
        virtual NodeType nodeType() const override;

        std::shared_ptr<AST::Expression> target;

        virtual std::shared_ptr<Node> clone() const override;
        void cloneTo(std::shared_ptr<Node> node) const;
        virtual std::string toString() const override;
        virtual bool operator ==(const Dereference& other) const;
    };
  };
};

#endif // CEETAH_AST_DEREFERENCE_HPP
