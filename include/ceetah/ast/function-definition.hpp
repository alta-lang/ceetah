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
        virtual const NodeType nodeType();

        std::string name;
        std::vector<std::tuple<std::string, std::shared_ptr<Type>>> parameters;
        std::shared_ptr<Type> returnType;
        std::vector<std::shared_ptr<Node>> body;

        virtual std::string toString();
        virtual bool operator ==(const FunctionDefinition& other);
    };
  };
};

#endif // CEETAH_AST_FUNCTION_DEFINITION_HPP
