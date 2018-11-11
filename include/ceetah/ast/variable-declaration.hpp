#ifndef CEETAH_AST_VARIABLE_DECLARATION_HPP
#define CEETAH_AST_VARIABLE_DECLARATION_HPP

#include "statement.hpp"
#include "type.hpp"
#include <string>

namespace Ceetah {
  namespace AST {
    class VariableDeclaration: public Statement {
      public:
        virtual const NodeType nodeType();

        std::string name;
        std::shared_ptr<Type> type;

        virtual std::string toString();
        virtual bool operator ==(const VariableDeclaration& other);
    };
  };
};

#endif // CEETAH_AST_VARIABLE_DECLARATION_HPP
