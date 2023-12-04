#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

struct avlNode {
        int key;
        avlNode* left;
        avlNode* right;
        int height;
        avlNode(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:

    avlNode* root;

    int height(avlNode* node);
    int balanceFactor(avlNode* node);
    avlNode* rotateRight(avlNode* y);
    avlNode* rotateLeft(avlNode* x);
    avlNode* insert(avlNode* node, int key);
    void postOrderTraversal(avlNode* node, void (*visit)(int));

public:
    AVLTree();
    void insert(int key);
    void postOrderTraversal(void (*visit)(int));
};

#endif // AVL_TREE_HPP
