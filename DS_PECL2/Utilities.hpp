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


AVLTree generatePackageCenters();

DoublyLinkedList generatePackages();

template <typename N>
void locateInPC(PackageCenter<N> PC);

#endif // UTILITIES_HPP
