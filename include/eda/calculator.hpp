#pragma once

#include "expression_tree.hpp"
#include "stack.hpp"
#include <string>
#include <map>
#include <iostream>

namespace eda {

class Calculator {
public:
    Calculator();
    
    ~Calculator();
    
    double evaluateInfix(const std::string& expression);
    
    double evaluatePostfix(const std::string& expression);
    
    double evaluatePrefix(const std::string& expression);
    
    std::string infixToPostfix(const std::string& expression);
    
    std::string infixToPrefix(const std::string& expression);
    
    std::string postfixToInfix(const std::string& expression);
    
    std::string prefixToInfix(const std::string& expression);
    
    bool isValidExpression(const std::string& expression);


private:
    ExpressionTree tree;
    
    int getPrecedence(char op) const;
    bool isOperator(char c) const;
    bool isOperand(char c) const;
};

} // namespace eda
