#ifndef CEETAH_AST_LABEL_HPP
#define CEETAH_AST_LABEL_HPP

#include "statement.hpp"
#include <string>
#include <vector>

namespace Ceetah {
  namespace AST {
    class Label: public Statement {
      public:
        virtual NodeType nodeType() const override;

        std::string label;

        virtual std::shared_ptr<Node> clone() const override;
        void cloneTo(std::shared_ptr<Node> node) const;
        virtual std::string toStringWithIndent(std::string indent = "") const override;
        virtual bool operator ==(const Label& other) const;
    };
  };
};

#endif // CEETAH_AST_LABEL_HPP
