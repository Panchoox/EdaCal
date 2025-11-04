#include "eda/expression_tree.hpp"
#include <iostream>
#include <cassert>

/**
 * @brief Pruebas para la clase ExpressionTree
 * 
 * Este archivo contiene pruebas unitarias básicas para verificar
 * el funcionamiento del árbol de expresiones.
 */

void testTreeNodeCreation() {
    // TODO: Implementar prueba de creación de nodo
    std::cout << "Test: TreeNode creation - ";
    eda::TreeNode node("5");
    assert(node.getValue() == "5");
    std::cout << "PASSED" << std::endl;
}

void testExpressionTreeCreation() {
    // TODO: Implementar prueba de creación de árbol
    std::cout << "Test: ExpressionTree creation - ";
    eda::ExpressionTree tree;
    assert(tree.isEmpty());
    std::cout << "PASSED" << std::endl;
}

void testBuildFromPostfix() {
    // TODO: Implementar prueba de construcción desde notación postfija
    std::cout << "Test: Build from postfix - ";
    std::cout << "NOT IMPLEMENTED" << std::endl;
}

void testBuildFromPrefix() {
    // TODO: Implementar prueba de construcción desde notación prefija
    std::cout << "Test: Build from prefix - ";
    std::cout << "NOT IMPLEMENTED" << std::endl;
}

void testBuildFromInfix() {
    // TODO: Implementar prueba de construcción desde notación infija
    std::cout << "Test: Build from infix - ";
    std::cout << "NOT IMPLEMENTED" << std::endl;
}

void testEvaluate() {
    // TODO: Implementar prueba de evaluación
    std::cout << "Test: Evaluate expression - ";
    std::cout << "NOT IMPLEMENTED" << std::endl;
}

void testToInfix() {
    // TODO: Implementar prueba de conversión a infija
    std::cout << "Test: Convert to infix - ";
    std::cout << "NOT IMPLEMENTED" << std::endl;
}

void testToPrefix() {
    // TODO: Implementar prueba de conversión a prefija
    std::cout << "Test: Convert to prefix - ";
    std::cout << "NOT IMPLEMENTED" << std::endl;
}

void testToPostfix() {
    // TODO: Implementar prueba de conversión a postfija
    std::cout << "Test: Convert to postfix - ";
    std::cout << "NOT IMPLEMENTED" << std::endl;
}

int main() {
    std::cout << "=== ExpressionTree Tests ===" << std::endl;
    
    testTreeNodeCreation();
    testExpressionTreeCreation();
    testBuildFromPostfix();
    testBuildFromPrefix();
    testBuildFromInfix();
    testEvaluate();
    testToInfix();
    testToPrefix();
    testToPostfix();
    
    std::cout << "=== All ExpressionTree tests completed ===" << std::endl;
    return 0;
}
