#ifndef DLLIST_HPP
#define DLLIST_HPP
#include "Package.hpp"

struct DoublyNode {
    Package element;
    DoublyNode* prev;
    DoublyNode* next;

    DoublyNode(const Package& value) : element(value), prev(nullptr), next(nullptr) {}
};


class DLList {
private:
    DoublyNode* head;
    DoublyNode* tail;

public:
    DLList();
    DoublyNode* getHead() const;
    void insertFront(const Package& element);
    void insertBack(const Package& element);
    Package removeFront();
    Package removeBack();
    bool isEmpty() const;
    void makeNull();
    Package getFront() const;
    Package getBack() const;
    
    // We must extend the basic implementation of a stack with these methods:
    int length() const;  
    int searchPackageByNum(string strNum);
    void deleteNode(string strNum);
};

#endif // DLLIST_HPP
