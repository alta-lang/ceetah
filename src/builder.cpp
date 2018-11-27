#include "../include/ceetah/builder.hpp"

Ceetah::UnimplementedException::UnimplementedException(std::string message):
  std::runtime_error("Error, functionality unimplemented: " + message)
  {};

Ceetah::Builder::Builder(std::shared_ptr<AST::RootNode> _root):
  root(_root),
  insertionPoint(std::make_shared<InsertionPoint>(root))
  {};

std::shared_ptr<Ceetah::AST::Type> Ceetah::Builder::createType(std::string name, std::vector<uint8_t> modifiers) {
  return std::make_shared<AST::Type>(name, modifiers);
};
std::shared_ptr<Ceetah::AST::Type> Ceetah::Builder::createType(std::string name, std::vector<std::vector<Ceetah::AST::TypeModifierFlag>> modifiers) {
  std::vector<uint8_t> flagModifiers;
  for (auto& modifierLevel: modifiers) {
    uint8_t level = 0;
    for (auto& modifier: modifierLevel) {
      level |= (uint8_t)modifier;
    }
    flagModifiers.push_back(level);
  }
  return createType(name, flagModifiers);
};
std::shared_ptr<Ceetah::AST::Type> Ceetah::Builder::createType(std::shared_ptr<Ceetah::AST::Type> returnType, std::vector<std::shared_ptr<Ceetah::AST::Type>> parameters, std::vector<uint8_t> modifiers) {
  return std::make_shared<AST::Type>(returnType, parameters, modifiers);
};
std::shared_ptr<Ceetah::AST::Type> Ceetah::Builder::createType(std::shared_ptr<Ceetah::AST::Type> returnType, std::vector<std::shared_ptr<Ceetah::AST::Type>> parameters, std::vector<std::vector<Ceetah::AST::TypeModifierFlag>> modifiers) {
  std::vector<uint8_t> flagModifiers;
  for (auto& modifierLevel: modifiers) {
    uint8_t level = 0;
    for (auto& modifier: modifierLevel) {
      level |= (uint8_t)modifier;
    }
    flagModifiers.push_back(level);
  }
  return createType(returnType, parameters, flagModifiers);
};
std::shared_ptr<Ceetah::AST::IntegerLiteral> Ceetah::Builder::createIntegerLiteral(std::string raw) {
  auto intLit = std::make_shared<AST::IntegerLiteral>();
  intLit->raw = raw;
  return intLit;
};
std::shared_ptr<Ceetah::AST::IntegerLiteral> Ceetah::Builder::createIntegerLiteral(int64_t integer) {
  return createIntegerLiteral(std::to_string(integer));
};
std::shared_ptr<Ceetah::AST::Fetch> Ceetah::Builder::createFetch(std::string query) {
  auto fetch = std::make_shared<AST::Fetch>();
  fetch->query = query;
  return fetch;
};
std::shared_ptr<Ceetah::AST::Accessor> Ceetah::Builder::createAccessor(std::shared_ptr<Ceetah::AST::Expression> target, std::string query) {
  auto acc = std::make_shared<AST::Accessor>();
  acc->target = target;
  acc->query = query;
  return acc;
};
std::shared_ptr<Ceetah::AST::Accessor> Ceetah::Builder::createAccessor(std::string target, std::string query) {
  return createAccessor(createFetch(target), query);
};
std::shared_ptr<Ceetah::AST::Pointer> Ceetah::Builder::createPointer(std::shared_ptr<Ceetah::AST::Expression> target) {
  auto pointer = std::make_shared<AST::Pointer>();
  pointer->target = target;
  return pointer;
};
std::shared_ptr<Ceetah::AST::Dereference> Ceetah::Builder::createDereference(std::shared_ptr<Ceetah::AST::Expression> target) {
  auto deref = std::make_shared<AST::Dereference>();
  deref->target = target;
  return deref;
};
std::shared_ptr<Ceetah::AST::Assignment> Ceetah::Builder::createAssignment(std::shared_ptr<Ceetah::AST::Expression> target, std::shared_ptr<Ceetah::AST::Expression> value) {
  auto assign = std::make_shared<AST::Assignment>();
  assign->target = target;
  assign->value = value;
  return assign;
};
std::shared_ptr<Ceetah::AST::MultiExpression> Ceetah::Builder::createMultiExpression(std::vector<std::shared_ptr<Ceetah::AST::Expression>> expressions) {
  auto multi = std::make_shared<AST::MultiExpression>();
  multi->expressions = expressions;
  return multi;
};
std::shared_ptr<Ceetah::AST::BinaryOperation> Ceetah::Builder::createBinaryOperation(Ceetah::AST::OperatorType operation, std::shared_ptr<Ceetah::AST::Expression> left, std::shared_ptr<Ceetah::AST::Expression> right) {
  auto binOp = std::make_shared<AST::BinaryOperation>();
  binOp->type = operation;
  binOp->left = left;
  binOp->right = right;
  return binOp;
};
std::shared_ptr<Ceetah::AST::FunctionCall> Ceetah::Builder::createFunctionCall(std::shared_ptr<Ceetah::AST::Expression> target, std::vector<std::shared_ptr<Ceetah::AST::Expression>> arguments) {
  auto funcCall = std::make_shared<AST::FunctionCall>();
  funcCall->target = target;
  funcCall->arguments = arguments;
  return funcCall;
};
std::shared_ptr<Ceetah::AST::StringLiteral> Ceetah::Builder::createStringLiteral(std::string value) {
  auto strLit = std::make_shared<AST::StringLiteral>();
  strLit->value = value;
  return strLit;
};

void Ceetah::Builder::insert(std::shared_ptr<Ceetah::AST::Node> node, bool enter) {
  auto pos = insertionPoint->insert(node);
  if (enter) {
    enterInsertionPoint(pos);
  }
};
void Ceetah::Builder::insertAfter(std::shared_ptr<Ceetah::AST::Node> node, bool enter) {
  auto pos = insertionPoint->insertAfter(node);
  if (enter) {
    enterInsertionPoint(pos);
  }
};

void Ceetah::Builder::insertFunctionDeclaration(std::string name, std::vector<std::tuple<std::string, std::shared_ptr<AST::Type>>> parameters, std::shared_ptr<AST::Type> returnType) {
  auto funcDef = std::make_shared<AST::FunctionDeclaration>();
  funcDef->name = name;
  funcDef->parameters = parameters;
  funcDef->returnType = returnType;
  insert(funcDef);
};
void Ceetah::Builder::insertFunctionDefinition(std::string name, std::vector<std::tuple<std::string, std::shared_ptr<Ceetah::AST::Type>>> parameters, std::shared_ptr<Ceetah::AST::Type> returnType) {
  auto func = std::make_shared<AST::FunctionDefinition>();
  func->name = name;
  func->parameters = parameters;
  func->returnType = returnType;
  insert(func, true);
};
void Ceetah::Builder::insertReturnDirective(std::shared_ptr<AST::Expression> value) {
  auto retDir = std::make_shared<AST::ReturnDirective>();
  retDir->value = value;
  insert(retDir);
};
void Ceetah::Builder::insertPreprocessorConditional(std::string test) {
  auto cond = std::make_shared<AST::ConditionalPreprocessorDirective>();
  cond->test = test;
  insert(cond, true);
};
void Ceetah::Builder::insertPreprocessorInclusion(std::string whatToInclude, AST::InclusionType type) {
  auto incl = std::make_shared<AST::InclusionalPreprocessorDirective>();
  incl->includeQuery = whatToInclude;
  incl->type = type;
  insert(incl);
};
void Ceetah::Builder::insertVariableDefinition(std::shared_ptr<AST::Type> type, std::string name, std::shared_ptr<AST::Expression> initializer) {
  auto varDef = std::make_shared<AST::VariableDefinition>();
  varDef->type = type;
  varDef->name = name;
  varDef->initializationExpression = initializer;
  insert(varDef);
};
void Ceetah::Builder::insertVariableDeclaration(std::shared_ptr<AST::Type> type, std::string name) {
  auto varDecl = std::make_shared<AST::VariableDeclaration>();
  varDecl->type = type;
  varDecl->name = name;
  insert(varDecl);
};
void Ceetah::Builder::insertPreprocessorDefinition(std::string whatToDefine, std::string value) {
  auto def = std::make_shared<AST::DefinitivePreprocessorDirective>();
  def->definition = whatToDefine;
  def->value = value;
  insert(def);
};
void Ceetah::Builder::insertExpressionStatement(std::shared_ptr<Ceetah::AST::Expression> expr) {
  auto exprStmt = std::make_shared<AST::ExpressionStatement>();
  exprStmt->expression = expr;
  insert(exprStmt);
};
void Ceetah::Builder::insertPreprocessorUndefinition(std::string whatToUndefine) {
  auto undef = std::make_shared<AST::UndefinitivePreprocessorDirective>();
  undef->undefinition = whatToUndefine;
  insert(undef);
};
void Ceetah::Builder::insertTypeDefinition(std::string name, std::shared_ptr<Ceetah::AST::Type> type) {
  auto def = std::make_shared<AST::TypeDefinition>();
  def->name = name;
  def->type = type;
  insert(def);
};

void Ceetah::Builder::enterInsertionPoint() {
  return enterInsertionPoint(insertionPoint->index);
};

void Ceetah::Builder::enterInsertionPoint(size_t index) {
  AST::NodeType nodeType = insertionPoint->node->nodeType();
  if (nodeType == AST::NodeType::RootNode) {
    auto root = std::dynamic_pointer_cast<AST::RootNode>(insertionPoint->node);
    insertionPoint = std::make_shared<InsertionPoint>(insertionPoint, root->statements[index]);
  } else if (nodeType == AST::NodeType::FunctionDefinition) {
    auto func = std::dynamic_pointer_cast<AST::FunctionDefinition>(insertionPoint->node);
    insertionPoint = std::make_shared<InsertionPoint>(insertionPoint, func->body[index]);
  } else if (nodeType == AST::NodeType::ConditionalPreprocessorDirective) {
    auto cond = std::dynamic_pointer_cast<AST::ConditionalPreprocessorDirective>(insertionPoint->node);
    insertionPoint = std::make_shared<InsertionPoint>(insertionPoint, cond->nodes[index]);
  }
};

// <not-implemented>
void Ceetah::Builder::enterInsertionPoint(std::shared_ptr<AST::Node> insertionTarget) {
  throw UnimplementedException("Ceetah::Builder::enterInsertionPoint(std::shared_ptr<AST::Node>)");
};
// </not-implemented>

void Ceetah::Builder::exitInsertionPoint() {
  if (insertionPoint->parent != nullptr) {
    insertionPoint = insertionPoint->parent;
  }
};
