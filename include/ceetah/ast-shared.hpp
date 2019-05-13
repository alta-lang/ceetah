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
      CharacterLiteral,
      UnaryOperation,
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
      "CharacterLiteral",
      "UnaryOperation",
    };

    enum class TypeModifierFlag: uint8_t {
      None     = 0,
      Pointer  = 1 << 0,
      Constant = 1 << 1,
      Signed   = 1 << 2,
      Unsigned = 1 << 3,
      Long     = 1 << 4,
      Short    = 1 << 5,
    };

    enum class OperatorType: uint8_t {
      Addition,
      Subtraction,
      Multiplication,
      Division,
      Modulo,
      LeftShift,
      RightShift,
      BitwiseAnd,
      BitwiseOr,
      BitwiseXor,
      EqualTo,
      NotEqualTo,
      GreaterThan,
      LessThan,
      GreaterThanOrEqualTo,
      LessThanOrEqualTo,
      And,
      Or,
    };

    static const char* const OperatorType_operators[] = {
      "+",
      "-",
      "*",
      "/",
      "%",
      "<<",
      ">>",
      "&",
      "|",
      "^",
      "==",
      "!=",
      ">",
      "<",
      ">=",
      "<=",
      "&&",
      "||",
    };

    enum class UOperatorType: uint8_t {
      Not,
      Plus,
      Minus,
      PreIncrement,
      PostIncrement,
      PreDecrement,
      PostDecrement,
      BitwiseNot,
    };

    static const char* const UOperatorType_operators[] = {
      "!",
      "+",
      "-",
      "++",
      "++",
      "--",
      "--",
      "~",
    };

    enum class AssignmentType: uint8_t {
      Simple,
      Addition,
      Subtraction,
      Multiplication,
      Division,
      Modulo,
      LeftShift,
      RightShift,
      BitwiseAnd,
      BitwiseOr,
      BitwiseXor,
    };

    static const char* const AssignmentType_operators[] = {
      "=",
      "+=",
      "-=",
      "*=",
      "/=",
      "%=",
      "<<=",
      ">>=",
      "&=",
      "|=",
      "^=",
    };
  };
};

#endif // CEETAH_AST_SHARED_HPP
