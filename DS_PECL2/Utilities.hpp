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
extern string postalCodes[9];
extern string acronyms[9];
extern Coords coordinates[9];

// Other required global variables:
extern int packageNumber;
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

// Getter methods for the logistics' arrays:
const string* getPostalCodes();
const string* getAcronyms();
const Coords* getCoordinates();

// Getter + setter methods regarding the other global variables:
int getPackageNumber();
void increasePackageNumber();
int getStepsTaken();
void increaseStepsTaken();


#endif // UTILITIES_HPP