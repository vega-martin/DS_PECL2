#ifndef QUEUE_HPP
#define QUEUE_HPP

template <typename T>
struct Node {
    T element;
    Node<T>* next;
    Node(const T& value) : element(value), next(nullptr) {}
};

template <typename T>
class Queue {
private:
    Node<T>* front;
    Node<T>* rear;

public:
    Queue();
    void enqueue(const T& newElement);
    T dequeue();
    bool isEmpty() const;
    void makeNull();
    T getFront() const;
};

#endif // QUEUE_HPP