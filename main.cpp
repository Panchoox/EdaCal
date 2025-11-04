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
    
    // TODO: Implementar lógica del programa principal
    
    while (true) {
        printMenu();
        std::cin >> option;
        std::cin.ignore(); // Limpiar el buffer
        
        if (option == 0) {
            std::cout << "¡Hasta luego!" << std::endl;
            break;
        }
        
        switch (option) {
            case 1:
                std::cout << "Ingrese expresión infija: ";
                std::getline(std::cin, expression);
                // TODO: Llamar a calculator.evaluateInfix(expression)
                std::cout << "Función no implementada aún." << std::endl;
                break;
                
            case 2:
                std::cout << "Ingrese expresión postfija: ";
                std::getline(std::cin, expression);
                // TODO: Llamar a calculator.evaluatePostfix(expression)
                std::cout << "Función no implementada aún." << std::endl;
                break;
                
            case 3:
                std::cout << "Ingrese expresión prefija: ";
                std::getline(std::cin, expression);
                // TODO: Llamar a calculator.evaluatePrefix(expression)
                std::cout << "Función no implementada aún." << std::endl;
                break;
                
            case 4:
                std::cout << "Ingrese expresión infija: ";
                std::getline(std::cin, expression);
                // TODO: Llamar a calculator.infixToPostfix(expression)
                std::cout << "Función no implementada aún." << std::endl;
                break;
                
            case 5:
                std::cout << "Ingrese expresión infija: ";
                std::getline(std::cin, expression);
                // TODO: Llamar a calculator.infixToPrefix(expression)
                std::cout << "Función no implementada aún." << std::endl;
                break;
                
            case 6:
                std::cout << "Ingrese expresión postfija: ";
                std::getline(std::cin, expression);
                // TODO: Llamar a calculator.postfixToInfix(expression)
                std::cout << "Función no implementada aún." << std::endl;
                break;
                
            case 7:
                std::cout << "Ingrese expresión prefija: ";
                std::getline(std::cin, expression);
                // TODO: Llamar a calculator.prefixToInfix(expression)
                std::cout << "Función no implementada aún." << std::endl;
                break;
                
            default:
                std::cout << "Opción inválida. Intente nuevamente." << std::endl;
                break;
        }
    }
    
    return 0;
}
