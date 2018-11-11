#ifndef CEETAH_AST_DEREFERENCE_HPP
#define CEETAH_AST_DEREFERENCE_HPP

#include "expression.hpp"
#include <string>

namespace Ceetah {
  namespace AST {
    class Dereference: public Expression {
      public:
        virtual const NodeType nodeType();

        std::shared_ptr<AST::Expression> target;

        virtual std::string toString();
        virtual bool operator ==(const Dereference& other);
    };
  };
};

#endif // CEETAH_AST_DEREFERENCE_HPP
