#include "../../include/ceetah/ast/function-definition.hpp"

Ceetah::AST::NodeType Ceetah::AST::FunctionDefinition::nodeType() const {
  return NodeType::FunctionDefinition;
};

std::string Ceetah::AST::FunctionDefinition::toString() const {
  std::string result;

  if (isStatic) {
    result += "static ";
  }
  result += returnType->toString();
  result += ' ';
  result += name;
  result += '(';

  bool isFirst = true;
  for (auto& [name, type]: parameters) {
    if (isFirst) {
      isFirst = false;
    } else {
      result += ", ";
    }
    result += type->toString();
    result += ' ';
    result += name;
  }

  result += ") {";
  if (body.size() > 0) {
    result += '\n';
    for (auto& stmt: body) {
      result += stmt->toString();
      result += '\n';
    }
  }
  result += "};";

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

bool Ceetah::AST::FunctionDefinition::operator ==(const Ceetah::AST::FunctionDefinition& other) const {
  if (other.name != name) return false;

  if (other.parameters.size() != parameters.size()) return false;
  bool match = true;
  for (size_t i = 0; i < parameters.size(); i++) {
    auto& param = parameters[i];
    auto& otherParam = other.parameters[i];
    auto& [paramName, paramType] = param;
    auto& [otherParamName, otherParamType] = otherParam;

    if (paramName != otherParamName) {
      match = false;
      break;
    }
    if (*paramType != *otherParamType) {
      match = false;
      break;
    }
  }
  if (!match) return false;
  
  if (*returnType != *other.returnType) return false;

  if (other.body.size() != body.size()) return false;
  for (size_t i = 0; i < body.size(); i++) {
    auto& stmt = body[i];
    auto& otherStmt = other.body[i];
    
    if (*stmt != *otherStmt) {
      return false;
    }
  }

  return true;
};

std::shared_ptr<Ceetah::AST::Node> Ceetah::AST::FunctionDefinition::clone() const {
  auto node = std::make_shared<Ceetah::AST::FunctionDefinition>();
  cloneTo(node);
  return node;
};

void Ceetah::AST::FunctionDefinition::cloneTo(std::shared_ptr<Node> _node) const {
  auto node = std::dynamic_pointer_cast<Ceetah::AST::FunctionDefinition>(_node);
  Statement::cloneTo(node);
  node->name = name;
  for (size_t i = 0; i < parameters.size(); ++i) {
    node->parameters.emplace_back(
      std::get<0>(parameters[i]),
      std::get<1>(parameters[i]) ? std::dynamic_pointer_cast<typename std::tuple_element<1, decltype(node->parameters)::value_type>::type::element_type>(std::get<1>(parameters[i])->clone()) : nullptr
    );
    if (std::get<1>(node->parameters[i])) {
      std::get<1>(node->parameters[i])->parent = node;
    }
  }
  CEETAH_AST_CLONE_CHILD(returnType);
  CEETAH_AST_CLONE_CHILDREN(body);
  node->isStatic = isStatic;
};
