#include "DLList.hpp"

DoublyNode::DoublyNode(const Package& value) : element(value), prev(nullptr), next(nullptr) {}

DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

DoublyLinkedList::~DoublyLinkedList() {
    makeNull();
}

void DoublyLinkedList::insertFront(const Package& element) {
    DoublyNode* newNode = new DoublyNode(element);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void DoublyLinkedList::insertBack(const Package& element) {
    DoublyNode* newNode = new DoublyNode(element);
    if (tail == nullptr) {
        head = tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

Package DoublyLinkedList::removeFront() {
    if (isEmpty()) {
        throw std::underflow_error("Empty list");
    }

    Package value = head->element;
    DoublyNode* temp = head;
    head = head->next;

    if (head == nullptr) {
        tail = nullptr;
    } else {
        head->prev = nullptr;
    }

    delete temp;
    return value;
}

Package DoublyLinkedList::removeBack() {
    if (isEmpty()) {
        throw std::underflow_error("Empty list");
    }

    Package value = tail->element;
    DoublyNode* temp = tail;
    tail = tail->prev;

    if (tail == nullptr) {
        head = nullptr;
    } else {
        tail->next = nullptr;
    }

    delete temp;
    return value;
}

bool DoublyLinkedList::isEmpty() const {
    return head == nullptr;
}

void DoublyLinkedList::makeNull() {
    while (!isEmpty()) {
        removeFront();
    }
}

Package DoublyLinkedList::getFront() const {
    if (isEmpty()) {
        throw std::underflow_error("Empty list");
    }
    return head->element;
}

Package DoublyLinkedList::getBack() const {
    if (isEmpty()) {
        throw std::underflow_error("Empty list");
    }
    return tail->element;
}
