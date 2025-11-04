
#include "eda/utils.hpp"
#include "eda/stack.hpp"
#include <algorithm>
#include <sstream>
#include <cctype>
#include <cmath>

namespace eda {

// Eliminar espacios en blanco de una cadena (al inicio y final)
std::string Utils::trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == std::string::npos) return "";
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, last - first + 1);
}

// Dividir una cadena por un delimitador
std::vector<std::string> Utils::split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string item;
    while (std::getline(ss, item, delimiter)) {
        tokens.push_back(item);
    }
    return tokens;
}

// Verificar si un carácter es un dígito
bool Utils::isDigit(char c) {
    return std::isdigit(static_cast<unsigned char>(c));
}

// Verificar si un carácter es una letra
bool Utils::isLetter(char c) {
    return std::isalpha(static_cast<unsigned char>(c));
}

// Verificar si un carácter es un operador
bool Utils::isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Verificar si un carácter es un paréntesis
bool Utils::isParenthesis(char c) {
    return c == '(' || c == ')';
}

// Convertir carácter a string
std::string Utils::charToString(char c) {
    return std::string(1, c);
}

// Convertir double a string
std::string Utils::doubleToString(double value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

// Convertir string a double
double Utils::stringToDouble(const std::string& str) {
    return std::stod(str);
}

// Verificar si una cadena es un número
bool Utils::isNumber(const std::string& str) {
    if (str.empty()) return false;
    char* endptr = nullptr;
    std::strtod(str.c_str(), &endptr);
    return (*endptr == '\0');
}

// Tokenizar una expresión en una lista de strings (números, operadores, paréntesis, variables)
std::vector<std::string> Utils::tokenize(const std::string& expr) {
    std::vector<std::string> tokens;
    size_t i = 0;
    while (i < expr.size()) {
        char c = expr[i];
        if (std::isspace(c)) {
            ++i;
            continue;
        }
        // Manejar funciones como sqrt(...)
        if (std::isalpha(c)) {
            size_t start = i;
            while (i < expr.size() && std::isalpha(expr[i])) ++i;
            std::string func = expr.substr(start, i - start);
            tokens.push_back(func);
            continue;
        }
        // Manejar números (incluyendo decimales y negativos unarios)
        if (std::isdigit(c) || (c == '.' && i + 1 < expr.size() && std::isdigit(expr[i + 1])) ||
            (c == '-' && (
                (i == 0) || (isOperator(expr[i - 1]) || expr[i - 1] == '(')
            ) && (
                (i + 1 < expr.size() && (std::isdigit(expr[i + 1]) || expr[i + 1] == '.'))
            ))
        ) {
            size_t start = i;
            if (c == '-') ++i; // incluir el signo negativo
            bool hasDot = (c == '.');
            while (i < expr.size() && (std::isdigit(expr[i]) || expr[i] == '.')) {
                if (expr[i] == '.') {
                    if (hasDot) break; // solo un punto decimal
                    hasDot = true;
                }
                ++i;
            }
            tokens.push_back(expr.substr(start, i - start));
            continue;
        }
        // Manejar operadores y paréntesis
        if (isOperator(c) || isParenthesis(c)) {
            tokens.push_back(std::string(1, c));
            ++i;
            continue;
        }
        // Caracter desconocido, ignorar
        ++i;
    }
    return tokens;
}

// Obtener la precedencia de un operador
int Utils::precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Convertir una expresión tokenizada de infijo a posfijo (Shunting Yard)
std::vector<std::string> Utils::toPostfix(const std::vector<std::string>& tokens) {
    std::vector<std::string> output;
    Stack<std::string> stack;
    for (const auto& token : tokens) {
        if (isNumber(token) || (isLetter(token[0]) && token != "sqrt")) {
            output.push_back(token);
        } else if (token == "sqrt") {
            stack.push(token); // Tratar como función
        } else if (token == "(") {
            stack.push(token);
        } else if (token == ")") {
            while (!stack.isEmpty() && stack.top() != "(") {
                output.push_back(stack.top());
                stack.pop();
            }
            if (!stack.isEmpty() && stack.top() == "(") stack.pop(); // Quita el '('
            // Si hay una función en la cima, también sacarla
            if (!stack.isEmpty() && stack.top() == "sqrt") {
                output.push_back(stack.top());
                stack.pop();
            }
        } else if (isOperator(token[0])) {
            while (!stack.isEmpty() && (isOperator(stack.top()[0]) || stack.top() == "sqrt") &&
                   ((precedence(token[0]) < precedence(stack.top()[0])) ||
                    (precedence(token[0]) == precedence(stack.top()[0]) && token[0] != '^'))) {
                output.push_back(stack.top());
                stack.pop();
            }
            stack.push(token);
        }
    }
    // Si queda una función en la pila, sacarla
    while (!stack.isEmpty()) {
        output.push_back(stack.top());
        stack.pop();
    }
    while (!stack.isEmpty()) {
        output.push_back(stack.top());
        stack.pop();
    }
    return output;
}

// Evaluar una expresión en notación posfija
double Utils::evaluatePostfix(const std::vector<std::string>& postfix) {
    Stack<double> stack;
    for (const auto& token : postfix) {
        if (isNumber(token)) {
            stack.push(stringToDouble(token));
        } else if (isOperator(token[0]) && token.size() == 1) {
            if (stack.size() < 2) throw std::runtime_error("Expresión inválida");
            double b = stack.top(); stack.pop();
            double a = stack.top(); stack.pop();
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
            throw std::runtime_error("Token no soportado en evaluatePostfix: " + token);
        }
    }
    if (stack.size() != 1) throw std::runtime_error("Expresión inválida");
    return stack.top();
    }
}

