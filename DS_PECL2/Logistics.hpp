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
void emptyAllHubs();

// Show package information:
void getNextPackagesToBeDelivered(const string& postalCode);

// Statistics methods:
int countPackagesInPC(const string& postalCode);
void printNumPackagesPC();
void printNumPackagesQueue();
void printLongestHub();
void printShortestHub();
void printFrequencies();

// Search for the location of a package, wherever in the system:
int searchPackage(string label);
void searchAnswer(string label);

// Delete package:
void deletePackage(string label);

//Transport packages form SPCS to a given PC
void fromSPCStoPC(string label, string postalCode);
void fromPCtoPC(string label, string postalCode);


#endif // LOGISTICS_HPP
