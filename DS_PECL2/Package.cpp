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

string Package::generateLabelId(const Coords &coordinates) {
    
    // OJO VEGA!! A ESTE LABEL LE FALTARÍA AL PRINCIPIO CUATRO NUMEROS MÁS!! SON LOS QUE IDENTIFICAN
    // EL NUMERO DEL PAQUETE!! (LEETE DEL ENUNCIADO LO QUE NO ENTIENDAS). NO SÉ SI DEJAR ESPACIO O
    // NO HACER NADA, Y A LA HORA DE GENERAR EL PAQUETE, MODIFICAR ESTE VALOR ASIGNANDOLE UNOS NUMEROS
    // DELANTE. Igual suena todo esto un poco confuso, cualquier duda dime, cuando veas esto bórralo tambien

    string threeRandNumbersOneLetter = randNumbersAndLetter();
    string date = generateDate();
    string postalCode = postalCodeAssignment(coordinates);
    string labelId = threeRandNumbersOneLetter + '-' + date + '-' + postalCode;

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
