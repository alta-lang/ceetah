#ifndef CEETAH_AST_NODE_HPP
#define CEETAH_AST_NODE_HPP

#include "../ast-shared.hpp"
#include <string>
#include <stdexcept>

#define CEETAH_AST_CLONE_CHILD(expr) node->expr = expr ? std::dynamic_pointer_cast<decltype(node->expr)::element_type>(expr->clone()) : nullptr;\
  if (node->expr) {\
    node->expr->parent = node;\
  }
#define CEETAH_AST_CLONE_CHILDREN(expr) for (size_t i = 0; i < expr.size(); ++i) {\
    node->expr.emplace_back(expr[i] ? std::dynamic_pointer_cast<decltype(node->expr)::value_type::element_type>(expr[i]->clone()) : nullptr);\
    if (node->expr[i]) {\
      node->expr[i]->parent = node;\
    }\
  }

namespace Ceetah {
  namespace AST {
    extern bool newlineOnExpressions;

    class Node {
      public:
        virtual NodeType nodeType() const;

        std::weak_ptr<Node> parent;
        std::string preComment;
        std::string postComment;

        virtual std::shared_ptr<Node> clone() const;
        void cloneTo(std::shared_ptr<Node> node) const;
        virtual std::string toString() const;
        virtual bool operator ==(const Node& other) const;
        virtual bool operator !=(const Node& other);
    };
  };
};

#endif // CEETAH_AST_NODE_HPP
