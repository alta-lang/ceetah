#ifndef CEETAH_AST_SHARED_HPP
#define CEETAH_AST_SHARED_HPP

#include <cinttypes>
#include <memory>

namespace Ceetah {
  namespace AST {
    enum class NodeType {
      Node,
      RootNode,
      Type,
      Statement,
      FunctionDefinition,
      Expression,
      ReturnDirective,
      IntegerLiteral,
      FunctionDeclaration,
      ExpressionStatement,
      PreprocessorDirective,
      ConditionalPreprocessorDirective,
      DefinitivePreprocessorDirective,
      InclusionalPreprocessorDirective,
      VariableDefinition,
      Accessor,
      Fetch,
      VariableDeclaration,
      Pointer,
      Dereference,
      Assignment,
      MultiExpression,
      BinaryOperation,
      UndefinitivePreprocessorDirective,
      FunctionCall,
      TypeDefinition,
      StringLiteral,
      ConditionalStatement,
      Block,
      TernaryOperation,
      ArrayLiteral,
      StructureDefinition,
      Sizeof,
      WhileLoop,
      Cast,
    };

    static const char* const NodeType_names[] = {
      "Node",
      "RootNode",
      "Type",
      "Statement",
      "FunctionDefinition",
      "Expression",
      "ReturnDirective",
      "IntegerLiteral",
      "FunctionDeclaration",
      "PreprocessorDirective",
      "ConditionalPreprocessorDirective",
      "DefinitivePreprocessorDirective",
      "InclusionalPreprocessorDirective",
      "VariableDefinition",
      "Accessor",
      "Fetch",
      "VariableDeclaration",
      "Pointer",
      "Dereference",
      "Assignment",
      "MultiExpression",
      "BinaryOperation",
      "UndefinitivePreprocessorDirective",
      "FunctionCall",
      "TypeDefinition",
      "StringLiteral",
      "ConditionalStatement",
      "Block",
      "TernaryOperation",
      "ArrayLiteral",
      "StructureDefinition",
      "Sizeof",
      "WhileLoop",
      "Cast",
    };

    enum class TypeModifierFlag: uint8_t {
      None     = 0,
      Pointer  = 1 << 0,
      Constant = 1 << 1,
    };

    enum class OperatorType: uint8_t {
      Addition,
      Subtraction,
      Multiplication,
      Division,
      EqualTo,
      NotEqualTo,
      GreaterThan,
      LessThan,
      GreaterThanOrEqualTo,
      LessThanOrEqualTo,
    };

    static const char* const OperatorType_operators[] = {
      "+",
      "-",
      "*",
      "/",
      "==",
      "!=",
      ">",
      "<",
      ">=",
      "<=",
    };
  };
};

#endif // CEETAH_AST_SHARED_HPP
