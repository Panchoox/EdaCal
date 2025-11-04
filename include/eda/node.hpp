#include <cstddef>

namespace eda {
template <typename T>
class LinkedList;
}
#pragma once

#include <memory>
#include <string>

namespace eda {

template <typename T>
class Node {
    friend class LinkedList<T>;
    friend class LinkedList<T>;
public:
    Node();
    
    explicit Node(const T& value);
    
    Node(const Node& other);
    
    Node& operator=(const Node& other);
    
    ~Node();
    
    T getValue() const;
    
    void setValue(const T& value);
    
    Node* getNext() const;
    
    void setNext(Node* next);

private:
    T data;              
    Node* next;          
};

} // namespace eda
