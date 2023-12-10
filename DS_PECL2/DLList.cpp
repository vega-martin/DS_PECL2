#include "DLList.hpp"
using namespace std;

DLList::DLList() : head(nullptr), tail(nullptr) {}

DoublyNode* DLList::getHead() const {
    return head;
}

void DLList::insertFront(const Package& element) {
    DoublyNode* newNode = new DoublyNode(element);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void DLList::insertBack(const Package& element) {
    DoublyNode* newNode = new DoublyNode(element);
    if (tail == nullptr) {
        head = tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

Package DLList::removeFront() {
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

Package DLList::removeBack() {
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

bool DLList::isEmpty() const {
    return head == nullptr;
}

void DLList::makeNull() {
    while (!isEmpty()) {
        removeFront();
    }
}

Package DLList::getFront() const {
    if (isEmpty()) {
        throw std::underflow_error("Empty list");
    }
    return head->element;
}

Package DLList::getBack() const {
    if (isEmpty()) {
        throw std::underflow_error("Empty list");
    }
    return tail->element;
}

int DLList::length() const {
    int count = 0;
    DoublyNode* current = head;

    while (current != nullptr) {
        count++;
        current = current->next;
    }

    return count;
}

int DLList::searchPackageByNum(string strNum) {
    if (isEmpty()) {
        return 0; // Empty list, can't be found
    }

    // We traverse the list:
    DoublyNode* current = getHead();

    while (current != nullptr) {
        if (current->element.getLabel().packageId.substr(0, 4) == strNum) {
            return 1; // Found the element
        }
        current = current->next;
    }
    delete current;
    return 0; // Element not found in the list
}
