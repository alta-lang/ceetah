#ifndef CEETAH_AST_STATEMENT_HPP
#define CEETAH_AST_STATEMENT_HPP

#include "node.hpp"

namespace Ceetah {
  namespace AST {
    class Statement: public Node {
      public:
        virtual const NodeType nodeType();
    };
  };
};

#endif // CEETAH_AST_STATEMENT_HPP