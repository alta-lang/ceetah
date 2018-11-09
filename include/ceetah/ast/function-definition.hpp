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
        std::vector<std::tuple<std::string, Type*>> parameters;
        Type* returnType;
        std::vector<Node*> body;

        virtual std::string toString();
        virtual bool operator ==(const FunctionDefinition& other);
    };
  };
};

#endif // CEETAH_AST_FUNCTION_DEFINITION_HPP