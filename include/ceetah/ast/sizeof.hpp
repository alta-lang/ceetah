#ifndef CEETAH_AST_SIZEOF_HPP
#define CEETAH_AST_SIZEOF_HPP

#include "expression.hpp"
#include "type.hpp"
#include <string>
#include <vector>

namespace Ceetah {
  namespace AST {
    class Sizeof: public Expression {
      public:
        virtual const NodeType nodeType();

        std::shared_ptr<Type> type;

        virtual std::string toString();
        virtual bool operator ==(const Sizeof& other);
    };
  };
};

#endif // CEETAH_AST_SIZEOF_HPP
