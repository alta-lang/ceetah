#ifndef CEETAH_AST_LABEL_HPP
#define CEETAH_AST_LABEL_HPP

#include "statement.hpp"
#include <string>
#include <vector>

namespace Ceetah {
  namespace AST {
    class Label: public Statement {
      public:
        virtual const NodeType nodeType();

        std::string label;

        virtual std::string toString();
        virtual bool operator ==(const Label& other);
    };
  };
};

#endif // CEETAH_AST_LABEL_HPP
