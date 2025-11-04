#include "eda/stack.hpp"

namespace eda {

// Constructor por defecto
template <typename T>
Stack<T>::Stack() : list() {}

// Constructor de copia
template <typename T>
Stack<T>::Stack(const Stack& other) : list(other.list) {}

// Operador de asignación
template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& other) {
    if (this != &other) {
        list = other.list;
    }
    return *this;
}

// Destructor
template <typename T>
Stack<T>::~Stack() {}

// Insertar un elemento en la cima
template <typename T>
void Stack<T>::push(const T& value) {
    list.pushFront(value);
}

// Eliminar el elemento en la cima
template <typename T>
void Stack<T>::pop() {
    list.popFront();
}

// Obtener el elemento en la cima
template <typename T>
T Stack<T>::top() const {
    return list.front();
}

// Verificar si la pila está vacía
template <typename T>
bool Stack<T>::isEmpty() const {
    return list.isEmpty();
}

// Obtener el tamaño de la pila
template <typename T>
std::size_t Stack<T>::size() const {
    return list.size();
}

// Limpiar la pila
template <typename T>
void Stack<T>::clear() {
    list.clear();
}

// Instanciación explícita de templates comunes
template class Stack<int>;
template class Stack<double>;
template class Stack<char>;
template class Stack<std::string>;

} // namespace eda
