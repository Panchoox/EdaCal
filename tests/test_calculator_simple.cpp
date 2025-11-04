#include "eda/calculator.hpp"
#include <iostream>

int main() {
    eda::Calculator calc;
    std::string expr;
    std::cout << "Ingresa una expresión infija (ejemplo: 3 + 4 * 2): ";
    std::getline(std::cin, expr);
    try {
        double resultado = calc.evaluateInfix(expr);
        std::cout << "Resultado: " << resultado << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}
