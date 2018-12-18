#include "../include/ceetah/builder.hpp"

Ceetah::InsertionException::InsertionException():
  std::runtime_error("Ceetah insertion point exception")
  {};

Ceetah::InsertionPoint::InsertionPoint(std::shared_ptr<Ceetah::AST::Node> _node):
  node(_node)
  {};
Ceetah::InsertionPoint::InsertionPoint(std::shared_ptr<Ceetah::InsertionPoint> _parent, std::shared_ptr<Ceetah::AST::Node> _node):
  node(_node),
  parent(_parent)
  {};

size_t Ceetah::InsertionPoint::insert(std::shared_ptr<Ceetah::AST::Node> newNode, bool movePointer) {
  size_t position = index;
  AST::NodeType nodeType = node->nodeType();
  if (nodeType == AST::NodeType::RootNode) {
    auto root = std::dynamic_pointer_cast<AST::RootNode>(node);
    auto stmt = std::dynamic_pointer_cast<AST::Statement>(newNode);
    stmt->parent = root;
    root->statements.insert(root->statements.begin() + index, stmt);
    if (movePointer) {
      index++;
    }
  } else if (nodeType == AST::NodeType::FunctionDefinition) {
    auto func = std::dynamic_pointer_cast<AST::FunctionDefinition>(node);
    auto stmt = std::dynamic_pointer_cast<AST::Statement>(newNode);
    stmt->parent = func;
    func->body.insert(func->body.begin() + index, stmt);
    if (movePointer) {
      index++;
    }
  } else if (nodeType == AST::NodeType::ConditionalPreprocessorDirective) {
    auto cond = std::dynamic_pointer_cast<AST::ConditionalPreprocessorDirective>(node);
    auto child = std::dynamic_pointer_cast<AST::Node>(newNode);
    child->parent = cond;
    cond->nodes.insert(cond->nodes.begin() + index, child);
    if (movePointer) {
      index++;
    }
  } else if (nodeType == AST::NodeType::ConditionalStatement) {
    auto cond = std::dynamic_pointer_cast<AST::ConditionalStatement>(node);
    if (index == 0 || index == 1) {
      auto stmt = std::dynamic_pointer_cast<AST::Statement>(newNode);
      if (!stmt) {
        throw InsertionException();
      }
      stmt->parent = cond;
      if (index == 0) {
        cond->primaryResult = stmt;
      } else {
        cond->finalAlternative = stmt;
      }
    } else {
      if (cond->alternatives.size() < index - 1) {
        cond->alternatives.resize(index - 1, { nullptr, nullptr });
      }
      if (auto expr = std::dynamic_pointer_cast<AST::Expression>(newNode)) {
        cond->alternatives[index - 2].first = expr;
      } else if (auto stmt = std::dynamic_pointer_cast<AST::Statement>(newNode)) {
        cond->alternatives[index - 2].second = stmt;
      }
    }
  } else if (nodeType == AST::NodeType::Block) {
    auto block = std::dynamic_pointer_cast<AST::Block>(node);
    auto stmt = std::dynamic_pointer_cast<AST::Statement>(newNode);
    stmt->parent = block;
    block->statements.insert(block->statements.begin() + index, stmt);
    if (movePointer) {
      index++;
    }
  } else {
    throw InvalidInsertionNodeException();
  }
  return position;
};

// <not-implemented>
size_t Ceetah::InsertionPoint::insertBefore(std::shared_ptr<Ceetah::AST::Node> newNode, bool movePointer) {
  throw UnimplementedException("Ceetah::InsertionPoint::insertBefore(Ceetah::AST::Node*, bool?)");
};
size_t Ceetah::InsertionPoint::insertBefore(std::shared_ptr<Ceetah::AST::Node> newNode, std::shared_ptr<Ceetah::AST::Node> referencePoint, bool movePointer) {
  throw UnimplementedException("Ceetah::InsertionPoint::insertBefore(Ceetah::AST::Node*, Ceetah::AST::Node*, bool?)");
};

size_t Ceetah::InsertionPoint::insertAfter(std::shared_ptr<Ceetah::AST::Node> newNode, bool movePointer) {
  size_t i = index;
  moveForward();
  insert(newNode, movePointer);
  if (!movePointer) {
    index = i;
  }
  return i + 1;
};
size_t Ceetah::InsertionPoint::insertAfter(std::shared_ptr<Ceetah::AST::Node> newNode, std::shared_ptr<Ceetah::AST::Node> referencePoint, bool movePointer) {
  throw UnimplementedException("Ceetah::InsertionPoint::insertAfter(Ceetah::AST::Node*, Ceetah::AST::Node*, bool?)");
};
// </not-implemented>

void Ceetah::InsertionPoint::scrollToStart() {
  index = 0;
};
void Ceetah::InsertionPoint::scrollToEnd() {
  AST::NodeType nodeType = node->nodeType();
  if (nodeType == AST::NodeType::RootNode) {
    auto root = std::dynamic_pointer_cast<AST::RootNode>(node);
    index = root->statements.size();
  } else if (nodeType == AST::NodeType::FunctionDefinition) {
    auto func = std::dynamic_pointer_cast<AST::FunctionDefinition>(node);
    index = func->body.size();
  } else if (nodeType == AST::NodeType::ConditionalPreprocessorDirective) {
    auto cond = std::dynamic_pointer_cast<AST::ConditionalPreprocessorDirective>(node);
    index = cond->nodes.size();
  } else if (nodeType == AST::NodeType::Block) {
    auto block = std::dynamic_pointer_cast<AST::Block>(node);
    index = block->statements.size();
  } else {
    throw InvalidInsertionNodeException();
  }
};

size_t Ceetah::InsertionPoint::containerLength() {
  return container().size();
};

std::vector<std::shared_ptr<Ceetah::AST::Node>> Ceetah::InsertionPoint::container() {
  AST::NodeType nodeType = node->nodeType();
  if (nodeType == AST::NodeType::RootNode) {
    auto root = std::dynamic_pointer_cast<AST::RootNode>(node);
    return root->statements;
  } else if (nodeType == AST::NodeType::FunctionDefinition) {
    auto func = std::dynamic_pointer_cast<AST::FunctionDefinition>(node);
    return func->body;
  } else if (nodeType == AST::NodeType::ConditionalPreprocessorDirective) {
    auto cond = std::dynamic_pointer_cast<AST::ConditionalPreprocessorDirective>(node);
    return cond->nodes;
  } else if (nodeType == AST::NodeType::Block) {
    auto block = std::dynamic_pointer_cast<AST::Block>(node);
    return block->statements;
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

void Ceetah::InsertionPoint::scrollTo(std::shared_ptr<Ceetah::AST::Node> tgt) {
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
