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
        virtual const NodeType nodeType();

        std::string name;
        std::shared_ptr<Type> type;

        virtual std::string toString();
        virtual bool operator ==(const TypeDefinition& other);
    };
  };
};

#endif // CEETAH_AST_TYPE_DEFINITION_HPP
