#ifndef UTILITIES_HPP
#define UTILITIES_HPP
#include "DLList.hpp"
#include "AVLTree.hpp"
#include <string>
using namespace std;

struct PackageCenter {
    int key;
    string postalCode;
    string acronym;
    Coords coordinates;
    //Stack hub;
};

// GLOBAL VARIABLES HOLDING LOGISTICS' INFOR:
extern string postalCodes[9];
extern string acronyms[9];
extern Coords coordinates[9];

// GETTER METHODS FOR THESE PREVIOUS ARRAYS:
const string* getPostalCodes();
const string* getAcronyms();
const Coords* getCoordinates();


AVLTree generatePackageCenters();

DoublyLinkedList generatePackages();

void locateInPC(PackageCenter PC);

#endif // UTILITIES_HPP
