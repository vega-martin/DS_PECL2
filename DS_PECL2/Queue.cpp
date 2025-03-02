#include <stdexcept>
#include "Queue.hpp"
using namespace std;

Queue::Queue() : front(nullptr), rear(nullptr) {}

bool Queue::isEmpty() const {
    return front == nullptr;
}

void Queue::enqueue(const Package& newElement) {
    QueueNode* newNode = new QueueNode(newElement);
    if (rear == nullptr) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

Package Queue::dequeue() {
    if (isEmpty()) {
        throw std::underflow_error("Empty queue");
    } else {
        Package value = front->element;
        QueueNode* temp = front;
        front = front->next;
        delete temp;

        if (front == nullptr) {
            rear = nullptr;
        }

        return value;
    }
}

void Queue::makeNull() {
    while (!isEmpty()) {
        dequeue();
    }
}

Package Queue::getFront() const {
    if (isEmpty()) {
        throw underflow_error("Empty queue");
    }
    return front->element;
}

int Queue::length(){
    int counter = 0;
    QueueNode* current = front;

    while (current != nullptr) {
        counter++;
        current = current->next;
    }

    return counter;
}

int Queue::searchPackageByNum(string strNum) {
    if (isEmpty()) {
        return 0; // Empty queue, can't be found
    }

    QueueNode* current = front;

    while (current != nullptr) {
        if (current->element.getLabel().packageId.substr(0, 4) == strNum) {
            return 1; // Found the element
        }
        current = current->next;
    }

    return 0; // Element not found in the queue
}
