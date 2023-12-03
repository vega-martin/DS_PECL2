#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

class AVLTree {
private:
    struct Node {
        int key;
        Node* left;
        Node* right;
        int height;
        Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
    };

    Node* root;

    int height(Node* node);
    int balanceFactor(Node* node);
    Node* rotateRight(Node* y);
    Node* rotateLeft(Node* x);
    Node* insert(Node* node, int key);
    void postOrderTraversal(Node* node, void (*visit)(int));

public:
    AVLTree();
    void insert(int key);
    void postOrderTraversal(void (*visit)(int));
};

#endif // AVL_TREE_HPP
