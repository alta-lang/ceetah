#ifndef CEETAH_AST_BLOCK_HPP
#define CEETAH_AST_BLOCK_HPP

#include "statement.hpp"
#include "expression.hpp"
#include <string>
#include <vector>

namespace Ceetah {
  namespace AST {
    class Block: public Statement {
      public:
        virtual NodeType nodeType() const override;

        std::vector<std::shared_ptr<Node>> statements;

        virtual std::shared_ptr<Node> clone() const override;
        void cloneTo(std::shared_ptr<Node> node) const;
        virtual std::string toStringWithIndent(std::string indent = "") const override;
        virtual bool operator ==(const Block& other) const;
    };
  };
};

#endif // CEETAH_AST_BLOCK_HPP
