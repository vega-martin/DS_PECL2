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

// The basic stack implementation was extended with these methods:

int Stack::length(){
    int counter = 0;
    StackNode* current = top;

    while (current != nullptr) {
        counter++;
        current = current->next;
    }

    return counter;
}

/* Watch out! The stack will technically never get full, as its implementation is dynamic. Still, 
 * the exercise requires the stack to have a max capacity, hence this method is a must. */
// OJO VEGA: EL 23 ES LA CONSTANTE QUE NECESITEMOS, NO ME ACUERDO AHORA (BORRA ESTO CUANDO LO VEAS)
bool Stack::isFull(){
    return (length() >= 23);
}