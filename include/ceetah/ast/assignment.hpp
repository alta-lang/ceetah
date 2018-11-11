#ifndef CEETAH_AST_ASSIGNMENT_HPP
#define CEETAH_AST_ASSIGNMENT_HPP

#include "expression.hpp"
#include <string>

namespace Ceetah {
  namespace AST {
    class Assignment: public Expression {
      public:
        virtual const NodeType nodeType();

        std::shared_ptr<AST::Expression> target;
        std::shared_ptr<AST::Expression> value;

        virtual std::string toString();
        virtual bool operator ==(const Assignment& other);
    };
  };
};

#endif // CEETAH_AST_ASSIGNMENT_HPP
