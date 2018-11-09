#ifndef CEETAH_AST_TYPE_HPP
#define CEETAH_AST_TYPE_HPP

#include "node.hpp"
#include <cinttypes>
#include <string>
#include <vector>

namespace Ceetah {
  namespace AST {
    class Type: public Node {
      public:
        virtual const NodeType nodeType();

        std::string name;
        std::vector<uint8_t> modifiers;

        Type(std::string name, std::vector<uint8_t> modifiers);

        /**
         * Full string representation of this type, as it would be seen in code
         */
        virtual std::string toString();
        virtual bool operator ==(const Type& other);
    };
  };
};

#endif // CEETAH_AST_TYPE_HPP