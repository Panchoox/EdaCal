#include "eda/calculator.hpp"
#include "eda/utils.hpp"
#include "eda/stack.hpp"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <sstream>

namespace eda {

Calculator::Calculator() : tree() {
}

Calculator::~Calculator() {
}

double Calculator::evaluateInfix(const std::string& expression) {
    auto tokens = Utils::tokenize(expression);
    auto postfix = Utils::toPostfix(tokens);
    return Utils::evaluatePostfix(postfix);
}

double Calculator::evaluatePostfix(const std::string& expression) {
    auto tokens = Utils::tokenize(expression);
    return Utils::evaluatePostfix(tokens);
}

double Calculator::evaluatePrefix(const std::string& expression) {
    auto tokens = Utils::tokenize(expression);
    std::reverse(tokens.begin(), tokens.end());
    Stack<double> stack;
    for (const auto& token : tokens) {
        if (Utils::isNumber(token)) {
            stack.push(Utils::stringToDouble(token));
        } else if (Utils::isOperator(token[0]) && token.size() == 1) {
            if (stack.size() < 2) throw std::runtime_error("Expresión inválida");
            double a = stack.top(); stack.pop();
            double b = stack.top(); stack.pop();
            double res = 0;
            switch (token[0]) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': res = a / b; break;
                case '^': res = std::pow(a, b); break;
            }
            stack.push(res);
        } else if (token == "sqrt") {
            if (stack.isEmpty()) throw std::runtime_error("Expresión inválida");
            double a = stack.top(); stack.pop();
            stack.push(std::sqrt(a));
        } else {
            throw std::runtime_error("Token no soportado en evaluatePrefix: " + token);
        }
    }
    if (stack.size() != 1) throw std::runtime_error("Expresión inválida");
    return stack.top();
}

std::string Calculator::infixToPostfix(const std::string& expression) {
    auto tokens = Utils::tokenize(expression);
    auto postfix = Utils::toPostfix(tokens);
    std::string result;
    for (const auto& tok : postfix) {
        if (!result.empty()) result += " ";
        result += tok;
    }
    return result;
}

std::string Calculator::infixToPrefix(const std::string& expression) {
    auto tokens = Utils::tokenize(expression);
    std::reverse(tokens.begin(), tokens.end());
    for (auto& t : tokens) {
        if (t == "(") t = ")";
        else if (t == ")") t = "(";
    }
    auto postfix = Utils::toPostfix(tokens);
    std::reverse(postfix.begin(), postfix.end());
    std::string result;
    for (const auto& tok : postfix) {
        if (!result.empty()) result += " ";
        result += tok;
    }
    return result;
}

std::string Calculator::postfixToInfix(const std::string& expression) {
    auto tokens = Utils::tokenize(expression);
    Stack<std::string> stack;
    for (const auto& token : tokens) {
        if (Utils::isNumber(token)) {
            stack.push(token);
        } else if (Utils::isOperator(token[0]) && token.size() == 1) {
            if (stack.size() < 2) throw std::runtime_error("Expresión inválida");
            std::string b = stack.top(); stack.pop();
            std::string a = stack.top(); stack.pop();
            stack.push("(" + a + " " + token + " " + b + ")");
        } else if (token == "sqrt") {
            if (stack.isEmpty()) throw std::runtime_error("Expresión inválida");
            std::string a = stack.top(); stack.pop();
            stack.push("sqrt(" + a + ")");
        } else {
            throw std::runtime_error("Token no soportado en postfixToInfix: " + token);
        }
    }
    if (stack.size() != 1) throw std::runtime_error("Expresión inválida");
    return stack.top();
}

std::string Calculator::prefixToInfix(const std::string& expression) {
    auto tokens = Utils::tokenize(expression);
    std::reverse(tokens.begin(), tokens.end());
    Stack<std::string> stack;
    for (const auto& token : tokens) {
        if (Utils::isNumber(token)) {
            stack.push(token);
        } else if (Utils::isOperator(token[0]) && token.size() == 1) {
            if (stack.size() < 2) throw std::runtime_error("Expresión inválida");
            std::string a = stack.top(); stack.pop();
            std::string b = stack.top(); stack.pop();
            stack.push("(" + a + " " + token + " " + b + ")");
        } else if (token == "sqrt") {
            if (stack.isEmpty()) throw std::runtime_error("Expresión inválida");
            std::string a = stack.top(); stack.pop();
            stack.push("sqrt(" + a + ")");
        } else {
            throw std::runtime_error("Token no soportado en prefixToInfix: " + token);
        }
    }
    if (stack.size() != 1) throw std::runtime_error("Expresión inválida");
    return stack.top();
}

bool Calculator::isValidExpression(const std::string& expression) {
    int balance = 0;
    std::istringstream iss(expression);
    std::string token;
    bool any = false;
    while (iss >> token) {
        any = true;
        if (token == "(") balance++;
        else if (token == ")") balance--;
        if (balance < 0) return false;
    }
    return any && (balance == 0);
}


int Calculator::getPrecedence(char op) const {
    if (op == '^') return 4;
    if (op == '*' || op == '/') return 3;
    if (op == '+' || op == '-') return 2;
    return 0;
}

bool Calculator::isOperator(char c) const {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

bool Calculator::isOperand(char c) const {
    return (c >= '0' && c <= '9') || c == '.';
}

} // namespace eda