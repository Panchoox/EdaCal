#include "eda/linked_list.hpp"
#include <stdexcept>
#include "eda/linked_list.hpp"

namespace eda {

// Constructor por defecto
template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), count(0) {}

// Constructor de copia
template <typename T>
LinkedList<T>::LinkedList(const LinkedList& other) : head(nullptr), tail(nullptr), count(0) {
    Node<T>* curr = other.head;
    while (curr) {
        pushBack(curr->data);
        curr = curr->next;
    }
}

// Operador de asignación
template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& other) {
    if (this != &other) {
        clear();
        Node<T>* curr = other.head;
        while (curr) {
            pushBack(curr->data);
            curr = curr->next;
        }
    }
    return *this;
}

// Destructor
template <typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

// Insertar un elemento al inicio
template <typename T>
void LinkedList<T>::pushFront(const T& value) {
    Node<T>* newNode = new Node<T>(value);
    newNode->next = head;
    head = newNode;
    if (!tail) tail = newNode;
    ++count;
}

// Insertar un elemento al final
template <typename T>
void LinkedList<T>::pushBack(const T& value) {
    Node<T>* newNode = new Node<T>(value);
    if (!tail) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    ++count;
}

// Eliminar el elemento al inicio
template <typename T>
void LinkedList<T>::popFront() {
    if (!head) return;
    Node<T>* temp = head;
    head = head->next;
    delete temp;
    --count;
    if (!head) tail = nullptr;
}

// Eliminar el elemento al final
template <typename T>
void LinkedList<T>::popBack() {
    if (!head) return;
    if (head == tail) {
        delete head;
        head = tail = nullptr;
    } else {
        Node<T>* curr = head;
        while (curr->next != tail) curr = curr->next;
        delete tail;
        tail = curr;
        tail->next = nullptr;
    }
    --count;
}

// Obtener el elemento al inicio
template <typename T>
T LinkedList<T>::front() const {
    if (!head) throw std::runtime_error("Lista vacía");
    return head->data;
}

// Obtener el elemento al final
template <typename T>
T LinkedList<T>::back() const {
    if (!tail) throw std::runtime_error("Lista vacía");
    return tail->data;
}

// Verificar si la lista está vacía
template <typename T>
bool LinkedList<T>::isEmpty() const {
    return head == nullptr;
}

// Obtener el tamaño de la lista
template <typename T>
std::size_t LinkedList<T>::size() const {
    return count;
}

// Limpiar la lista
template <typename T>
void LinkedList<T>::clear() {
    while (head) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    count = 0;
}

// Instanciación explícita de templates comunes
template class LinkedList<int>;
template class LinkedList<double>;
template class LinkedList<char>;
template class LinkedList<std::string>;

} // namespace eda
