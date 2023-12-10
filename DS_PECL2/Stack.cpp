#include <stdexcept>
#include "Stack.hpp"
#include "Utilities.hpp"
#include <iostream>
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

// The basic stack implementation was extended with these methods:

int Stack::length(){
    int counter = 0;
    StackNode* current = top;

    while (current != nullptr) {
        counter++;
        current = current->next;
    }
    free(current);
    return counter;
}

/* Watch out! The stack will technically never get full, as its implementation is dynamic. Still, 
 * the exercise requires the stack to have a max capacity. Therefore, this method is a must. */

bool Stack::isFull(){
    return (length() >= HUB_CAPACITY);
}

int Stack::searchPackageByNum(string strNum){
    if (isEmpty()) {
        return 0; // Empty list, can't be found
    }
    
    // We traverse the list:
    StackNode* current = top;
    
    while (current->element.getLabel().packageId.substr(0,4) != strNum) {
        current = current->next;
    }
    if (current->element.getLabel().packageId.substr(0,4) == strNum) {
        delete current;
        return 1; // Found the element
    }
    return 0; // Element not found in the list
}