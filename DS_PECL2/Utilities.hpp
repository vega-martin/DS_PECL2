#ifndef UTILITIES_HPP
#define UTILITIES_HPP
#include "DLList.hpp"
#include "AVLTree.hpp"
#include "Stack.hpp"
#include <string>
using namespace std;

// Global variables holding logistics' info:
extern string postalCodes[9];
extern string acronyms[9];
extern Coords coordinates[9];

// Other required global variables:
extern int packageNumber;
extern int stepsTaken;

// Every PC is modelled as follows:
struct PackageCenter {
    int key;
    string postalCode;
    string acronym;
    Coords coordinates;
    Stack hub;
};

// Getter methods for the logistics' arrays:
const string* getPostalCodes();
const string* getAcronyms();
const Coords* getCoordinates();

// Methods regarding the other global variables:
int getPackageNumber();
void increasePackageNumber();
int getStepsTaken();
void increaseStepsTaken();

// Other various methods:
AVLTree generatePackageCenters();
DoublyLinkedList generatePackages();
void locateInPC(PackageCenter PC);

#endif // UTILITIES_HPP