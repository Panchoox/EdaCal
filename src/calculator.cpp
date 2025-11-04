#include "eda/calculator.hpp"
#include "eda/utils.hpp"
#include <iostream>
#include <algorithm>
#include <cmath>

namespace eda {

// Constructor por defecto
Calculator::Calculator() : tree() {
    // TODO: Implementar
}

// Destructor
Calculator::~Calculator() {
    // TODO: Implementar limpieza si es necesaria
}

// Evaluar expresión en notación infija
double Calculator::evaluateInfix(const std::string& expression) {
    // 1. Tokenizar
    auto tokens = Utils::tokenize(expression);
    auto postfix = Utils::toPostfix(tokens);
    return Utils::evaluatePostfix(postfix);
}

// Evaluar expresión en notación postfija
double Calculator::evaluatePostfix(const std::string& expression) {
    auto tokens = Utils::tokenize(expression);
    return Utils::evaluatePostfix(tokens);
}

// Evaluar expresión en notación prefija
double Calculator::evaluatePrefix(const std::string& expression) {
    // Evaluar expresión prefija usando pila (de derecha a izquierda)
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

// Convertir de infija a postfija
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

// Convertir de infija a prefija
std::string Calculator::infixToPrefix(const std::string& expression) {
    // Algoritmo: invertir, cambiar paréntesis, infija a postfija, invertir resultado
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

// Convertir de postfija a infija
std::string Calculator::postfixToInfix(const std::string& expression) {
    // Usar pila para reconstruir la expresión infija
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

// Convertir de prefija a infija
std::string Calculator::prefixToInfix(const std::string& expression) {
    // Usar pila para reconstruir la expresión infija desde prefija (de derecha a izquierda)
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

// Verificar si una expresión es válida
bool Calculator::isValidExpression(const std::string& expression) {
    // TODO: Implementar
    return false;
}

// Métodos auxiliares privados

int Calculator::getPrecedence(char op) const {
    // TODO: Implementar precedencia de operadores
    return 0;
}

bool Calculator::isOperator(char c) const {
    // TODO: Implementar verificación de operador
    return false;
}

bool Calculator::isOperand(char c) const {
    // TODO: Implementar verificación de operando
    return false;
}

} // namespace eda
