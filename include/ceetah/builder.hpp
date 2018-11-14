#ifndef CEETAH_BUILDER_HPP
#define CEETAH_BUILDER_HPP

#include "ast.hpp"
#include <string>
#include <vector>
#include <cinttypes>
#include <exception>
#include <memory>

namespace Ceetah {
  class InsertionException: public std::runtime_error {
    public:
      InsertionException();
  };
  class InvalidInsertionNodeException: public InsertionException {};

  class UnimplementedException: public std::runtime_error {
    public:
      UnimplementedException(std::string name);
  };

  class InsertionPoint {
    public:
      std::shared_ptr<AST::Node> node;
      std::shared_ptr<InsertionPoint> parent = nullptr;
      size_t index = 0;

      InsertionPoint(std::shared_ptr<AST::Node> node);
      InsertionPoint(std::shared_ptr<InsertionPoint> parent, std::shared_ptr<AST::Node> node);

      size_t insert(std::shared_ptr<AST::Node> node, bool movePointer = true);
      [[deprecated("Ceetah::InsertionPoint.insertBefore(std::shared_ptr<Ceetah::AST::Node>, bool?) is currently unimplemented")]]
      size_t insertBefore(std::shared_ptr<AST::Node> node, bool movePointer = true);
      /**
       * Please note that `insertBefore(node, refPoint)` is much more computationally expensive than `insertBefore(node)`
       */
      [[deprecated("Ceetah::InsertionPoint.insertBefore(std::shared_ptr<Ceetah::AST::Node>, std::shared_ptr<Ceetah::AST::Node>, bool?) is currently unimplemented")]]
      size_t insertBefore(std::shared_ptr<AST::Node> node, std::shared_ptr<AST::Node> referencePoint, bool movePointer = true);
      size_t insertAfter(std::shared_ptr<AST::Node> node, bool movePointer = true);
      /**
       * Please note that `insertAfter(node, refPoint)` is much more computationally expensive than `insertAfter(node)`
       */
      [[deprecated("Ceetah::InsertionPoint.insertAfter(Ceetah::AST::Node*, Ceetah::AST::Node*, bool?) is currently unimplemented")]]
      size_t insertAfter(std::shared_ptr<AST::Node> node, std::shared_ptr<AST::Node> referencePoint, bool movePointer = true);

      void scrollToStart();
      void scrollToEnd();
      void scrollTo(std::shared_ptr<AST::Node> node);

      std::vector<std::shared_ptr<AST::Node>> container();
      size_t containerLength();

      void moveBackward();
      void moveForward();

      size_t save();
      void restore(size_t position);
  };

  /**
   * @brief Awesome little helper class for build a C AST from scratch
   * 
   * Builders are the best! Previous iterations of Alta's C transpiliation logic have had
   * lots of problems when it comes to generating C code properly, especially when a single
   * Alta expression translates into one or more C statements followed by an expression.
   * 
   * Step one in fixing this problem was to separate the C AST generation logic into its own library.
   * Thus, Ceetah was born. Step two in this fixing this problem is the way that builders and
   * insertion points are set up. If an `insert` call occurs while handling another `insert` call,
   * the second call is fully executed before the first. e.g.
   *     sourceCode.insertExpressionStatement(somethingThatReturnsAnExpression());
   * If `somethingThatReturnsAnExpression` inserts something, it will be inserted before the new expression
   * statement is inserted
   */
  class Builder {
    // make sure `root` comes before `insertionPoint`, we need it to initialize it in proper
    // order (otherwise, `insertionPoint` ends up with a garbage node)
    public:
      std::shared_ptr<AST::RootNode> root;
      std::shared_ptr<InsertionPoint> insertionPoint;

      Builder(std::shared_ptr<AST::RootNode> root);

      std::shared_ptr<AST::Type> createType(std::string name, std::vector<uint8_t> modifiers);
      std::shared_ptr<AST::Type> createType(std::string name, std::vector<std::vector<AST::TypeModifierFlag>> modifiers);
      std::shared_ptr<AST::IntegerLiteral> createIntegerLiteral(std::string raw);
      std::shared_ptr<AST::IntegerLiteral> createIntegerLiteral(int64_t integer);
      std::shared_ptr<AST::Fetch> createFetch(std::string query);
      std::shared_ptr<AST::Accessor> createAccessor(std::shared_ptr<AST::Expression> target, std::string query);
      std::shared_ptr<AST::Accessor> createAccessor(std::string target, std::string query);
      std::shared_ptr<AST::Pointer> createPointer(std::shared_ptr<AST::Expression> target);
      std::shared_ptr<AST::Dereference> createDereference(std::shared_ptr<AST::Expression> target);
      std::shared_ptr<AST::Assignment> createAssignment(std::shared_ptr<AST::Expression> target, std::shared_ptr<AST::Expression> value);
      std::shared_ptr<AST::MultiExpression> createMultiExpression(std::vector<std::shared_ptr<AST::Expression>> expressions);
      std::shared_ptr<AST::BinaryOperation> createBinaryOperation(AST::OperatorType operation, std::shared_ptr<AST::Expression> left, std::shared_ptr<AST::Expression> right);

      void insert(std::shared_ptr<AST::Node> node, bool enter = false);
      void insertAfter(std::shared_ptr<AST::Node> node, bool enter = false);

      void insertFunctionDeclaration(std::string name, std::vector<std::tuple<std::string, std::shared_ptr<AST::Type>>> parameters, std::shared_ptr<AST::Type> returnType);
      void insertFunctionDefinition(std::string name, std::vector<std::tuple<std::string, std::shared_ptr<AST::Type>>> parameters, std::shared_ptr<AST::Type> returnType);
      void insertReturnDirective(std::shared_ptr<AST::Expression> value = nullptr);
      void insertPreprocessorConditional(std::string test);
      void insertPreprocessorInclusion(std::string whatToInclude, AST::InclusionType type = AST::InclusionType::Local);
      void insertVariableDefinition(std::shared_ptr<AST::Type> type, std::string name, std::shared_ptr<AST::Expression> initializer = nullptr);
      void insertVariableDeclaration(std::shared_ptr<AST::Type> type, std::string name);
      void insertPreprocessorDefinition(std::string whatToDefine, std::string value = "");
      void insertExpressionStatement(std::shared_ptr<AST::Expression> expr);
      void insertPreprocessorUndefinition(std::string whatToUndefine);

      void enterInsertionPoint();
      void enterInsertionPoint(size_t index);
      [[deprecated("Ceetah::Builder.enterInsertionPoint(std::shared_ptr<Ceetah::AST::Node>) is currently unimplemented")]]
      void enterInsertionPoint(std::shared_ptr<AST::Node> insertionTarget);

      void exitInsertionPoint();
  };
};

#endif // CEETAH_BUILDER_HPP
