#ifndef STACK_HPP
#define STACK_HPP

#include "Package.hpp"

struct StackNode {
    Package element;
    StackNode* next;
    StackNode(const Package& value) : element(value), next(nullptr) {}
};

class Stack {
private:
    StackNode* top;

public:
    Stack();
    void push(const Package& element);
    Package pop();
    bool isEmpty() const;
    void makeNull();
    
    // We must extend the basic implementation of a stack with these methods:
    int length();
    bool isFull();
    int searchPackageByNum(string strNum);
    Package removePackage(string strNum);
};

#endif // STACK_HPP