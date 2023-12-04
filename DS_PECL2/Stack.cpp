#include <stdexcept>
#include "Stack.hpp"
using namespace std;

Stack::Stack() : top(nullptr) {}

void Stack::push(const Package& element) {
    StackNode* newNode = new StackNode(element);
    newNode->next = top;
    top = newNode;
}

Package Stack::pop() {
    if (isEmpty()) {
        throw underflow_error("Empty stack");
    }

    Package value = top->element;
    StackNode* temp = top;
    top = top->next;
    delete temp;

    return value;
}

bool Stack::isEmpty() const {
    return top == nullptr;
}

void Stack::makeNull() {
    while (!isEmpty()) {
        pop();
    }
}