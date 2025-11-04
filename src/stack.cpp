#include "eda/stack.hpp"

namespace eda {

template <typename T>
Stack<T>::Stack() : list() {}

template <typename T>
Stack<T>::Stack(const Stack& other) : list(other.list) {}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& other) {
    if (this != &other) {
        list = other.list;
    }
    return *this;
}

template <typename T>
Stack<T>::~Stack() {}

template <typename T>
void Stack<T>::push(const T& value) {
    list.pushFront(value);
}

template <typename T>
void Stack<T>::pop() {
    list.popFront();
}

template <typename T>
T Stack<T>::top() const {
    return list.front();
}

template <typename T>
bool Stack<T>::isEmpty() const {
    return list.isEmpty();
}

template <typename T>
std::size_t Stack<T>::size() const {
    return list.size();
}

template <typename T>
void Stack<T>::clear() {
    list.clear();
}

template class Stack<int>;
template class Stack<double>;
template class Stack<char>;
template class Stack<std::string>;

} // namespace eda
