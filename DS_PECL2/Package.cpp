#include <ctime>
#include <random>
#include "Package.hpp"
#include "Utilities.hpp"
using namespace std;

thread_local mt19937 Package::gen(random_device{}());

// This method randomizes three one-digit numbers and one letter, then concatenates them:
string randNumbersAndLetter() {
    
    uniform_int_distribution<int> numDistribution(0, 9);
    uniform_int_distribution<int> letterDistribution(0, 25);
    string result;
    
    for (int i = 0; i < 3; ++i) {
        result += to_string(numDistribution(Package::gen));
    }

    int randomIndex = letterDistribution(Package::gen);
    char alphabet[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    result += alphabet[randomIndex];

    return result;
}

Coords Package::generateCoordinates(){
    
    uniform_real_distribution<double> distributionLat(40.854057, 41.070999);
    double lat = distributionLat(gen); 
    int latD = (int)lat;
    int latM = (int) ((lat - (double)latD) * 60.f);
    int latS = (int) (((lat - (double)latD) * 60.f - (double)latM) * 60.f);
        
    uniform_real_distribution<double> distributionLon(-5.837731, -5.483050);
    double lon = distributionLon(gen);
    int lonD = (int)lon;
    int lonM = (int) ((lon - (double)lonD) * 60.f);
    int lonS = (int) (((lon - (double)lonD) * 60.f - (double)lonM) * 60.f);
    
    Coords coordinates;
    
    coordinates.latitude = to_string(latD) + " " + to_string(latM) + " " + to_string(latS);
    coordinates.longitude = to_string(lonD) + " " + to_string(lonM) + " " + to_string(lonS);
    
    return coordinates;
    
}

string Package::generateDate(){
    
    time_t time = std::time(nullptr);
    tm *now = localtime(&time);
    string day = to_string(now->tm_mday);
    while(day.length() < 2){
        day = "0" + day;
    }
    string month = to_string(now->tm_mon + 1);
    while(month.length() < 2){
        month = "0" + month;
    }
    string date = day + month + to_string(now->tm_year + 1900);
    return date;
}

/* This next method may seem somewhat complicated to understand just by looking at its implementation, so allow
 * us to explain it: whenever a package is generated, its coordinates are also randomly obtained (inside the
 * square given to us by the exercise). Most packages, if not all of them, will not fall under the exact Package 
 * Center's postal code, so we have to assign them to a PC. The easiest and most obvious way to solve this is by
 * moving them to the CLOSEST PC. This is exactly what the following method does */

string Package::postalCodeAssignment(const Coords &coordinates) {
    string postalCode;
    const string* postalCodesArray = getPostalCodes();
    const Coords* coordinatesArray = getCoordinates();

    double minDistance = 100000;
    int minIndex = -1;

    for (int i = 0; i < 9; i++) {
        const Coords& centerCoords = coordinatesArray[i];

        double distance = sqrt(
            pow(stod(coordinates.latitude) - stod(centerCoords.latitude), 2) +
            pow(stod(coordinates.longitude) - stod(centerCoords.longitude), 2)
        );

        if (distance < minDistance) {
            minDistance = distance;
            minIndex = i;
        }
    }

    if (minIndex != -1) {
        postalCode = postalCodesArray[minIndex];
    }

    return postalCode;
}

string Package::generatePackageNumber(){
    
    string packageNumber = to_string(getPackageNumber());
    
    // This number must be 4 digits long: 
    while(packageNumber.length() < 4) {
        packageNumber = "0" + packageNumber;
    }
    
    // Update the Package counter:
    increasePackageNumber();
    
    return packageNumber;
}

string Package::generateLabelId(const Coords &coordinates) {
    
    string counter = generatePackageNumber();
    string threeRandNumbersOneLetter = randNumbersAndLetter();
    string date = generateDate();
    string postalCode = postalCodeAssignment(coordinates);
    string labelId = counter + '-' + threeRandNumbersOneLetter + '-' + date + '-' + postalCode;

    return labelId;
}



string Package::generateClientId(){
    uniform_int_distribution<int> distribution(10000000, 99999999);
    int idNum = distribution(gen);
    
    // Spanish IDs have a letter assigned to them, following this method:
    char letter[23] = {'T','R','W','A','G','M','Y','F','P','D','X','B','N','J','Z','S','Q','V','H','L','C','K','E'};
    int mod = idNum % 23;
    char idLetter = letter[mod];
    
    string clientId = to_string(idNum) + idLetter;
    
    return clientId;
}


Package::Package(){
    
    //All packages start at the Central Station, so its status must be fixed:
    status = Status::SPCS;
    label.clientId = Package::generateClientId();
    label.coordinates = Package::generateCoordinates();
    label.packageId = Package::generateLabelId(label.coordinates);
    
}

// A few required setter and getter methods:

Status Package::getStatus(){
    return status;
}

void Package::setStatus(Status newStatus){
    status = newStatus;
}

PackageLabel Package::getLabel(){
    return label;
}

void Package::setPackageId(string newPackageId) {
    label.packageId = newPackageId;
}

void Package::setClientId(string id){
    label.clientId = id;
}
