#include "Logistics.hpp"
#include "Utilities.hpp"
#include "Package.hpp"
#include "Stack.hpp"
#include "AVLTree.hpp"
#include "DLList.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

AVLTree pcTree;
DLList packageList;

void generatePackageCentres(){
    for (int i = 0; i < PACKAGE_CENTRES; i++){
        PackageCenter packageCenter;
        packageCenter.postalCode = postalCodes[i];
        packageCenter.acronym = acronyms[i];
        packageCenter.coordinates = coordinates[i];
        pcTree.insert(packageCenter);
    }
};

void generatePackages(){
    
    // The first two packages must be set to our personal IDs:
    Package vega;
    Package adri;
    vega.setClientId("05955285X");
    adri.setClientId("03247820J");
    packageList.insertBack(vega);
    packageList.insertBack(adri);
    
    for(int i = 0; i < PACKAGE_CARGO - 2; i++){
        Package p;
        packageList.insertBack(p);
    }
};

void packageDelivery(){
    
    for (int i = 0; i < PACKAGES_PER_DELIVERY; i++){
        
        // We must first check if there are pending packages:
        if (packageList.isEmpty()){
            cout << "Oh no! The package list emptied out! The leftover packages will be delivered now..." << endl;
            return;
        }
        
        // To begin with the delivery, we must know where the package must
        // be sent. Therefore, we need to obtain its postal code: 
        Package p = packageList.removeFront();
        string pLabel = p.getLabel().packageId;
        string postalCode = pLabel.substr(pLabel.length() - 5,5); // Last 5 characters (postal code)
        
        // Now we must find what Package Centre is this package assigned to:
        PackageCenter& searchedPC = pcTree.getPC(postalCode);
        
        // Insert the package in the PC stack if its not full:
        if (!searchedPC.hub.isFull()) {
            searchedPC.hub.push(p);
        }
        
    }
    // At the end of the method, the global variable stepsTaken must be updated:
    increaseStepsTaken();
}

int countPackagesInPC(const string& postalCode) {
    PackageCenter searchedPC = pcTree.getPC(postalCode);
    if (searchedPC.hub.isEmpty()) {
        return 0;
    } else {
        return searchedPC.hub.length();
    }
}

void printNumPackagesPC() {
    cout << endl << " The number of packages in each Package Centre at the moment is:" << endl << endl;
    for (int i = 0; i < PACKAGE_CENTRES; i++){
        int numPackages = countPackagesInPC(postalCodes[i]);
        cout << "- Package Centre " << acronyms[i] << " with postal code " << postalCodes[i] << ": " <<
        numPackages << " packages." << endl;
    }
}

void getNextPackagesToBeDelivered(const string& postalCode) {

    // We have to make sure the introduced postal code matches any existing PCentre:
    const string* postalCodesArray = getPostalCodes();
    bool isCorrect = false; //Checking variable
    
    int arrayLength = sizeof(postalCodes) / sizeof(postalCodes[0]); //Length must be calculated like this
    
    for (int i = 0; i < arrayLength; i++){ 
        if (postalCode == postalCodesArray[i]){ // Match found
            isCorrect = true;
            break;
        } 
    }
    
    // If there was no match, the method must end here:
    if (isCorrect == false){
        cout << "Wrong postal code!!" << endl;
        return;
    }
    
    // Exception handled, now the method does its thing:
    DoublyNode* current = packageList.getHead();

    while (current != nullptr) {

        Package p = current->element;
        PackageLabel pl = p.getLabel();
        string x = pl.packageId.substr(pl.packageId.length()-5,5);
        
        if (postalCode == x) {
            cout     << "Package id:"        << setw(25) << pl.packageId <<
            setw(20) << "Client ID:"         << setw(15) << pl.clientId <<
            setw(25) << "Package latitude:"  << setw(15) << pl.coordinates.latitude <<
            setw(25) << "Package longitude:" << setw(15) << pl.coordinates.longitude << 
            setw(20) << "Postal code:"       << setw(10) << x << endl;
        }
        current = current->next;
    }
}

void searchPackage(int number){
    
    // Invalid inputs: not an integer, or an int out of (1-PACKAGE_CARGO) range:
    if (!(cin >> number) || (number < 1) || (number > PACKAGE_CARGO)) {
        cout << "Invalid input. Please enter a valid package number" << endl;
        return;
    }
    // Convert the input to a 4 digit long string (to match the package label's format):
    string strNum = to_string(number);
    while(strNum.length() < 4) {
        strNum = "0" + strNum;
    }
    
    // We begin searching in the Central Station (doubly-linked list):    
    if (packageList.searchPackageByNum(strNum) == 1){
        cout << "The package is currently located at the Central Station" << endl;
        return;
    }

    // AQUI TOCA COMPARAR EN LOS HUBS, SI NO SE ENCONTRARA TAMPOCO EN NINGUNO
    // ES QUE EL PAQUETE SE HA BORRADO, PERO ESO DE MOMENTO NO PODRÍA PASAR PORQUE NO PODEMOS BORRAR PAQUETES
    
}