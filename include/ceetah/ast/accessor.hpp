#ifndef CEETAH_AST_ACCESSOR_HPP
#define CEETAH_AST_ACCESSOR_HPP

#include "expression.hpp"
#include <string>

namespace Ceetah {
  namespace AST {
    class Accessor: public Expression {
      public:
        virtual const NodeType nodeType();

        std::shared_ptr<Expression> target;
        std::string query;

        virtual std::string toString();
        virtual bool operator ==(const Accessor& other);

        std::shared_ptr<AST::Accessor> access(std::string subquery);
    };
  };
};

#endif // CEETAH_AST_ACCESSOR_HPP
