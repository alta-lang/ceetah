#ifndef CEETAH_AST_EXPRESSION_HPP
#define CEETAH_AST_EXPRESSION_HPP

#include "node.hpp"

namespace Ceetah {
  namespace AST {
    class Expression: public Node {
      public:
        virtual const NodeType nodeType();
    };
  };
};

#endif // CEETAH_AST_EXPRESSION_HPP