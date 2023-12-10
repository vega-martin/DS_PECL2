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

    //Private attributes:
    avlNode* root;
    int height(avlNode* node);
    int balanceFactor(avlNode* node);
    
    //Private balancing methods:
    avlNode* rotateRight(avlNode* y);
    avlNode* rotateLeft(avlNode* x);
    
    //Internal insert method:
    avlNode* insert(avlNode* node, const PackageCenter& PC);

    //Helper method to find the node corresponding to a given postalCode:
    avlNode* findNode(avlNode* node, const string& postalCode);
    
    //Internal traversing method:
    void postOrderTraversalSearch(avlNode* node, const string& postalCode);

public:
    AVLTree();
    
    //Public methods:
    void insert(const PackageCenter& PC);
    void searchPackageCentre(const string& postalCode);
    PackageCenter& getPC(const string& postalCode);
};

#endif // AVL_TREE_HPP