#include "../../include/ceetah/ast/function-declaration.hpp"

Ceetah::AST::NodeType Ceetah::AST::FunctionDeclaration::nodeType() const {
  return NodeType::FunctionDeclaration;
};

std::string Ceetah::AST::FunctionDeclaration::toStringWithIndent(std::string indent) const {
  std::string result;

  result += returnType->toStringWithIndent(indent);
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
    result += type->toStringWithIndent(indent);
    result += ' ';
    result += name;
  }

  if (vararg) {
    if (isFirst) {
      isFirst = false;
    } else {
      result += ", ";
    }
    result += "...";
  }

  result += ");";

  if (!preComment.empty())
    result = "/* " + preComment + " */" + result;

  if (!postComment.empty())
    result += "/* " + postComment + " */";

  return result;
};

bool Ceetah::AST::FunctionDeclaration::operator ==(const Ceetah::AST::FunctionDeclaration& other) const {
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
  return true;
};

std::shared_ptr<Ceetah::AST::Node> Ceetah::AST::FunctionDeclaration::clone() const {
  auto node = std::make_shared<Ceetah::AST::FunctionDeclaration>();
  cloneTo(node);
  return node;
};

void Ceetah::AST::FunctionDeclaration::cloneTo(std::shared_ptr<Node> _node) const {
  auto node = std::dynamic_pointer_cast<Ceetah::AST::FunctionDeclaration>(_node);
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
  node->vararg = vararg;
  CEETAH_AST_CLONE_CHILD(returnType);
};
