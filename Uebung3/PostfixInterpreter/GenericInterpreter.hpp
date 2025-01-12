#pragma once

#include <exception>
#include <functional>
#include <stack>
#include <string>
#include <vector>

// Gideon Monterosa

namespace GenericInterpreter {

template <typename T>
T convertString(const std::string& s) {
  throw "Type not supported";
  return T();
}

template <>
inline int convertString<int>(const std::string& s) {
  return std::stoi(s);
}

template <>
inline long long convertString<long long>(const std::string& s) {
  return std::stoll(s);
}

template <>
inline float convertString<float>(const std::string& s) {
  return std::stof(s);
}

template <>
inline double convertString<double>(const std::string& s) {
  return std::stod(s);
}

template <typename T>
concept Addable = requires(T a, T b) { a + b; };

template <typename T>
concept Subtractable = requires(T a, T b) { a - b; };

template <typename T>
concept Multipliable = requires(T a, T b) { a* b; };

template <typename T>
concept Divisible = requires(T a, T b) { a / b; };

template <typename Func, typename T>
concept BinaryOperation = requires(Func f, T a, T b) {
  { f(a, b) } -> std::same_as<T>;
};

template <typename Func, typename T>
concept UnaryOperation = requires(Func f, T a) {
  { f(a) } -> std::same_as<T>;
};

template <typename T>
concept Computable =
    Addable<T> && Subtractable<T> && Multipliable<T> && Divisible<T>;

template <typename T>
struct Increment {
  constexpr T operator()(const T& a) const {
    return a + 1;
  }
};

template <Computable T>
class PostfixInterpreter {
 private:
  std::stack<T> stack;

  template <typename Func>
    requires BinaryOperation<Func, T>
  void apply(Func func) {
    if (stack.size() < 2)
      throw std::invalid_argument("Not enough operands on stack");
    T b = stack.top();
    stack.pop();
    T a = stack.top();
    stack.pop();
    stack.push(func(a, b));
  }

  template <typename Func>
    requires UnaryOperation<Func, T>
  void apply(Func func, bool isUnary) {
    if (stack.size() < 1)
      throw std::invalid_argument("Not enough operands on stack");

    T a = stack.top();

    stack.pop();
    stack.push(func(a));
  }

 public:
  T evaluate(const std::vector<std::string>& tokens) {
    stack = {};  // Reset the stack
    for (const auto& token : tokens) {
      if (token == "+") {
        apply(std::plus<T>());
      } else if (token == "-") {
        apply(std::minus<T>());
      } else if (token == "*") {
        apply(std::multiplies<T>());
      } else if (token == "/") {
        apply(std::divides<T>());
      } else if (token == "++") {
        apply(Increment<T>(), true);
      } else {
        stack.push(convertString<T>(token));
      }
    }
    if (stack.size() != 1) {
      throw std::invalid_argument("Invalid expression.");
    }
    return stack.top();
  }
};
}  // namespace GenericInterpreter
