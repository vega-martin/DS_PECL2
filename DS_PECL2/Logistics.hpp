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

// Show package information:
void getNextPackages(const string& postalCode);

// Stadistics methods:
int countPackagesInPC(const string& postalCode);
void printNumPackagesPC();


#endif // LOGISTICS_HPP
