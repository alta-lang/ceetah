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
        virtual const NodeType nodeType();

        std::vector<std::shared_ptr<Node>> statements;

        virtual std::string toString();
        virtual bool operator ==(const Block& other);
    };
  };
};

#endif // CEETAH_AST_BLOCK_HPP
