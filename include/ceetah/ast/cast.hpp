#ifndef CEETAH_AST_CAST_EXPRESSION_HPP
#define CEETAH_AST_CAST_EXPRESSION_HPP

#include "expression.hpp"
#include "type.hpp"
#include <string>
#include <vector>

namespace Ceetah {
  namespace AST {
    class Cast: public Expression {
    public:
      virtual const NodeType nodeType();

      std::shared_ptr<Expression> target;
      std::shared_ptr<Type> type;

      virtual std::string toString();
      virtual bool operator ==(const Cast& other);
    };
  };
};

#endif // CEETAH_AST_CAST_EXPRESSION_HPP
