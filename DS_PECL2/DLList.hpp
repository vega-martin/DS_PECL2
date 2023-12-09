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
    
    Package searchPackage(const string& labelID);
    
    // New method to calculate the length of the list
    int length() const;
};

#endif // DLLIST_HPP
