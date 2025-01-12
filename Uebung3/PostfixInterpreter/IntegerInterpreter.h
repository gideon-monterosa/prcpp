#pragma once

#include <exception>
#include <stack>
#include <string>
#include <vector>

// Gideon Monterosa

namespace IntegerInterpreter {
class PostfixInterpreter {
 private:
  std::stack<int> operandStack;

  bool isOperator(const std::string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
  }

  int performOperation(const std::string& op, int operand1, int operand2) {
    if (op == "+") return operand1 + operand2;
    if (op == "-") return operand1 - operand2;
    if (op == "*") return operand1 * operand2;
    if (op == "/") {
      if (operand2 == 0) throw std::runtime_error("Null division");
      return operand1 / operand2;
    }
    throw std::invalid_argument("Illegal operator: " + op);
  }

 public:
  /// <summary>
  /// Postfix interpretation of arithmetic expressions.
  /// Throws an exception if list of tokens isn't valid.
  /// </summary>
  /// <param name="tokens">list of tokens</param>
  /// <returns>result</returns>
  int evaluate(const std::vector<std::string>& tokens) {
    for (const auto& token : tokens) {
      if (isOperator(token)) {
        if (operandStack.size() < 2) {
          throw std::runtime_error("Illegal arguments: not enought arguments");
        }

        int operand2 = operandStack.top();
        operandStack.pop();
        int operand1 = operandStack.top();
        operandStack.pop();

        int result = performOperation(token, operand1, operand2);
        operandStack.push(result);
      } else {
        try {
          operandStack.push(std::stoi(token));
        } catch (const std::invalid_argument& e) {
          throw std::runtime_error("Illegal token: " + token);
        }
      }
    }

    if (operandStack.empty()) {
      throw std::runtime_error("Illegal Arguments: Unknown operator");
    }

    return operandStack.top();
  }
};
}  // namespace IntegerInterpreter
