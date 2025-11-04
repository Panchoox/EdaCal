#pragma once

#include "node.hpp"
#include <cstddef>

namespace eda {

template <typename T>
class LinkedList {
public:
    LinkedList();
    
    LinkedList(const LinkedList& other);
    
    LinkedList& operator=(const LinkedList& other);
    
    ~LinkedList();
    
    void pushFront(const T& value);
    
    void pushBack(const T& value);
    
    void popFront();
    
    void popBack();
    
    T front() const;
    
    T back() const;
    
    bool isEmpty() const;
    
    std::size_t size() const;
    
    void clear();

private:
    Node<T>* head;       
    Node<T>* tail;       
    std::size_t count;   
};

} // namespace eda
