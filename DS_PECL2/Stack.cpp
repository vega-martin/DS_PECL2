#include <stdexcept>
#include "Stack.hpp"
using namespace std;

template <typename T>
Stack<T>::Stack() : top(nullptr) {}

template <typename T>
void Stack<T>::push(const T& element) {
    StackNode<T>* newNode = new StackNode<T>(element);
    newNode->next = top;
    top = newNode;
}

template <typename T>
T Stack<T>::pop() {
    if (isEmpty()) {
        throw underflow_error("Empty stack");
    }

    T value = top->element;
    StackNode<T>* temp = top;
    top = top->next;
    delete temp;

    return value;
}

template <typename T>
bool Stack<T>::isEmpty() const {
    return top == nullptr;
}

template <typename T>
void Stack<T>::makeNull() {
    while (!isEmpty()) {
        pop();
    }
}
