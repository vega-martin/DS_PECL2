#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP
#include "Utilities.hpp"

struct avlNode {
        PackageCenter PC;
        avlNode* left;
        avlNode* right;
        int height;
        avlNode(const PackageCenter& pc) : PC(pc), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:

    avlNode* root;

    int height(avlNode* node);
    int balanceFactor(avlNode* node);
    avlNode* rotateRight(avlNode* y);
    avlNode* rotateLeft(avlNode* x);
    avlNode* insert(avlNode* node, const PackageCenter& PC);
    void postOrderTraversal(avlNode* node, string postalCode);

public:
    AVLTree();
    void insert(const PackageCenter& PC);
    void postOrderTraversalSearch(string postalCode);
};

#endif // AVL_TREE_HPP
