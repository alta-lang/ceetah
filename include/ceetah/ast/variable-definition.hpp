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
        virtual NodeType nodeType() const override;

        std::string name;
        std::shared_ptr<Type> type;
        std::shared_ptr<Expression> initializationExpression = nullptr;

        virtual std::shared_ptr<Node> clone() const override;
        void cloneTo(std::shared_ptr<Node> node) const;
        virtual std::string toString() const override;
        virtual bool operator ==(const VariableDefinition& other) const;
    };
  };
};

#endif // CEETAH_AST_VARIABLE_DEFINITION_HPP
