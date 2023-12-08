#include "Utilities.hpp"
#include "Package.hpp"
#include <string>
using namespace std;

// Global variables initialisation:
string postalCodes[9] = {"37715","37427","37449","37893","37797","37796","37129","37340","37001"};
string acronyms[9] = {"ADT","PER","ROD","VDT","CDV","MOZ","CDB","ALD","SAL"};
Coords coordinates[9] = {{"41.063717","-5.821883"},
                         {"41.061974","-5.549179"},
                         {"40.904188","-5.817388"},
                         {"40.892504","-5.498010"},
                         {"41.051090","-5.693395"},
                         {"40.859055","-5.652303"},
                         {"40.978764","-5.761869"},
                         {"41.006495","-5.500316"},
                         {"40.965059","-5.664039"}};
                         
int packageNumber = 1;
int stepsTaken = 0;

// Getters + setters:        
const string* getPostalCodes() {
    return postalCodes;
}
const string* getAcronyms() {
    return acronyms;
}
const Coords* getCoordinates() {
    return coordinates;
}
int getPackageNumber(){
    return packageNumber;
}
void increasePackageNumber(){
    packageNumber++;
}
int getStepsTaken(){
    return stepsTaken;
}
void increaseStepsTaken(){
    stepsTaken++;
}

// Other methods:
void locateInPC(PackageCenter PC){
    
}
