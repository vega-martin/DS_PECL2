#include "AVLTree.hpp"
#include <algorithm>
#include <iostream>

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

avlNode* AVLTree::insert(avlNode* node, const PackageCenter& PC) {
    if (node == nullptr) {
        return new avlNode(PC);
    }

    if (PC.postalCode < node->PC.postalCode) {
        node->left = insert(node->left, PC);
    } else if (PC.postalCode > node->PC.postalCode) {
        node->right = insert(node->right, PC);
    } else {
        // Duplicate keys are not allowed in this example
        return node;
    }

    node->height = std::max(height(node->left), height(node->right)) + 1;

    int balance = balanceFactor(node);

    // Left Heavy
    if (balance > 1) {
        if (PC.postalCode < node->left->PC.postalCode) {
            return rotateRight(node);
        } else {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
    }

    // Right Heavy
    if (balance < -1) {
        if (PC.postalCode > node->right->PC.postalCode) {
            return rotateLeft(node);
        } else {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
    }

    return node;
}

void AVLTree::insert(const PackageCenter& PC) {
    root = insert(root, PC);
}

void AVLTree::postOrderTraversal(avlNode* node, string postalCode) {
    // No se muy bn qué hacer aquí xq e error está dfinitivamente en el return
    // Asiq podemos pasar el paquete en vez de el codigo postal y que lo
    // introduzca directamente o no se q hacer. Por que hay que tener en 
    // cuenta que este método se supone q tambien se tiene que usar para otras
    // cosas como las estadíticas.
    //if (postalCode == node->PC.postalCode){}
    if (node != nullptr) {
        postOrderTraversal(node->left, postalCode);
        postOrderTraversal(node->right, postalCode);
    }
}

void AVLTree::postOrderTraversalSearch(string postalCode) {
    postOrderTraversal(root, postalCode);
}