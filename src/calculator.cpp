#include "eda/calculator.hpp"
#include <sstream>
#include <iostream>

namespace eda {

// Constructor por defecto
Calculator::Calculator() : tree() {
    // Constructor vacío: no es necesario inicializar aquí variables del prompt
}

// Destructor
Calculator::~Calculator() {
    // Nada que limpiar explícitamente aquí
}

// Evaluar expresión en notación infija
double Calculator::evaluateInfix(const std::string& expression) {
    // Mantener como TODO: la conversión/evaluación infija->postfija es
    // responsabilidad de Persona A según la distribución.
    return 0.0;
}

// Evaluar expresión en notación postfija
double Calculator::evaluatePostfix(const std::string& expression) {
    // TODO: Implementar (Persona A)
    return 0.0;
}

// Evaluar expresión en notación prefija (esencial Persona B)
double Calculator::evaluatePrefix(const std::string& expression) {
    tree.clear();
    tree.buildFromPrefix(expression);
    return tree.evaluate();
}

// Convertir de infija a postfija
std::string Calculator::infixToPostfix(const std::string& expression) {
    // TODO: Implementar (Persona A)
    return std::string();
}

// Convertir de infija a prefija (esencial Persona B)
std::string Calculator::infixToPrefix(const std::string& expression) {
    tree.clear();
    tree.buildFromInfix(expression);
    return tree.toPrefix();
}

// Convertir de postfija a infija (esencial Persona B)
std::string Calculator::postfixToInfix(const std::string& expression) {
    tree.clear();
    tree.buildFromPostfix(expression);
    return tree.toInfix();
}

// Convertir de prefija a infija (esencial Persona B)
std::string Calculator::prefixToInfix(const std::string& expression) {
    tree.clear();
    tree.buildFromPrefix(expression);
    return tree.toInfix();
}

// Verificar si una expresión es válida (esencial Persona B)
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

// Métodos auxiliares privados (esenciales Persona B)
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

