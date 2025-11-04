#pragma once

#include <string>
#include <memory>

namespace eda {

class TreeNode {
public:
    TreeNode();
    
    explicit TreeNode(const std::string& value);
    
    ~TreeNode();
    
    std::string getValue() const;
    
    void setValue(const std::string& value);
    
    TreeNode* getLeft() const;
    
    void setLeft(TreeNode* left);
    
    TreeNode* getRight() const;
    
    void setRight(TreeNode* right);

private:
    std::string value;   
    TreeNode* left;      
    TreeNode* right;     
};

class ExpressionTree {
public:
    ExpressionTree();
    
    ~ExpressionTree();
    
    void buildFromPostfix(const std::string& expression);
    
    void buildFromPrefix(const std::string& expression);
    
    void buildFromInfix(const std::string& expression);
    
    double evaluate() const;
    
    std::string toInfix() const;
    
    std::string toPrefix() const;
    
    std::string toPostfix() const;
    
    bool isEmpty() const;
    
    void clear();
    void printTree() const;
    void printTreeHelper(TreeNode* node, int depth) const;

private:
    TreeNode* root;
    
    void clearHelper(TreeNode* node);
    double evaluateHelper(TreeNode* node) const;
    std::string toInfixHelper(TreeNode* node) const;
    std::string toPrefixHelper(TreeNode* node) const;
    std::string toPostfixHelper(TreeNode* node) const;
};

} // namespace eda
