#ifndef CEETAH_AST_VARIABLE_DECLARATION_HPP
#define CEETAH_AST_VARIABLE_DECLARATION_HPP

#include "statement.hpp"
#include "type.hpp"
#include <string>

namespace Ceetah {
  namespace AST {
    class VariableDeclaration: public Statement {
      public:
        virtual NodeType nodeType() const override;

        std::string name;
        std::shared_ptr<Type> type;

        virtual std::shared_ptr<Node> clone() const override;
        void cloneTo(std::shared_ptr<Node> node) const;
        virtual std::string toString() const override;
        virtual bool operator ==(const VariableDeclaration& other) const;
    };
  };
};

#endif // CEETAH_AST_VARIABLE_DECLARATION_HPP
