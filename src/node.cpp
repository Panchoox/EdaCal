#include "eda/node.hpp"

namespace eda {

template <typename T>
Node<T>::Node() : data(), next(nullptr) {
}

template <typename T>
Node<T>::Node(const T& value) : data(value), next(nullptr) {
}

template <typename T>
Node<T>::Node(const Node& other) : data(other.data), next(nullptr) {
}

template <typename T>
Node<T>& Node<T>::operator=(const Node& other) {
    if (this != &other) {
        data = other.data;
    }
    return *this;
}

template <typename T>
Node<T>::~Node() {
}

template <typename T>
T Node<T>::getValue() const {
    return data;
}

template <typename T>
void Node<T>::setValue(const T& value) {
    data = value;
}

template <typename T>
Node<T>* Node<T>::getNext() const {
    return next;
}

template <typename T>
void Node<T>::setNext(Node* next) {
    this->next = next;
}

template class Node<int>;
template class Node<double>;
template class Node<char>;
template class Node<std::string>;

} // namespace eda
