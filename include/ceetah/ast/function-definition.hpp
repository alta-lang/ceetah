#ifndef CEETAH_AST_FUNCTION_DEFINITION_HPP
#define CEETAH_AST_FUNCTION_DEFINITION_HPP

#include "statement.hpp"
#include "type.hpp"
#include <string>
#include <vector>

namespace Ceetah {
  namespace AST {
    class FunctionDefinition: public Statement {
      public:
        virtual NodeType nodeType() const override;

        std::string name;
        std::vector<std::tuple<std::string, std::shared_ptr<Type>>> parameters;
        std::shared_ptr<Type> returnType;
        std::vector<std::shared_ptr<Node>> body;
        bool isStatic = false;

        virtual std::shared_ptr<Node> clone() const override;
        void cloneTo(std::shared_ptr<Node> node) const;
        virtual std::string toString() const override;
        virtual bool operator ==(const FunctionDefinition& other) const;
    };
  };
};

#endif // CEETAH_AST_FUNCTION_DEFINITION_HPP
