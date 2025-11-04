#include "eda/stack.hpp"

namespace eda {

// Constructor por defecto
template <typename T>
Stack<T>::Stack() : list() {
    // TODO: Implementar
}

// Constructor de copia
template <typename T>
Stack<T>::Stack(const Stack& other) : list(other.list) {
    // TODO: Implementar
}

// Operador de asignación
template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& other) {
    // TODO: Implementar
    if (this != &other) {
        list = other.list;
    }
    return *this;
}

// Destructor
template <typename T>
Stack<T>::~Stack() {
    // TODO: Implementar limpieza si es necesaria
}

// Insertar un elemento en la cima
template <typename T>
void Stack<T>::push(const T& value) {
    // TODO: Implementar
}

// Eliminar el elemento en la cima
template <typename T>
void Stack<T>::pop() {
    // TODO: Implementar
}

// Obtener el elemento en la cima
template <typename T>
T Stack<T>::top() const {
    // TODO: Implementar
    return T();
}

// Verificar si la pila está vacía
template <typename T>
bool Stack<T>::isEmpty() const {
    // TODO: Implementar
    return list.isEmpty();
}

// Obtener el tamaño de la pila
template <typename T>
std::size_t Stack<T>::size() const {
    // TODO: Implementar
    return list.size();
}

// Limpiar la pila
template <typename T>
void Stack<T>::clear() {
    // TODO: Implementar
    list.clear();
}

// Instanciación explícita de templates comunes
template class Stack<int>;
template class Stack<double>;
template class Stack<char>;
template class Stack<std::string>;

} // namespace eda
