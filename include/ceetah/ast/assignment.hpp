#ifndef CEETAH_AST_ASSIGNMENT_HPP
#define CEETAH_AST_ASSIGNMENT_HPP

#include "expression.hpp"
#include <string>

namespace Ceetah {
  namespace AST {
    class Assignment: public Expression {
      public:
        virtual NodeType nodeType() const override;

        std::shared_ptr<AST::Expression> target;
        std::shared_ptr<AST::Expression> value;
        AssignmentType type = AssignmentType::Simple;

        virtual std::shared_ptr<Node> clone() const override;
        void cloneTo(std::shared_ptr<Node> node) const;
        virtual std::string toString() const override;
        virtual bool operator ==(const Assignment& other) const;
    };
  };
};

#endif // CEETAH_AST_ASSIGNMENT_HPP
