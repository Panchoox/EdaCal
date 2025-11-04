#include "eda/calculator.hpp"
#include "eda/utils.hpp"
#include <iostream>
#include <string>

/**
 * @brief Programa principal de la calculadora EdaCal
 * 
 * Este programa permite evaluar expresiones matemáticas y realizar
 * conversiones entre diferentes notaciones (infija, prefija, postfija).
 */

void printMenu() {
    std::cout << "\n=== EdaCal - Calculadora de Expresiones ===" << std::endl;
    std::cout << "1. Evaluar expresión infija" << std::endl;
    std::cout << "2. Evaluar expresión postfija" << std::endl;
    std::cout << "3. Evaluar expresión prefija" << std::endl;
    std::cout << "4. Convertir infija a postfija" << std::endl;
    std::cout << "5. Convertir infija a prefija" << std::endl;
    std::cout << "6. Convertir postfija a infija" << std::endl;
    std::cout << "7. Convertir prefija a infija" << std::endl;
    std::cout << "0. Salir" << std::endl;
    std::cout << "Seleccione una opción: ";
}

int main() {
    eda::Calculator calculator;
    std::string expression;
    int option;
    
    std::cout << "Bienvenido a EdaCal" << std::endl;
    std::cout << "Calculadora de Expresiones Aritméticas" << std::endl;
    
    while (true) {
        printMenu();
        std::cin >> option;
        std::cin.ignore(); // Limpiar el buffer

        if (option == 0) {
            std::cout << "¡Hasta luego!" << std::endl;
            break;
        }

        try {
            switch (option) {
                case 1:
                    std::cout << "Ingrese expresión infija: ";
                    std::getline(std::cin, expression);
                    std::cout << "Resultado: " << calculator.evaluateInfix(expression) << std::endl;
                    break;

                case 2:
                    std::cout << "Ingrese expresión postfija: ";
                    std::getline(std::cin, expression);
                    std::cout << "Resultado: " << calculator.evaluatePostfix(expression) << std::endl;
                    break;

                case 3:
                    std::cout << "Ingrese expresión prefija: ";
                    std::getline(std::cin, expression);
                    std::cout << "Resultado: " << calculator.evaluatePrefix(expression) << std::endl;
                    break;

                case 4:
                    std::cout << "Ingrese expresión infija: ";
                    std::getline(std::cin, expression);
                    std::cout << "Postfija: " << calculator.infixToPostfix(expression) << std::endl;
                    break;

                case 5:
                    std::cout << "Ingrese expresión infija: ";
                    std::getline(std::cin, expression);
                    std::cout << "Prefija: " << calculator.infixToPrefix(expression) << std::endl;
                    break;

                case 6:
                    std::cout << "Ingrese expresión postfija: ";
                    std::getline(std::cin, expression);
                    std::cout << "Infija: " << calculator.postfixToInfix(expression) << std::endl;
                    break;

                case 7:
                    std::cout << "Ingrese expresión prefija: ";
                    std::getline(std::cin, expression);
                    std::cout << "Infija: " << calculator.prefixToInfix(expression) << std::endl;
                    break;

                default:
                    std::cout << "Opción inválida. Intente nuevamente." << std::endl;
                    break;
            }
        } catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
    
    return 0;
}
