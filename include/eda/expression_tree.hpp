#pragma once

#include <string>
#include <memory>

namespace eda {

/**
 * @brief Clase TreeNode que representa un nodo de árbol de expresiones
 * 
 * Cada nodo puede ser un operador o un operando.
 */
class TreeNode {
public:
    // Constructor por defecto
    TreeNode();
    
    // Constructor con valor
    explicit TreeNode(const std::string& value);
    
    // Destructor
    ~TreeNode();
    
    // Obtener el valor del nodo
    std::string getValue() const;
    
    // Establecer el valor del nodo
    void setValue(const std::string& value);
    
    // Obtener hijo izquierdo
    TreeNode* getLeft() const;
    
    // Establecer hijo izquierdo
    void setLeft(TreeNode* left);
    
    // Obtener hijo derecho
    TreeNode* getRight() const;
    
    // Establecer hijo derecho
    void setRight(TreeNode* right);

private:
    std::string value;   // Valor del nodo (operador o operando)
    TreeNode* left;      // Hijo izquierdo
    TreeNode* right;     // Hijo derecho
};

/**
 * @brief Clase ExpressionTree que representa un árbol de expresiones matemáticas
 * 
 * Permite construir y evaluar expresiones aritméticas en notación infija,
 * prefija o postfija.
 */
class ExpressionTree {
public:
    // Constructor por defecto
    ExpressionTree();
    
    // Destructor
    ~ExpressionTree();
    
    // Construir árbol desde expresión en notación postfija
    void buildFromPostfix(const std::string& expression);
    
    // Construir árbol desde expresión en notación prefija
    void buildFromPrefix(const std::string& expression);
    
    // Construir árbol desde expresión en notación infija
    void buildFromInfix(const std::string& expression);
    
    // Evaluar la expresión del árbol
    double evaluate() const;
    
    // Obtener expresión en notación infija
    std::string toInfix() const;
    
    // Obtener expresión en notación prefija
    std::string toPrefix() const;
    
    // Obtener expresión en notación postfija
    std::string toPostfix() const;
    
    // Verificar si el árbol está vacío
    bool isEmpty() const;
    
    // Limpiar el árbol
    void clear();
         void printTree() const;
         void printTreeHelper(TreeNode* node, int depth) const;

private:
    TreeNode* root;      // Raíz del árbol
    
    // Métodos auxiliares privados
    void clearHelper(TreeNode* node);
    double evaluateHelper(TreeNode* node) const;
    std::string toInfixHelper(TreeNode* node) const;
    std::string toPrefixHelper(TreeNode* node) const;
    std::string toPostfixHelper(TreeNode* node) const;
};

} // namespace eda
