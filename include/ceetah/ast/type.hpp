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
        virtual NodeType nodeType() const override;

        bool isFunction = false;
        bool isStructure = false;
        std::shared_ptr<Type> returnType;
        std::vector<std::shared_ptr<Type>> parameters;
        std::string name;
        std::vector<uint8_t> modifiers;

        // for use with `modifiers`; each index corresponds to the same index in `modifiers`
        // 0 = no array
        // SIZE_MAX = automatic size array
        // 1..SIZE_MAX = fixed size array
        size_t arraySize = 0;

        Type();
        Type(std::string name, std::vector<uint8_t> modifiers, bool isStructure = false);
        Type(std::shared_ptr<Type> returnType, std::vector<std::shared_ptr<Type>> parameters, std::vector<uint8_t> modifiers);

        virtual std::shared_ptr<Node> clone() const override;
        void cloneTo(std::shared_ptr<Node> node) const;
        /**
         * Full string representation of this type, as it would be seen in code
         */
        virtual std::string toString() const override;
        virtual bool operator ==(const Type& other) const;
    };
  };
};

#endif // CEETAH_AST_TYPE_HPP
