#include "../include/ceetah/builder.hpp"

Ceetah::InsertionException::InsertionException():
  std::runtime_error("Ceetah insertion point exception")
  {};

Ceetah::InsertionPoint::InsertionPoint(Ceetah::AST::Node* _node):
  node(_node)
  {};
Ceetah::InsertionPoint::InsertionPoint(std::shared_ptr<Ceetah::InsertionPoint> _parent, Ceetah::AST::Node* _node):
  node(_node),
  parent(_parent)
  {};

size_t Ceetah::InsertionPoint::insert(Ceetah::AST::Node* newNode, bool movePointer) {
  size_t position = index;
  AST::NodeType nodeType = node->nodeType();
  if (nodeType == AST::NodeType::RootNode) {
    auto root = dynamic_cast<AST::RootNode*>(node);
    auto stmt = dynamic_cast<AST::Statement*>(newNode);
    stmt->parent = root;
    root->statements.insert(root->statements.begin() + index, stmt);
    if (movePointer) {
      index++;
    }
  } else if (nodeType == AST::NodeType::FunctionDefinition) {
    auto func = dynamic_cast<AST::FunctionDefinition*>(node);
    auto stmt = dynamic_cast<AST::Statement*>(newNode);
    stmt->parent = func;
    func->body.insert(func->body.begin() + index, stmt);
    if (movePointer) {
      index++;
    }
  } else if (nodeType == AST::NodeType::ConditionalPreprocessorDirective) {
    auto cond = dynamic_cast<AST::ConditionalPreprocessorDirective*>(node);
    auto child = dynamic_cast<AST::Node*>(newNode);
    child->parent = cond;
    cond->nodes.insert(cond->nodes.begin() + index, child);
    if (movePointer) {
      index++;
    }
  } else {
    throw InvalidInsertionNodeException();
  }
  return position;
};

// <not-implemented>
size_t Ceetah::InsertionPoint::insertBefore(Ceetah::AST::Node* newNode, bool movePointer) {
  throw UnimplementedException("Ceetah::InsertionPoint::insertBefore(Ceetah::AST::Node*, bool?)");
};
size_t Ceetah::InsertionPoint::insertBefore(Ceetah::AST::Node* newNode, Ceetah::AST::Node* referencePoint, bool movePointer) {
  throw UnimplementedException("Ceetah::InsertionPoint::insertBefore(Ceetah::AST::Node*, Ceetah::AST::Node*, bool?)");
};

size_t Ceetah::InsertionPoint::insertAfter(Ceetah::AST::Node* newNode, bool movePointer) {
  size_t i = index;
  moveForward();
  insert(newNode, movePointer);
  if (!movePointer) {
    index = i;
  }
  return i + 1;
};
size_t Ceetah::InsertionPoint::insertAfter(Ceetah::AST::Node* newNode, Ceetah::AST::Node* referencePoint, bool movePointer) {
  throw UnimplementedException("Ceetah::InsertionPoint::insertAfter(Ceetah::AST::Node*, Ceetah::AST::Node*, bool?)");
};
// </not-implemented>

void Ceetah::InsertionPoint::scrollToStart() {
  index = 0;
};
void Ceetah::InsertionPoint::scrollToEnd() {
  AST::NodeType nodeType = node->nodeType();
  if (nodeType == AST::NodeType::RootNode) {
    auto root = dynamic_cast<AST::RootNode*>(node);
    index = root->statements.size();
  } else if (nodeType == AST::NodeType::FunctionDefinition) {
    auto func = dynamic_cast<AST::FunctionDefinition*>(node);
    index = func->body.size();
  } else if (nodeType == AST::NodeType::ConditionalPreprocessorDirective) {
    auto cond = dynamic_cast<AST::ConditionalPreprocessorDirective*>(node);
    index = cond->nodes.size();
  } else {
    throw InvalidInsertionNodeException();
  }
};

size_t Ceetah::InsertionPoint::containerLength() {
  return container().size();
};

std::vector<Ceetah::AST::Node*> Ceetah::InsertionPoint::container() {
  AST::NodeType nodeType = node->nodeType();
  if (nodeType == AST::NodeType::RootNode) {
    auto root = dynamic_cast<AST::RootNode*>(node);
    return root->statements;
  } else if (nodeType == AST::NodeType::FunctionDefinition) {
    auto func = dynamic_cast<AST::FunctionDefinition*>(node);
    return func->body;
  } else if (nodeType == AST::NodeType::ConditionalPreprocessorDirective) {
    auto cond = dynamic_cast<AST::ConditionalPreprocessorDirective*>(node);
    return cond->nodes;
  } else {
    throw InvalidInsertionNodeException();
  }
};

void Ceetah::InsertionPoint::moveBackward() {
  if (index != 0) {
    index--;
  }
};
void Ceetah::InsertionPoint::moveForward() {
  if (index < containerLength()) {
    index++;
  }
};

void Ceetah::InsertionPoint::scrollTo(Ceetah::AST::Node* tgt) {
  auto cont = container();
  for (size_t i = 0; i < cont.size(); i++) {
    auto& item = cont[i];
    if (*item == *tgt) {
      index = i;
      break;
    }
  }
};

size_t Ceetah::InsertionPoint::save() {
  return index;
};
void Ceetah::InsertionPoint::restore(size_t position) {
  index = position;
};
