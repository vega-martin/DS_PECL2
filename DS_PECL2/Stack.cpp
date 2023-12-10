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

int Stack::searchPackageByNum(string strNum) {
    if (isEmpty()) {
        return 0; // Empty stack, can't be found
    }

    StackNode* current = top;

    while (current != nullptr) {
        if (current->element.getLabel().packageId.substr(0, 4) == strNum) {
            return 1; // Found the element
        }
        current = current->next;
    }
    delete current;
    return 0; // Element not found in the stack
}

void Stack::deleteNode(string strNum){
    if (isEmpty()) {
        return; // Empty stack, can't be deleted
    }

    StackNode* prev = nullptr;
    StackNode* current = top;

    // Special case: the node we are looking for is the first one
    if (current->element.getLabel().packageId.substr(0, 4) == strNum) {
        top = current->next;
        delete current;
        return;
    }

    // Search for the node
    while (current != nullptr && current->element.getLabel().packageId.substr(0, 4) != strNum) {
        prev = current;
        current = current->next;
    }

    // If the node wasn't found
    if (current == nullptr) {
        return;
    }

    // Adjust pointers and delete node
    prev->next = current->next;
    delete current;
    
}