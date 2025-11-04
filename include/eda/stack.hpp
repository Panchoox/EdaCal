#pragma once

#include "linked_list.hpp"

namespace eda {

template <typename T>
class Stack {
public:
    Stack();
    
    Stack(const Stack& other);
    
    Stack& operator=(const Stack& other);
    
    ~Stack();
    
    void push(const T& value);
    
    void pop();
    
    T top() const;
    
    bool isEmpty() const;
    
    std::size_t size() const;
    
    void clear();

private:
    LinkedList<T> list;  
};

} // namespace eda
