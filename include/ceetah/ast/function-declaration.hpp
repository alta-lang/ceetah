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
        virtual NodeType nodeType() const override;

        std::string name;
        std::vector<std::tuple<std::string, std::shared_ptr<Type>>> parameters;
        std::shared_ptr<Type> returnType;
        bool vararg = false;

        virtual std::shared_ptr<Node> clone() const override;
        void cloneTo(std::shared_ptr<Node> node) const;
        virtual std::string toStringWithIndent(std::string indent = "") const override;
        virtual bool operator ==(const FunctionDeclaration& other) const;
    };
  };
};

#endif // CEETAH_AST_FUNCTION_DECLARATION_HPP
