#ifndef CEETAH_AST_TERNARY_OPERATION_HPP
#define CEETAH_AST_TERNARY_OPERATION_HPP

#include "expression.hpp"
#include <string>

namespace Ceetah {
  namespace AST {
    class TernaryOperation: public Expression {
    public:
      virtual const NodeType nodeType();

      std::shared_ptr<AST::Expression> test;
      std::shared_ptr<AST::Expression> primary;
      std::shared_ptr<AST::Expression> secondary;

      virtual std::string toString();
      virtual bool operator ==(const TernaryOperation& other);
    };
  };
};

#endif // CEETAH_AST_TERNARY_OPERATION_HPP
