cmake_minimum_required(VERSION 3.10)

project(ceetah)

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
  "${PROJECT_SOURCE_DIR}/src/ast/function-call.cpp"
  "${PROJECT_SOURCE_DIR}/src/ast/type-definition.cpp"
  "${PROJECT_SOURCE_DIR}/src/ast/string-literal.cpp"
  "${PROJECT_SOURCE_DIR}/src/ast/conditional-statement.cpp"
  "${PROJECT_SOURCE_DIR}/src/ast/block.cpp"
  "${PROJECT_SOURCE_DIR}/src/ast/ternary-operation.cpp"
  "${PROJECT_SOURCE_DIR}/src/ast/array-literal.cpp"
  "${PROJECT_SOURCE_DIR}/src/ast/structure-definition.cpp"
  "${PROJECT_SOURCE_DIR}/src/ast/sizeof.cpp"
  "${PROJECT_SOURCE_DIR}/src/ast/while-loop.cpp"
  "${PROJECT_SOURCE_DIR}/src/ast/cast.cpp"
  "${PROJECT_SOURCE_DIR}/src/ast/character-literal.cpp"
  "${PROJECT_SOURCE_DIR}/src/ast/unary-operation.cpp"
  "${PROJECT_SOURCE_DIR}/src/ast/goto-directive.cpp"
  "${PROJECT_SOURCE_DIR}/src/ast/label.cpp"
)
target_include_directories(ceetah PUBLIC "${PROJECT_SOURCE_DIR}/include")

# credit to Austin Lasher (https://medium.com/@alasher/colored-c-compiler-output-with-ninja-clang-gcc-10bfe7f2b949)
option(FORCE_COLORED_OUTPUT "Always produce ANSI-colored output (GNU/Clang only)." TRUE)
if(${FORCE_COLORED_OUTPUT})
  if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    target_compile_options(ceetah PRIVATE -fdiagnostics-color=always)
  elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "AppleClang")
    target_compile_options(ceetah PRIVATE -fcolor-diagnostics)
  endif()
endif()

set_target_properties(ceetah
  PROPERTIES
  CXX_STANDARD 17
  CXX_STANDARD_REQUIRED on
  CXX_EXTENSIONS off
  ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
  LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# install files
install(TARGETS ceetah
  ARCHIVE DESTINATION lib
)

install(DIRECTORY "${PROJECT_SOURCE_DIR}/include/"
  DESTINATION include
  FILES_MATCHING PATTERN "*"
)
