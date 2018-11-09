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
      AST::Node* node;
      std::weak_ptr<InsertionPoint> parent;
      size_t index = 0;

      InsertionPoint(AST::Node* node);
      InsertionPoint(std::shared_ptr<InsertionPoint> parent, AST::Node* node);

      size_t insert(AST::Node* node, bool movePointer = true);
      [[deprecated("Ceetah::InsertionPoint.insertBefore(Ceetah::AST::Node*, bool?) is currently unimplemented")]]
      size_t insertBefore(AST::Node* node, bool movePointer = true);
      /**
       * Please note that `insertBefore(node, refPoint)` is much more computationally expensive than `insertBefore(node)`
       */
      [[deprecated("Ceetah::InsertionPoint.insertBefore(Ceetah::AST::Node*, Ceetah::AST::Node*, bool?) is currently unimplemented")]]
      size_t insertBefore(AST::Node* node, AST::Node* referencePoint, bool movePointer = true);
      size_t insertAfter(AST::Node* node, bool movePointer = true);
      /**
       * Please note that `insertAfter(node, refPoint)` is much more computationally expensive than `insertAfter(node)`
       */
      [[deprecated("Ceetah::InsertionPoint.insertAfter(Ceetah::AST::Node*, Ceetah::AST::Node*, bool?) is currently unimplemented")]]
      size_t insertAfter(AST::Node* node, AST::Node* referencePoint, bool movePointer = true);

      void scrollToStart();
      void scrollToEnd();
      void scrollTo(AST::Node* node);

      std::vector<AST::Node*> container();
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
      AST::RootNode* root;
      //AST::RootNode* headerRoot;
      std::shared_ptr<InsertionPoint> insertionPoint;
      //std::shared_ptr<InsertionPoint> headerIP;

      Builder(AST::RootNode* root/*, AST::RootNode* headerRoot*/);

      AST::Type* createType(std::string name, std::vector<uint8_t> modifiers);
      AST::Type* createType(std::string name, std::vector<std::vector<AST::TypeModifierFlag>> modifiers);
      AST::IntegerLiteral* createIntegerLiteral(std::string raw);
      AST::IntegerLiteral* createIntegerLiteral(int64_t integer);
      AST::Fetch* createFetch(std::string query);
      AST::Accessor* createAccessor(AST::Expression* target, std::string query);
      AST::Accessor* createAccessor(std::string target, std::string query);

      void insert(AST::Node* node, bool enter = false);
      void insertAfter(AST::Node* node, bool enter = false);

      void insertFunctionDeclaration(std::string name, std::vector<std::tuple<std::string, AST::Type*>> parameters, AST::Type* returnType);
      void insertFunctionDefinition(std::string name, std::vector<std::tuple<std::string, AST::Type*>> parameters, AST::Type* returnType);
      void insertReturnDirective(AST::Expression* value);
      void insertPreprocessorConditional(std::string test);
      void insertPreprocessorInclusion(std::string whatToInclude, AST::InclusionType type = AST::InclusionType::Local);
      void insertVariableDefinition(AST::Type* type, std::string name, AST::Expression* initializer = nullptr);
      void insertVariableDeclaration(AST::Type* type, std::string name);
      void insertPreprocessorDefinition(std::string whatToDefine, std::string value = "");
      void insertExpressionStatement(AST::Expression* expr);

      void enterInsertionPoint();
      void enterInsertionPoint(size_t index);
      
      [[deprecated("Ceetah::Builder.enterInsertionPoint(Ceetah::AST::Node*) is currently unimplemented")]]
      void enterInsertionPoint(AST::Node* insertionTarget);

      void exitInsertionPoint();
  };
};

#endif // CEETAH_BUILDER_HPP