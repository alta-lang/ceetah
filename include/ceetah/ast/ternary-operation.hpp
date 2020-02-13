#ifndef CEETAH_AST_TERNARY_OPERATION_HPP
#define CEETAH_AST_TERNARY_OPERATION_HPP

#include "expression.hpp"
#include <string>

namespace Ceetah {
  namespace AST {
    class TernaryOperation: public Expression {
      public:
        virtual NodeType nodeType() const override;

        std::shared_ptr<AST::Expression> test;
        std::shared_ptr<AST::Expression> primary;
        std::shared_ptr<AST::Expression> secondary;

        virtual std::shared_ptr<Node> clone() const override;
        void cloneTo(std::shared_ptr<Node> node) const;
        virtual std::string toString() const override;
        virtual bool operator ==(const TernaryOperation& other) const;
    };
  };
};

#endif // CEETAH_AST_TERNARY_OPERATION_HPP
