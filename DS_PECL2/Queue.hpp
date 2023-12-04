#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "Package.hpp"

struct QueueNode {
    Package element;
    QueueNode* next;
    QueueNode(const Package& value) : element(value), next(nullptr) {}
};

class Queue {
private:
    QueueNode* front;
    QueueNode* rear;

public:
    Queue();
    void enqueue(const Package& newElement);
    Package dequeue();
    bool isEmpty() const;
    void makeNull();
    Package getFront() const;
};

#endif // QUEUE_HPP