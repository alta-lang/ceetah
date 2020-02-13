#ifndef CEETAH_AST_ACCESSOR_HPP
#define CEETAH_AST_ACCESSOR_HPP

#include "expression.hpp"
#include <string>

namespace Ceetah {
  namespace AST {
    class Accessor: public Expression {
      public:
        virtual NodeType nodeType() const override;

        std::shared_ptr<Expression> target;
        std::string query;

        virtual std::shared_ptr<Node> clone() const override;
        void cloneTo(std::shared_ptr<Node> node) const;
        virtual std::string toString() const override;
        virtual bool operator ==(const Accessor& other) const;

        std::shared_ptr<AST::Accessor> access(std::string subquery);
    };
  };
};

#endif // CEETAH_AST_ACCESSOR_HPP
