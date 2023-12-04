#include "AVLTree.hpp"
#include <algorithm>

AVLTree::AVLTree() : root(nullptr) {}

int AVLTree::height(avlNode* node) {
    return node ? node->height : 0;
}

int AVLTree::balanceFactor(avlNode* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

avlNode* AVLTree::rotateRight(avlNode* y) {
    avlNode* x = y->left;
    avlNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;

    return x;
}

avlNode* AVLTree::rotateLeft(avlNode* x) {
    avlNode* y = x->right;
    avlNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(height(y->left), height(y->right)) + 1;

    return y;
}

avlNode* AVLTree::insert(avlNode* node, int key) {
    if (node == nullptr) {
        return new avlNode(key);
    }

    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    } else {
        // Duplicate keys are not allowed in this example
        return node;
    }

    node->height = std::max(height(node->left), height(node->right)) + 1;

    int balance = balanceFactor(node);

    // Left Heavy
    if (balance > 1) {
        if (key < node->left->key) {
            return rotateRight(node);
        } else {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
    }

    // Right Heavy
    if (balance < -1) {
        if (key > node->right->key) {
            return rotateLeft(node);
        } else {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
    }

    return node;
}

void AVLTree::insert(int key) {
    root = insert(root, key);
}

void AVLTree::postOrderTraversal(avlNode* node, void (*visit)(int)) {
    if (node != nullptr) {
        postOrderTraversal(node->left, visit);
        postOrderTraversal(node->right, visit);
        visit(node->key);
    }
}

void AVLTree::postOrderTraversal(void (*visit)(int)) {
    postOrderTraversal(root, visit);
}
