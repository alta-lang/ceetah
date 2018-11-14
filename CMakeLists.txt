cmake_minimum_required(VERSION 3.10)

project(ceetah)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)
set(CMAKE_CXX_EXTENSIONS off)

add_library(ceetah
  "${PROJECT_SOURCE_DIR}/src/builder.cpp"
  "${PROJECT_SOURCE_DIR}/src/insertion-point.cpp"

  # AST nodes
  "${PROJECT_SOURCE_DIR}/src/ast/node.cpp"
  "${PROJECT_SOURCE_DIR}/src/ast/root-node.cpp"
  "${PROJECT_SOURCE_DIR}/src/ast/type.cpp"
  "${PROJECT_SOURCE_DIR}/src/ast/function-definition.cpp"
  "${PROJECT_SOURCE_DIR}/src/ast/statement.cpp"
  "${PROJECT_SOURCE_DIR}/src/ast/expression.cpp"
  "${PROJECT_SOURCE_DIR}/src/ast/return-directive.cpp"
  "${PROJECT_SOURCE_DIR}/src/ast/integer-literal.cpp"
  "${PROJECT_SOURCE_DIR}/src/ast/function-declaration.cpp"
  "${PROJECT_SOURCE_DIR}/src/ast/expression-statement.cpp"
  "${PROJECT_SOURCE_DIR}/src/ast/preprocessor-directive.cpp"
  "${PROJECT_SOURCE_DIR}/src/ast/conditional-preprocessor-directive.cpp"
  "${PROJECT_SOURCE_DIR}/src/ast/definitive-preprocessor-directive.cpp"
  "${PROJECT_SOURCE_DIR}/src/ast/inclusional-preprocessor-directive.cpp"
  "${PROJECT_SOURCE_DIR}/src/ast/variable-definition.cpp"
  "${PROJECT_SOURCE_DIR}/src/ast/accessor.cpp"
  "${PROJECT_SOURCE_DIR}/src/ast/fetch.cpp"
  "${PROJECT_SOURCE_DIR}/src/ast/variable-declaration.cpp"
  "${PROJECT_SOURCE_DIR}/src/ast/pointer.cpp"
  "${PROJECT_SOURCE_DIR}/src/ast/dereference.cpp"
  "${PROJECT_SOURCE_DIR}/src/ast/assignment.cpp"
  "${PROJECT_SOURCE_DIR}/src/ast/multi-expression.cpp"
  "${PROJECT_SOURCE_DIR}/src/ast/binary-operation.cpp"
  "${PROJECT_SOURCE_DIR}/src/ast/undefinitive-preprocessor-directive.cpp"
)
target_include_directories(ceetah PUBLIC "${PROJECT_SOURCE_DIR}/include")
