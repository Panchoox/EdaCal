#include "eda/linked_list.hpp"

namespace eda {

// Constructor por defecto
template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), count(0) {
    // TODO: Implementar
}

// Constructor de copia
template <typename T>
LinkedList<T>::LinkedList(const LinkedList& other) : head(nullptr), tail(nullptr), count(0) {
    // TODO: Implementar copia profunda
}

// Operador de asignación
template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& other) {
    // TODO: Implementar
    if (this != &other) {
        clear();
        // Copiar elementos de other
    }
    return *this;
}

// Destructor
template <typename T>
LinkedList<T>::~LinkedList() {
    // TODO: Implementar
    clear();
}

// Insertar un elemento al inicio
template <typename T>
void LinkedList<T>::pushFront(const T& value) {
    // TODO: Implementar
}

// Insertar un elemento al final
template <typename T>
void LinkedList<T>::pushBack(const T& value) {
    // TODO: Implementar
}

// Eliminar el elemento al inicio
template <typename T>
void LinkedList<T>::popFront() {
    // TODO: Implementar
}

// Eliminar el elemento al final
template <typename T>
void LinkedList<T>::popBack() {
    // TODO: Implementar
}

// Obtener el elemento al inicio
template <typename T>
T LinkedList<T>::front() const {
    // TODO: Implementar
    return T();
}

// Obtener el elemento al final
template <typename T>
T LinkedList<T>::back() const {
    // TODO: Implementar
    return T();
}

// Verificar si la lista está vacía
template <typename T>
bool LinkedList<T>::isEmpty() const {
    // TODO: Implementar
    return head == nullptr;
}

// Obtener el tamaño de la lista
template <typename T>
std::size_t LinkedList<T>::size() const {
    // TODO: Implementar
    return count;
}

// Limpiar la lista
template <typename T>
void LinkedList<T>::clear() {
    // TODO: Implementar
    // Liberar todos los nodos
}

// Instanciación explícita de templates comunes
template class LinkedList<int>;
template class LinkedList<double>;
template class LinkedList<char>;
template class LinkedList<std::string>;

} // namespace eda
