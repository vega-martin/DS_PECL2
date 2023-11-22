#ifndef BST_HPP
#define BST_HPP

template <class T>
class Node {
public:
    T data;
    Node* left;
    Node* right;

    Node(T value) : data(value), left(nullptr), right(nullptr) {}
};

template <class T>
class BinarySearchTree {
private:
    Node<T>* root;

    void insert(Node<T>*& node, T value);
    void postOrderTraversal(Node<T>* node);

public:
    BinarySearchTree() : root(nullptr) {}
    ~BinarySearchTree();

    void insert(T value);
    void postOrderTraversal();
};

#endif