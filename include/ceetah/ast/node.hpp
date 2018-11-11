#ifndef CEETAH_AST_NODE_HPP
#define CEETAH_AST_NODE_HPP

#include "../ast-shared.hpp"
#include <string>

namespace Ceetah {
  namespace AST {
    class Node {
      public:
        virtual const NodeType nodeType();

        std::weak_ptr<Node> parent;
        
        virtual std::string toString();
        virtual bool operator ==(const Node& other);
        virtual bool operator !=(const Node& other);
    };
  };
};

#endif // CEETAH_AST_NODE_HPP
