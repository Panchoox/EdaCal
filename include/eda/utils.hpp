#pragma once

#include <string>
#include <vector>

namespace eda {

/**
 * @brief Clase Utils con funciones utilitarias
 * 
 * Contiene funciones auxiliares para el procesamiento de expresiones
 * y operaciones comunes.
 */
class Utils {
public:
    // Eliminar espacios en blanco de una cadena
    static std::string trim(const std::string& str);
    
    // Dividir una cadena por un delimitador
    static std::vector<std::string> split(const std::string& str, char delimiter);
    
    // Verificar si un carácter es un dígito
    static bool isDigit(char c);
    
    // Verificar si un carácter es una letra
    static bool isLetter(char c);
    
    // Verificar si un carácter es un operador
    static bool isOperator(char c);
    
    // Verificar si un carácter es un paréntesis
    static bool isParenthesis(char c);
    
    // Convertir carácter a string
    static std::string charToString(char c);
    
    // Convertir double a string
    static std::string doubleToString(double value);
    
    // Convertir string a double
    static double stringToDouble(const std::string& str);
    
    // Verificar si una cadena es un número
    static bool isNumber(const std::string& str);
};

} // namespace eda
