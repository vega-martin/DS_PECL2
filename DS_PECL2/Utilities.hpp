#ifndef UTILITIES_HPP
#define UTILITIES_HPP
#include <string>
#include "AVLTree.hpp"
#include "Stack.hpp"
#include "DLList.hpp"
using namespace std;

struct Coords {
    string latitude;
    string longitude;
};

template <typename T> 
struct PackageCenter {
    int key;
    string postalCode;
    string acronym;
    Coords coordinates;
    Stack<T> hub;
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

template <typename N>
void locateInPC(PackageCenter<N> PC);

#endif // UTILITIES_HPP
