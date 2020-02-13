#ifndef CEETAH_AST_STRUCTURE_DEFINITION_HPP
#define CEETAH_AST_STRUCTURE_DEFINITION_HPP

#include "statement.hpp"
#include "type.hpp"
#include <vector>

namespace Ceetah {
  namespace AST {
    class StructureDefinition: public Statement {
      public:
        virtual NodeType nodeType() const override;

        std::string name;
        std::vector<std::pair<std::string, std::shared_ptr<Type>>> members;
        bool packed = false;

        virtual std::shared_ptr<Node> clone() const override;
        void cloneTo(std::shared_ptr<Node> node) const;
        virtual std::string toString() const override;
        virtual bool operator ==(const StructureDefinition& other) const;
    };
  };
};

#endif // CEETAH_AST_STRUCTURE_DEFINITION_HPP
