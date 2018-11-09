#ifndef CEETAH_AST_FUNCTION_DECLARATION_HPP
#define CEETAH_AST_FUNCTION_DECLARATION_HPP

#include "statement.hpp"
#include "type.hpp"
#include <string>
#include <vector>

namespace Ceetah {
  namespace AST {
    class FunctionDeclaration: public Statement {
      public:
        virtual const NodeType nodeType();

        std::string name;
        std::vector<std::tuple<std::string, Type*>> parameters;
        Type* returnType;

        virtual std::string toString();
        virtual bool operator ==(const FunctionDeclaration& other);
    };
  };
};

#endif // CEETAH_AST_FUNCTION_DECLARATION_HPP