#ifndef CEETAH_AST_VARIABLE_DEFINITION_HPP
#define CEETAH_AST_VARIABLE_DEFINITION_HPP

#include "statement.hpp"
#include "expression.hpp"
#include "type.hpp"
#include <string>

namespace Ceetah {
  namespace AST {
    class VariableDefinition: public Statement {
      public:
        virtual const NodeType nodeType();

        std::string name;
        Type* type;
        Expression* initializationExpression = nullptr;

        virtual std::string toString();
        virtual bool operator ==(const VariableDefinition& other);
    };
  };
};

#endif // CEETAH_AST_VARIABLE_DEFINITION_HPP