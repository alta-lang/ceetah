#ifndef CEETAH_AST_ARRAY_LITERAL_HPP
#define CEETAH_AST_ARRAY_LITERAL_HPP

#include "expression.hpp"
#include "type.hpp"
#include <vector>

namespace Ceetah {
  namespace AST {
    class ArrayLiteral: public Expression {
      public:
        virtual NodeType nodeType() const override;

        std::shared_ptr<AST::Type> type = nullptr;
        std::vector<std::shared_ptr<AST::Expression>> items;

        virtual std::shared_ptr<Node> clone() const override;
        void cloneTo(std::shared_ptr<Node> node) const;
        virtual std::string toString() const override;
        virtual bool operator ==(const ArrayLiteral& other) const;
    };
  };
};

#endif /* CEETAH_AST_ARRAY_LITERAL_HPP */
