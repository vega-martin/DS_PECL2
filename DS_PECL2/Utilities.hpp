#ifndef UTILITIES_HPP
#define UTILITIES_HPP
#include "DLList.hpp"
#include "AVLTree.hpp"
#include "Stack.hpp"
#include <string>
using namespace std;

// Global constant variables:
#define PACKAGE_CARGO 4700
#define PACKAGE_CENTRES 9
#define EXTRACTED_PACKAGES 197
#define HUB_CAPACITY 86

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

// Getter + setter methods regarding the other global variables:
int getPackageNumber();
void increasePackageNumber();
int getStepsTaken();
void increaseStepsTaken();

// Other various methods:
AVLTree generatePackageCentres();
DoublyLinkedList generatePackages();
void locateInPC(PackageCenter PC);

#endif // UTILITIES_HPP