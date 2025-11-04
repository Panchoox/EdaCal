#include "eda/utils.hpp"
#include <algorithm>
#include <sstream>
#include <cctype>

namespace eda {

// Eliminar espacios en blanco de una cadena
std::string Utils::trim(const std::string& str) {
    // TODO: Implementar
    return "";
}

// Dividir una cadena por un delimitador
std::vector<std::string> Utils::split(const std::string& str, char delimiter) {
    // TODO: Implementar
    return std::vector<std::string>();
}

// Verificar si un carácter es un dígito
bool Utils::isDigit(char c) {
    // TODO: Implementar
    return std::isdigit(static_cast<unsigned char>(c));
}

// Verificar si un carácter es una letra
bool Utils::isLetter(char c) {
    // TODO: Implementar
    return std::isalpha(static_cast<unsigned char>(c));
}

// Verificar si un carácter es un operador
bool Utils::isOperator(char c) {
    // TODO: Implementar
    return false;
}

// Verificar si un carácter es un paréntesis
bool Utils::isParenthesis(char c) {
    // TODO: Implementar
    return false;
}

// Convertir carácter a string
std::string Utils::charToString(char c) {
    // TODO: Implementar
    return std::string(1, c);
}

// Convertir double a string
std::string Utils::doubleToString(double value) {
    // TODO: Implementar
    return "";
}

// Convertir string a double
double Utils::stringToDouble(const std::string& str) {
    // TODO: Implementar
    return 0.0;
}

// Verificar si una cadena es un número
bool Utils::isNumber(const std::string& str) {
    // TODO: Implementar
    return false;
}

} // namespace eda
