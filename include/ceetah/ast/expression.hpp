#ifndef CEETAH_AST_EXPRESSION_HPP
#define CEETAH_AST_EXPRESSION_HPP

#include "node.hpp"

namespace Ceetah {
  namespace AST {
    class Expression: public Node {
      public:
        virtual NodeType nodeType() const override;
        virtual std::shared_ptr<Node> clone() const override;
        void cloneTo(std::shared_ptr<Node> node) const;
    };
  };
};

#endif // CEETAH_AST_EXPRESSION_HPP
