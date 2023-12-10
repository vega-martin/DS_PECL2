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
void getNextPackagesToBeDelivered(const string& postalCode);

// Statistics methods:
int countPackagesInPC(const string& postalCode);
void printNumPackagesPC();

// Search for the location of a package, wherever in the system:
int searchPackage(string label);
void searchAnswer(string label);

// Delete package:
void deletePackage(string label);


#endif // LOGISTICS_HPP
