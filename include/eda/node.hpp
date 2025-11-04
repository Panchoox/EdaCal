#include <cstddef>

// Declaración adelantada de LinkedList
namespace eda {
template <typename T>
class LinkedList;
}
#pragma once

#include <memory>
#include <string>

namespace eda {

/**
 * @brief Clase Node que representa un nodo genérico
 * 
 * Esta clase puede ser utilizada para construir estructuras de datos
 * como listas enlazadas, árboles, etc.
 * 
 * @tparam T Tipo de dato que almacena el nodo
 */
template <typename T>
class Node {
    friend class LinkedList<T>;
    friend class LinkedList<T>;
public:
    // Constructor por defecto
    Node();
    
    // Constructor con valor
    explicit Node(const T& value);
    
    // Constructor de copia
    Node(const Node& other);
    
    // Operador de asignación
    Node& operator=(const Node& other);
    
    // Destructor
    ~Node();
    
    // Obtener el valor almacenado
    T getValue() const;
    
    // Establecer el valor almacenado
    void setValue(const T& value);
    
    // Obtener puntero al siguiente nodo
    Node* getNext() const;
    
    // Establecer puntero al siguiente nodo
    void setNext(Node* next);

private:
    T data;              // Dato almacenado en el nodo
    Node* next;          // Puntero al siguiente nodo
};

} // namespace eda
