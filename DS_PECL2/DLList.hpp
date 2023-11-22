#ifndef DLLIST_HPP
#define DLLIST_HPP

template <typename T>
struct DoublyNode {
    T element;
    DoublyNode<T>* prev;
    DoublyNode<T>* next;

    DoublyNode(const T& value) : element(value), prev(nullptr), next(nullptr) {}
};

template <typename T>
class DoublyLinkedList {
private:
    DoublyNode<T>* head;
    DoublyNode<T>* tail;

public:
    DoublyLinkedList();
    ~DoublyLinkedList(); // Destructor to clean up memory
    void insertFront(const T& element);
    void insertBack(const T& element);
    T removeFront();
    T removeBack();
    bool isEmpty() const;
    void makeNull();
    T getFront() const;
    T getBack() const;
};

#endif // DLLIST_HPP
