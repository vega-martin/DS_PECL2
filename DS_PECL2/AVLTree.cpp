#include "AVLTree.hpp"
#include <algorithm>
#include <iostream>

AVLTree::AVLTree() : root(nullptr) {}

// Function to get the height of a node
int AVLTree::height(avlNode* node) {
    return node ? node->height : 0;
}

// Function to get the balance factor of a node
int AVLTree::balanceFactor(avlNode* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

// Function to rotate the subtree rooted at y to the right
avlNode* AVLTree::rotateRight(avlNode* y) {
    avlNode* x = y->left;
    avlNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;

    return x;
}

// Function to rotate the subtree rooted at x to the left
avlNode* AVLTree::rotateLeft(avlNode* x) {
    avlNode* y = x->right;
    avlNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(height(y->left), height(y->right)) + 1;

    return y;
}

// Function to insert a new PackageCenter into the AVL tree
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

// Public function to insert a new PackageCenter into the AVL tree
void AVLTree::insert(const PackageCenter& PC) {
    root = insert(root, PC);
}

// Helper function to find a node with a specific postal code
avlNode* AVLTree::findNode(avlNode* node, const string& postalCode) {
    if (node == nullptr) {
        return nullptr; // Node not found
    }

    if (postalCode < node->PC.postalCode) {
        return findNode(node->left, postalCode);
    } else if (postalCode > node->PC.postalCode) {
        return findNode(node->right, postalCode);
    } else {
        return node; // Node with the specified postal code found
    }
}

// Modified postOrderTraversalSearch method
void AVLTree::postOrderTraversalSearch(avlNode* node, const string& postalCode) {
    if (node != nullptr) {
        postOrderTraversalSearch(node->left, postalCode);
        postOrderTraversalSearch(node->right, postalCode);
        
        // Process the node here (e.g., compare postalCode with node->PC.postalCode)
        if (node->PC.postalCode.compare(postalCode) == 0) {
            // Do something with the found node
            std::cout << "Found: " << node->PC.postalCode << std::endl;
        }
    }
}

// Wrapper function that calls the modified postOrderTraversalSearch
void AVLTree::searchPackageCentre(const string& postalCode) {
    avlNode* targetNode = findNode(root, postalCode);

    if (targetNode != nullptr) {
        postOrderTraversalSearch(targetNode, postalCode);
    } else {
        std::cout << "Node with postal code " << postalCode << " not found." << std::endl;
    }
}

PackageCenter AVLTree::getPC(const string& postalCode) {
    avlNode* targetNode = findNode(root, postalCode);
    return targetNode->PC;
}

// Modified postOrderTraversalSearch method
void AVLTree::postOrderTraversalSearch2(avlNode* node) {
    if (node != nullptr) {
        postOrderTraversalSearch2(node->left);
        postOrderTraversalSearch2(node->right);
        std::cout << "Found: " << node->PC.postalCode << std::endl;
    }
}

// Wrapper function that calls the modified postOrderTraversalSearch
void AVLTree::searchPackageCentre2() {
    postOrderTraversalSearch2(root);
}