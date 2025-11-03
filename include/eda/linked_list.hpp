#pragma once

#include "node.hpp"
#include <cstddef>

namespace eda {

/**
 * @brief Clase LinkedList que implementa una lista enlazada simple
 * 
 * Estructura de datos lineal donde cada elemento apunta al siguiente.
 * 
 * @tparam T Tipo de dato que almacena la lista
 */
template <typename T>
class LinkedList {
public:
    // Constructor por defecto
    LinkedList();
    
    // Constructor de copia
    LinkedList(const LinkedList& other);
    
    // Operador de asignación
    LinkedList& operator=(const LinkedList& other);
    
    // Destructor
    ~LinkedList();
    
    // Insertar un elemento al inicio
    void pushFront(const T& value);
    
    // Insertar un elemento al final
    void pushBack(const T& value);
    
    // Eliminar el elemento al inicio
    void popFront();
    
    // Eliminar el elemento al final
    void popBack();
    
    // Obtener el elemento al inicio
    T front() const;
    
    // Obtener el elemento al final
    T back() const;
    
    // Verificar si la lista está vacía
    bool isEmpty() const;
    
    // Obtener el tamaño de la lista
    std::size_t size() const;
    
    // Limpiar la lista
    void clear();

private:
    Node<T>* head;       // Puntero al primer nodo
    Node<T>* tail;       // Puntero al último nodo
    std::size_t count;   // Número de elementos en la lista
};

} // namespace eda
