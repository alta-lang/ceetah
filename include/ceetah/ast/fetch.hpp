#ifndef CEETAH_AST_FETCH_HPP
#define CEETAH_AST_FETCH_HPP

#include "expression.hpp"
#include <string>

namespace Ceetah {
  namespace AST {
    class Fetch: public Expression {
      public:
        virtual NodeType nodeType() const override;

        std::string query;

        virtual std::shared_ptr<Node> clone() const override;
        void cloneTo(std::shared_ptr<Node> node) const;
        virtual std::string toString() const override;
        virtual bool operator ==(const Fetch& other) const;
    };
  };
};

#endif // CEETAH_AST_FETCH_HPP
