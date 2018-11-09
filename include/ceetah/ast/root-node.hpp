#ifndef CEETAH_AST_ROOT_NODE_HPP
#define CEETAH_AST_ROOT_NODE_HPP

#include "node.hpp"
#include "statement.hpp"
#include <vector>

namespace Ceetah {
  namespace AST {
    class RootNode: public Node {
      public:
        virtual const NodeType nodeType();

        std::vector<Node*> statements;

        virtual std::string toString();
        virtual bool operator ==(const RootNode& other);
    };
  };
};

#endif // CEETAH_AST_ROOT_NODE_HPP