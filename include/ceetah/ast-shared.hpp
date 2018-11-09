#ifndef CEETAH_AST_SHARED_HPP
#define CEETAH_AST_SHARED_HPP

#include <cinttypes>

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
    };

    enum class TypeModifierFlag: uint8_t {
      None     = 0,
      Pointer  = 1 << 0,
      Constant = 1 << 1,
    };
  };
};

#endif // CEETAH_AST_SHARED_HPP