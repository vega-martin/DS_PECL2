#ifndef UTILITIES_HPP
#define UTILITIES_HPP
#include "Stack.hpp"
#include "Queue.hpp"
#include <string>
using namespace std;

// Global constant variables:
#define PACKAGE_CARGO 4700
#define PACKAGE_CENTRES 9
#define PACKAGES_PER_DELIVERY 197
#define HUB_CAPACITY 86

// Global variables holding logistics' info:
extern string postalCodesArray[9];
extern string acronymsArray[9];
extern Coords coordinatesArray[9];

// Other required global variables:
extern int packageCounter;
extern int stepsTaken;

// Every PC is modelled as follows:
struct PackageCenter {
    string postalCode;
    string acronym;
    Coords coordinates;
    Stack hub;
    Queue auxQueue;
    
    PackageCenter() : postalCode(""), acronym(""), coordinates(), hub(), auxQueue() {}
    
};

#endif // UTILITIES_HPP