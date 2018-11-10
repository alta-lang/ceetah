#include "../include/ceetah/builder.hpp"

Ceetah::UnimplementedException::UnimplementedException(std::string message):
  std::runtime_error("Error, functionality unimplemented: " + message)
  {};

Ceetah::Builder::Builder(AST::RootNode* _root/*, AST::RootNode* _headerRoot*/):
  root(_root),
  //headerRoot(_headerRoot),
  insertionPoint(std::make_shared<InsertionPoint>(root))//,
  //headerIP(std::make_shared<InsertionPoint>(headerRoot))
  {};

Ceetah::AST::Type* Ceetah::Builder::createType(std::string name, std::vector<uint8_t> modifiers) {
  return new AST::Type(name, modifiers);
};
Ceetah::AST::Type* Ceetah::Builder::createType(std::string name, std::vector<std::vector<Ceetah::AST::TypeModifierFlag>> modifiers) {
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
Ceetah::AST::IntegerLiteral* Ceetah::Builder::createIntegerLiteral(std::string raw) {
  auto* intLit = new AST::IntegerLiteral();
  intLit->raw = raw;
  return intLit;
};
Ceetah::AST::IntegerLiteral* Ceetah::Builder::createIntegerLiteral(int64_t integer) {
  return createIntegerLiteral(std::to_string(integer));
};
Ceetah::AST::Fetch* Ceetah::Builder::createFetch(std::string query) {
  auto fetch = new AST::Fetch();
  fetch->query = query;
  return fetch;
};
Ceetah::AST::Accessor* Ceetah::Builder::createAccessor(Ceetah::AST::Expression* target, std::string query) {
  auto acc = new AST::Accessor();
  acc->target = target;
  acc->query = query;
  return acc;
};
Ceetah::AST::Accessor* Ceetah::Builder::createAccessor(std::string target, std::string query) {
  return createAccessor(createFetch(target), query);
};

void Ceetah::Builder::insert(Ceetah::AST::Node* node, bool enter) {
  auto pos = insertionPoint->insert(node);
  if (enter) {
    enterInsertionPoint(pos);
  }
};
void Ceetah::Builder::insertAfter(Ceetah::AST::Node* node, bool enter) {
  auto pos = insertionPoint->insertAfter(node);
  if (enter) {
    enterInsertionPoint(pos);
  }
};

void Ceetah::Builder::insertFunctionDeclaration(std::string name, std::vector<std::tuple<std::string, AST::Type*>> parameters, AST::Type* returnType) {
  auto funcDef = new AST::FunctionDeclaration();
  funcDef->name = name;
  funcDef->parameters = parameters;
  funcDef->returnType = returnType;
  /*headerIP->*/insert(funcDef);
};
void Ceetah::Builder::insertFunctionDefinition(std::string name, std::vector<std::tuple<std::string, Ceetah::AST::Type*>> parameters, Ceetah::AST::Type* returnType) {
  auto func = new AST::FunctionDefinition();
  
  // some people consider multi-assignment/batch-assignment to be bad style,
  // but honestly, here we know that these should be the same, so let's just save time
  // and write it concisely
  func->name = name;
  func->parameters = parameters;
  func->returnType = returnType;
  insert(func, true);
};
void Ceetah::Builder::insertReturnDirective(AST::Expression* value = nullptr) {
  auto retDir = new AST::ReturnDirective();
  retDir->value = value;
  insert(retDir);
};
void Ceetah::Builder::insertPreprocessorConditional(std::string test) {
  auto cond = new AST::ConditionalPreprocessorDirective();
  cond->test = test;
  insert(cond, true);
};
void Ceetah::Builder::insertPreprocessorInclusion(std::string whatToInclude, AST::InclusionType type) {
  auto incl = new AST::InclusionalPreprocessorDirective();
  incl->includeQuery = whatToInclude;
  incl->type = type;
  insert(incl);
};
void Ceetah::Builder::insertVariableDefinition(AST::Type* type, std::string name, AST::Expression* initializer) {
  auto varDef = new AST::VariableDefinition();
  varDef->type = type;
  varDef->name = name;
  varDef->initializationExpression = initializer;
  insert(varDef);
};
void Ceetah::Builder::insertVariableDeclaration(AST::Type* type, std::string name) {
  auto varDecl = new AST::VariableDeclaration();
  varDecl->type = type;
  varDecl->name = name;
  insert(varDecl);
};
void Ceetah::Builder::insertPreprocessorDefinition(std::string whatToDefine, std::string value) {
  auto def = new AST::DefinitivePreprocessorDirective();
  def->definition = whatToDefine;
  def->value = value;
  insert(def);
};
void Ceetah::Builder::insertExpressionStatement(Ceetah::AST::Expression* expr) {
  auto exprStmt = new AST::ExpressionStatement();
  exprStmt->expression = expr;
  insert(exprStmt);
};

void Ceetah::Builder::enterInsertionPoint() {
  return enterInsertionPoint(insertionPoint->index);
};

void Ceetah::Builder::enterInsertionPoint(size_t index) {
  AST::NodeType nodeType = insertionPoint->node->nodeType();
  if (nodeType == AST::NodeType::RootNode) {
    auto root = dynamic_cast<AST::RootNode*>(insertionPoint->node);
    insertionPoint = std::make_shared<InsertionPoint>(insertionPoint, root->statements[index]);
  } else if (nodeType == AST::NodeType::FunctionDefinition) {
    auto func = dynamic_cast<AST::FunctionDefinition*>(insertionPoint->node);
    insertionPoint = std::make_shared<InsertionPoint>(insertionPoint, func->body[index]);
  } else if (nodeType == AST::NodeType::ConditionalPreprocessorDirective) {
    auto cond = dynamic_cast<AST::ConditionalPreprocessorDirective*>(insertionPoint->node);
    insertionPoint = std::make_shared<InsertionPoint>(insertionPoint, cond->nodes[index]);
  }
};

// <not-implemented>
void Ceetah::Builder::enterInsertionPoint(AST::Node* insertionTarget) {
  throw UnimplementedException("Ceetah::Builder::enterInsertionPoint(AST::Node*)");
};
// </not-implemented>

void Ceetah::Builder::exitInsertionPoint() {
  if (insertionPoint->parent != nullptr) {
    insertionPoint = insertionPoint->parent;
  }
};
