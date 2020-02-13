#ifndef CEETAH_AST_ROOT_NODE_HPP
#define CEETAH_AST_ROOT_NODE_HPP

#include "node.hpp"
#include "statement.hpp"
#include <vector>

namespace Ceetah {
  namespace AST {
    class RootNode: public Node {
      public:
        virtual NodeType nodeType() const override;

        std::vector<std::shared_ptr<Node>> statements;

        virtual std::shared_ptr<Node> clone() const override;
        void cloneTo(std::shared_ptr<Node> node) const;
        virtual std::string toString() const override;
        virtual bool operator ==(const RootNode& other) const;
    };
  };
};

#endif // CEETAH_AST_ROOT_NODE_HPP
