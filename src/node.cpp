#include "eda/node.hpp"

namespace eda {

// Constructor por defecto
template <typename T>
Node<T>::Node() : data(), next(nullptr) {
    // TODO: Implementar
}

// Constructor con valor
template <typename T>
Node<T>::Node(const T& value) : data(value), next(nullptr) {
    // TODO: Implementar
}

// Constructor de copia
template <typename T>
Node<T>::Node(const Node& other) : data(other.data), next(nullptr) {
    // TODO: Implementar copia profunda si es necesario
}

// Operador de asignación
template <typename T>
Node<T>& Node<T>::operator=(const Node& other) {
    // TODO: Implementar
    if (this != &other) {
        data = other.data;
        // Nota: next no se copia para evitar efectos secundarios
    }
    return *this;
}

// Destructor
template <typename T>
Node<T>::~Node() {
    // TODO: Implementar limpieza si es necesaria
}

// Obtener el valor almacenado
template <typename T>
T Node<T>::getValue() const {
    // TODO: Implementar
    return data;
}

// Establecer el valor almacenado
template <typename T>
void Node<T>::setValue(const T& value) {
    // TODO: Implementar
    data = value;
}

// Obtener puntero al siguiente nodo
template <typename T>
Node<T>* Node<T>::getNext() const {
    // TODO: Implementar
    return next;
}

// Establecer puntero al siguiente nodo
template <typename T>
void Node<T>::setNext(Node* next) {
    // TODO: Implementar
    this->next = next;
}

// Instanciación explícita de templates comunes
template class Node<int>;
template class Node<double>;
template class Node<char>;
template class Node<std::string>;

} // namespace eda
