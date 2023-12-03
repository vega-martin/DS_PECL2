#ifndef STACK_HPP
#define STACK_HPP
#include <stdexcept>

template <typename T>
struct StackNode {
    T element;
    StackNode<T>* next;

    StackNode(const T& value) : element(value), next(nullptr) {}
};

template <typename T>
class Stack {
private:
    StackNode<T>* top;

public:
    Stack();
    void push(const T& element);
    T pop();
    bool isEmpty() const;
    void makeNull();
};

#include "Stack.tpp"

#endif // STACK_HPP