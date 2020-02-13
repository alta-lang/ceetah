#ifndef CEETAH_AST_SIZEOF_HPP
#define CEETAH_AST_SIZEOF_HPP

#include "expression.hpp"
#include "type.hpp"
#include <string>
#include <vector>

namespace Ceetah {
  namespace AST {
    class Sizeof: public Expression {
      public:
        virtual NodeType nodeType() const override;

        std::shared_ptr<Type> type;

        virtual std::shared_ptr<Node> clone() const override;
        void cloneTo(std::shared_ptr<Node> node) const;
        virtual std::string toString() const override;
        virtual bool operator ==(const Sizeof& other) const;
    };
  };
};

#endif // CEETAH_AST_SIZEOF_HPP
