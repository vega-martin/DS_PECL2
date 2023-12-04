#ifndef DLLIST_HPP
#define DLLIST_HPP
#include "Package.hpp"

struct DoublyNode {
    Package element;
    DoublyNode* prev;
    DoublyNode* next;

    DoublyNode(const Package& value) : element(value), prev(nullptr), next(nullptr) {}
};


class DoublyLinkedList {
private:
    DoublyNode* head;
    DoublyNode* tail;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void insertFront(const Package& element);
    void insertBack(const Package& element);
    Package removeFront();
    Package removeBack();
    bool isEmpty() const;
    void makeNull();
    Package getFront() const;
    Package getBack() const;
};

#endif // DLLIST_HPP
