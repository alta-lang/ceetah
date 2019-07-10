#ifndef CEETAH_AST_STRUCTURE_DEFINITION_HPP
#define CEETAH_AST_STRUCTURE_DEFINITION_HPP

#include "statement.hpp"
#include "type.hpp"
#include <vector>

namespace Ceetah {
  namespace AST {
    class StructureDefinition: public Statement {
      public:
        virtual const NodeType nodeType();

        std::string name;
        std::vector<std::pair<std::string, std::shared_ptr<Type>>> members;
        bool packed = false;

        virtual std::string toString();
        virtual bool operator ==(const StructureDefinition& other);
    };
  };
};

#endif // CEETAH_AST_STRUCTURE_DEFINITION_HPP
