#pragma once

#include "linked_list.hpp"

namespace eda {

/**
 * @brief Clase Stack que implementa una pila (LIFO)
 * 
 * Estructura de datos que sigue el principio Last In First Out.
 * Utiliza internamente una lista enlazada.
 * 
 * @tparam T Tipo de dato que almacena la pila
 */
template <typename T>
class Stack {
public:
    // Constructor por defecto
    Stack();
    
    // Constructor de copia
    Stack(const Stack& other);
    
    // Operador de asignación
    Stack& operator=(const Stack& other);
    
    // Destructor
    ~Stack();
    
    // Insertar un elemento en la cima
    void push(const T& value);
    
    // Eliminar el elemento en la cima
    void pop();
    
    // Obtener el elemento en la cima
    T top() const;
    
    // Verificar si la pila está vacía
    bool isEmpty() const;
    
    // Obtener el tamaño de la pila
    std::size_t size() const;
    
    // Limpiar la pila
    void clear();

private:
    LinkedList<T> list;  // Lista enlazada interna para almacenar elementos
};

} // namespace eda
