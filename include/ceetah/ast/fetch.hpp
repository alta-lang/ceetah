#ifndef CEETAH_AST_FETCH_HPP
#define CEETAH_AST_FETCH_HPP

#include "expression.hpp"
#include <string>

namespace Ceetah {
  namespace AST {
    class Fetch: public Expression {
      public:
        virtual const NodeType nodeType();

        std::string query;

        virtual std::string toString();
        virtual bool operator ==(const Fetch& other);
    };
  };
};

#endif // CEETAH_AST_FETCH_HPP