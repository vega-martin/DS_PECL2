template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    makeNull(); // Clean up memory when the list is destroyed
}

template <typename T>
void DoublyLinkedList<T>::insertFront(const T& element) {
    DoublyNode<T>* newNode = new DoublyNode<T>(element);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

template <typename T>
void DoublyLinkedList<T>::insertBack(const T& element) {
    DoublyNode<T>* newNode = new DoublyNode<T>(element);
    if (tail == nullptr) {
        head = tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

template <typename T>
T DoublyLinkedList<T>::removeFront() {
    if (isEmpty()) {
        throw std::underflow_error("Empty list");
    }

    T value = head->element;
    DoublyNode<T>* temp = head;
    head = head->next;

    if (head == nullptr) {
        tail = nullptr;
    } else {
        head->prev = nullptr;
    }

    delete temp;
    return value;
}

template <typename T>
T DoublyLinkedList<T>::removeBack() {
    if (isEmpty()) {
        throw std::underflow_error("Empty list");
    }

    T value = tail->element;
    DoublyNode<T>* temp = tail;
    tail = tail->prev;

    if (tail == nullptr) {
        head = nullptr;
    } else {
        tail->next = nullptr;
    }

    delete temp;
    return value;
}

template <typename T>
bool DoublyLinkedList<T>::isEmpty() const {
    return head == nullptr;
}

template <typename T>
void DoublyLinkedList<T>::makeNull() {
    while (!isEmpty()) {
        removeFront();
    }
}

template <typename T>
T DoublyLinkedList<T>::getFront() const {
    if (isEmpty()) {
        throw std::underflow_error("Empty list");
    }
    return head->element;
}

template <typename T>
T DoublyLinkedList<T>::getBack() const {
    if (isEmpty()) {
        throw std::underflow_error("Empty list");
    }
    return tail->element;
}