#ifndef CEETAH_AST_TYPE_DEFINITION_HPP
#define CEETAH_AST_TYPE_DEFINITION_HPP

#include "statement.hpp"
#include "type.hpp"
#include <string>
#include <vector>

namespace Ceetah {
  namespace AST {
    class TypeDefinition: public Statement {
      public:
        virtual NodeType nodeType() const override;

        std::string name;
        std::shared_ptr<Type> type;

        virtual std::shared_ptr<Node> clone() const override;
        void cloneTo(std::shared_ptr<Node> node) const;
        virtual std::string toStringWithIndent(std::string indent = "") const override;
        virtual bool operator ==(const TypeDefinition& other) const;
    };
  };
};

#endif // CEETAH_AST_TYPE_DEFINITION_HPP
