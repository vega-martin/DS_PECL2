#ifndef LOGISTICS_HPP
#define LOGISTICS_HPP
#include "AVLTree.hpp"
#include "DLList.hpp"

extern AVLTree pcTree;
extern DLList packageList;

// Methods to create:    
void generatePackageCentres();
void generatePackages();

// Methods to move packages:
void packageDelivery();


#endif // LOGISTICS_HPP
