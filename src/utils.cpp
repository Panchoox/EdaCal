
#include "eda/utils.hpp"
#include "eda/stack.hpp"
#include <algorithm>
#include <sstream>
#include <cctype>
#include <cmath>

namespace eda {

std::string Utils::trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == std::string::npos) return "";
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, last - first + 1);
}

std::vector<std::string> Utils::split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string item;
    while (std::getline(ss, item, delimiter)) {
        tokens.push_back(item);
    }
    return tokens;
}

bool Utils::isDigit(char c) {
    return std::isdigit(static_cast<unsigned char>(c));
}

bool Utils::isLetter(char c) {
    return std::isalpha(static_cast<unsigned char>(c));
}

bool Utils::isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

bool Utils::isParenthesis(char c) {
    return c == '(' || c == ')';
}

std::string Utils::charToString(char c) {
    return std::string(1, c);
}

std::string Utils::doubleToString(double value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

double Utils::stringToDouble(const std::string& str) {
    return std::stod(str);
}

bool Utils::isNumber(const std::string& str) {
    if (str.empty()) return false;
    char* endptr = nullptr;
    std::strtod(str.c_str(), &endptr);
    return (*endptr == '\0');
}

std::vector<std::string> Utils::tokenize(const std::string& expr) {
    std::vector<std::string> tokens;
    size_t i = 0;
    while (i < expr.size()) {
        char c = expr[i];
        if (std::isspace(c)) {
            ++i;
            continue;
        }
        if (std::isalpha(c)) {
            size_t start = i;
            while (i < expr.size() && std::isalpha(expr[i])) ++i;
            std::string func = expr.substr(start, i - start);
            tokens.push_back(func);
            continue;
        }
    
        if (std::isdigit(c) || (c == '.' && i + 1 < expr.size() && std::isdigit(expr[i + 1])) ||
            (c == '-' && (
                (i == 0) || (isOperator(expr[i - 1]) || expr[i - 1] == '(')
            ) && (
                (i + 1 < expr.size() && (std::isdigit(expr[i + 1]) || expr[i + 1] == '.'))
            ))
        ) {
            size_t start = i;
            if (c == '-') ++i;
            bool hasDot = (c == '.');
            while (i < expr.size() && (std::isdigit(expr[i]) || expr[i] == '.')) {
                if (expr[i] == '.') {
                    if (hasDot) break;
                    hasDot = true;
                }
                ++i;
            }
            tokens.push_back(expr.substr(start, i - start));
            continue;
        }
        if (isOperator(c) || isParenthesis(c)) {
            tokens.push_back(std::string(1, c));
            ++i;
            continue;
        }
        ++i;
    }
    return tokens;
}

int Utils::precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

std::vector<std::string> Utils::toPostfix(const std::vector<std::string>& tokens) {
    std::vector<std::string> output;
    Stack<std::string> stack;
    for (const auto& token : tokens) {
        if (isNumber(token) || (isLetter(token[0]) && token != "sqrt")) {
            output.push_back(token);
        } else if (token == "sqrt") {
            stack.push(token); 
        } else if (token == "(") {
            stack.push(token);
        } else if (token == ")") {
            while (!stack.isEmpty() && stack.top() != "(") {
                output.push_back(stack.top());
                stack.pop();
            }
            if (!stack.isEmpty() && stack.top() == "(") stack.pop();
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

