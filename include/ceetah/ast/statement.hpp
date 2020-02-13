#ifndef CEETAH_AST_STATEMENT_HPP
#define CEETAH_AST_STATEMENT_HPP

#include "node.hpp"

namespace Ceetah {
  namespace AST {
    class Statement: public Node {
      public:
        virtual NodeType nodeType() const override;
        virtual std::shared_ptr<Node> clone() const override;
        void cloneTo(std::shared_ptr<Node> node) const;
    };
  };
};

#endif // CEETAH_AST_STATEMENT_HPP
