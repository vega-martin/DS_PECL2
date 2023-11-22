#include "BSTree.hpp"
#include <iostream>

template <class T>
BinarySearchTree<T>::~BinarySearchTree() {
    // Implement a function to delete all nodes and free memory
}

template <class T>
void BinarySearchTree<T>::insert(Node<T>*& node, T value) {
    if (node == nullptr) {
        node = new Node<T>(value);
    } else {
        if (value < node->data) {
            insert(node->left, value);
        } else {
            insert(node->right, value);
        }
    }
}

template <class T>
void BinarySearchTree<T>::insert(T value) {
    insert(root, value);
}

template <class T>
void BinarySearchTree<T>::postOrderTraversal(Node<T>* node) {
    if (node != nullptr) {
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        std::cout << node->data << " ";
    }
}

template <class T>
void BinarySearchTree<T>::postOrderTraversal() {
    postOrderTraversal(root);
    std::cout << std::endl;
}
