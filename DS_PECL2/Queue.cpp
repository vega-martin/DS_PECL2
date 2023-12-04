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