#ifndef CEETAH_AST_ARRAY_LITERAL_HPP
#define CEETAH_AST_ARRAY_LITERAL_HPP

#include "expression.hpp"
#include "type.hpp"
#include <vector>

namespace Ceetah {
  namespace AST {
    class ArrayLiteral: public Expression {
      public:
        virtual const NodeType nodeType();

        std::shared_ptr<AST::Type> type = nullptr;
        std::vector<std::shared_ptr<AST::Expression>> items;

        virtual std::string toString();
        virtual bool operator ==(const ArrayLiteral& other);
    };
  };
};

#endif /* CEETAH_AST_ARRAY_LITERAL_HPP */
