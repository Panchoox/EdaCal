#pragma once

#include <string>
#include <vector>

namespace eda {

class Utils {
public:
    static double evaluatePostfix(const std::vector<std::string>& postfix);
    static std::vector<std::string> tokenize(const std::string& expr);

    static int precedence(char op);

    static std::vector<std::string> toPostfix(const std::vector<std::string>& tokens);
    static std::string trim(const std::string& str);
    
    static std::vector<std::string> split(const std::string& str, char delimiter);
    
    static bool isDigit(char c);
    
    static bool isLetter(char c);
    
    static bool isOperator(char c);
    
    static bool isParenthesis(char c);
    
    static std::string charToString(char c);
    
    static std::string doubleToString(double value);
    
    static double stringToDouble(const std::string& str);
    
    static bool isNumber(const std::string& str);
};

} // namespace eda
