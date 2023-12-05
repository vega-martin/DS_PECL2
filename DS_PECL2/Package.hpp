#ifndef PACKAGE_HPP
#define PACKAGE_HPP
#include <string>
#include <random>
using namespace std;

extern int packageCounter;

enum Status {SPCS, Hub, Delivered};

struct Coords {
    string latitude;
    string longitude;
};

struct PackageLabel {
    string packageId;
    Coords coordinates;
    string clientId;
};

class Package {
private:
    
    Status status;
    PackageLabel label;
     
    string generateDate();
    string postalCodeAssignment(const Coords &coordinates);
     
    string generateClientId();
    Coords generateCoordinates();
    string generatePackageNum();
    string generateLabelId(const Coords &coordinates);    

public:

    Package();
    static thread_local mt19937 gen;
    Status getStatus();
    void setStatus(Status newStatus);
    PackageLabel getLabel();
    void setPackageId(string newPackageId);
    void setClientId(string id);
    
   

};

#endif // PACKAGE_HPP