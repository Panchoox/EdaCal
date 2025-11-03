#pragma once

#include "expression_tree.hpp"
#include "stack.hpp"
#include <string>

namespace eda {

/**
 * @brief Clase Calculator que implementa una calculadora de expresiones
 * 
 * Permite evaluar expresiones matemáticas en diferentes notaciones
 * y realizar conversiones entre ellas.
 */
class Calculator {
public:
    // Constructor por defecto
    Calculator();
    
    // Destructor
    ~Calculator();
    
    // Evaluar expresión en notación infija
    double evaluateInfix(const std::string& expression);
    
    // Evaluar expresión en notación postfija
    double evaluatePostfix(const std::string& expression);
    
    // Evaluar expresión en notación prefija
    double evaluatePrefix(const std::string& expression);
    
    // Convertir de infija a postfija
    std::string infixToPostfix(const std::string& expression);
    
    // Convertir de infija a prefija
    std::string infixToPrefix(const std::string& expression);
    
    // Convertir de postfija a infija
    std::string postfixToInfix(const std::string& expression);
    
    // Convertir de prefija a infija
    std::string prefixToInfix(const std::string& expression);
    
    // Verificar si una expresión es válida
    bool isValidExpression(const std::string& expression);

private:
    ExpressionTree tree;  // Árbol de expresiones interno
    
    // Métodos auxiliares privados
    int getPrecedence(char op) const;
    bool isOperator(char c) const;
    bool isOperand(char c) const;
};

} // namespace eda
