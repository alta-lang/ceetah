#ifndef CEETAH_AST_POINTER_HPP
#define CEETAH_AST_POINTER_HPP

#include "expression.hpp"
#include <string>

namespace Ceetah {
  namespace AST {
    class Pointer: public Expression {
      public:
        virtual const NodeType nodeType();

        std::shared_ptr<AST::Expression> target;

        virtual std::string toString();
        virtual bool operator ==(const Pointer& other);
    };
  };
};

#endif // CEETAH_AST_POINTER_HPP
