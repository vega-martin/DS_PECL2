#include <stdexcept>
#include "Queue.hpp"
using namespace std;

template <typename T>
Queue<T>::Queue() : front(nullptr), rear(nullptr) {}

template <typename T>
bool Queue<T>::isEmpty() const {
    return front == nullptr;
}

template <typename T>
void Queue<T>::enqueue(const T& newElement) {
    Node<T>* newNode = new Node<T>(newElement);
    if (rear == nullptr) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

template <typename T>
T Queue<T>::dequeue() {
    if (isEmpty()) {
        throw std::underflow_error("Empty queue");
    } else {
        T value = front->element;
        Node<T>* temp = front;
        front = front->next;
        delete temp;

        if (front == nullptr) {
            rear = nullptr;
        }

        return value;
    }
}

template <typename T>
void Queue<T>::makeNull() {
    while (!isEmpty()) {
        dequeue();
    }
}

template <typename T>
T Queue<T>::getFront() const {
    if (isEmpty()) {
        throw underflow_error("Empty queue");
    }
    return front->element;
}