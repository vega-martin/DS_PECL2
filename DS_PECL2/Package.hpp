#ifndef PACKAGE_HPP
#define PACKAGE_HPP
#include <string>
#include <random>
using namespace std;

enum Status {SPCS, Hub, Delivered};
    
struct Label {
    string packageId;
    struct Coords {
        string latitude;
        string longitude;
    } coordinates;
    string clientId;
};

class Package {
    
private:
    
    Status status;
    Label label;
     
    string generateDate(); 
    string cpPackageAssignment();
    string postalCodeAssignment(const Label::Coords &coordinates);
     
    string generateClientId();
    Label::Coords generateCoordinates();
    string generateLabelId(const Label::Coords &coordinates);    

public:

    Package();
    static thread_local mt19937 gen;
    Status getStatus();
    void setStatus(Status newStatus);
    Label getLabel();
    void setPackageId(string newPackageId);
    void setClientId(std::string id);
    
   

};

#endif // PACKAGE_HPP