#include "Logistics.hpp"
#include "Utilities.hpp"
#include "Package.hpp"
#include "Stack.hpp"
#include "AVLTree.hpp"
#include "DLList.hpp"
#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <cstdlib>
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
    
    for(int i = 0; i < PACKAGES_PER_DELIVERY; i++){
        
        // We must first check if there are pending packages:
        if (packageList.isEmpty()){
            cout << "Oh no! The package list emptied out! The leftover packages will be delivered now..." << endl;
            //emptyAllHubs(); NOT DONE YET
            return;
        }
        
        // To begin with the delivery, we must know where the package must
        // be sent. Therefore, we need to obtain its postal code: 
        Package p = packageList.removeFront();
        string pLabel = p.getLabel().packageId;
        string postalCode = pLabel.substr(pLabel.length() - 5,5); // Last 5 characters (postal code)
        
        // Now we must find what Package Centre is this package assigned to:
        PackageCenter& searchedPC = pcTree.getPC(postalCode);
        
        // The stack can't be full , so we must check that:
        if (searchedPC.hub.isFull()){
            cout << "The Package Centre in " << searchedPC.acronym << " has been filled up! " 
            << "Delivering all packages..." << endl;
            
            // Pop all stack elements and enqueue them into the auxiliary queue:
            while (!searchedPC.hub.isEmpty()){
                searchedPC.auxQueue.enqueue(searchedPC.hub.pop());
            }
        }
        
        // Now the new package can be pushed into the stack:
        searchedPC.hub.push(p);
    }
    
    // At the end of the method, the global variable stepsTaken must be updated:
    increaseStepsTaken();
}

int countPackagesInPC(const string& postalCode) {
    PackageCenter searchedPC = pcTree.getPC(postalCode);
    return searchedPC.hub.length();
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
    
    for (int i = 0; i < PACKAGE_CENTRES; i++){ 
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
            cout     << "Package id:"        << setw(20) << pl.packageId <<
            setw(18) << "Client ID:"         << setw(12) << pl.clientId <<
            setw(20) << "Package latitude:"  << setw(12) << pl.coordinates.latitude <<
            setw(20) << "Package longitude:" << setw(12) << pl.coordinates.longitude << 
            setw(14) << "Postal code:"       << setw(9) << x << endl;
        }
        current = current->next;
    }
}

int searchPackage(string label) {
    /* If result = -1 -> invalid input (controlled in searchPackage method)
     * If result = -2 -> package not found
     * If result = [0,8] -> in which PC the pakage is located
     * If result = 9 -> package in Central Station
     */
    
    int number;
    try {
        number = stoi(label);   

        
        // Invalid inputs: not an integer, or an int out of (1-PACKAGE_CARGO) range    
        if((number < 1) || (number > PACKAGE_CARGO)) {
            cout << endl << "Invalid input. Please enter a valid number." << endl;
            sleep(1);
            system("cls");
            return -1;
        }

        // Convert the input to a 4 digit long string (to match the package label's format):
        string strNum = to_string(number);
        while(strNum.length() < 4) {
            strNum = "0" + strNum;
        }
        
        // We begin searching in the Central Station (doubly-linked list):
        if (packageList.searchPackageByNum(strNum) == 1){
            return 9;   
        } 
        
        const string* postalCodesArray = getPostalCodes();
            
        for (int i = 0; i < PACKAGE_CENTRES; i++){  
            PackageCenter searchedPC = pcTree.getPC(postalCodesArray[i]);  
            if(searchedPC.hub.searchPackageByNum(strNum) == 1){  
                return i;
            }
        }
        return -2; 
        
    // Catching exceptions
    } catch (const invalid_argument& e) {
        cout << endl << "Invalid input. Please enter a valid number." << endl;
        sleep(1);
        system("cls");
        return -1;
        
    } catch (const out_of_range& e) {
        cout << endl << "Invalid input. Please enter a valid number." << endl;
        sleep(1);
        system("cls");
        return -1;
    }
}

void searchAnswer(string label) {
    int result = searchPackage(label);
     
    if(result == -1) {
        return;
    }
    else if (result == -2) {
        cout << "Sorry, the package have not been found." << endl;
        cout << endl << "Press ENTER key to continue..." << endl;
    }
    else if (result == 9) {
        cout << "The package is currently located at the Central Station" << endl;
        cout << endl << "Press ENTER key to continue..." << endl;
    }
    else {
        const string* acronymsArray = getAcronyms();
        cout << "The package is currently located at the " << acronymsArray[result] << " package center." << endl;
        cout << endl << "Press ENTER key to continue..." << endl;
    }
}

void deletePackage(string label) {
    int result = searchPackage(label);
    // Apply format
    while(label.length() < 4) {
        label = "0" + label;
    }
    
    if(result == -1) {
        return;
    }
    else if (result == -2) {
        cout << "Sorry, the package can't be deleted, it has already been delivered." << endl;
        cout << endl << "Press ENTER key to continue..." << endl;
    }
    else if (result == 9) {
        packageList.deleteNode(label);
        cout << "The package have been deleted from the Central Station" << endl;
        cout << endl << "Press ENTER key to continue..." << endl;
    }
    else {
        const string* postalCodesArray = getPostalCodes();
        const string* acronymsArray = getAcronyms();
        PackageCenter& searchedPC = pcTree.getPC(postalCodesArray[result]);
        searchedPC.hub.deleteNode(label);
        cout << "The package have been deleted from the " << acronymsArray[result] << " package center." << endl;
        cout << endl << "Press ENTER key to continue..." << endl;
    }
}

void fromSPCStoPC(string label, string postalCode){
    // Apply format
    while(label.length() < 4) {
        label = "0" + label;
    }
    
    // We have to make sure the introduced postal code matches any existing PCentre:
    const string* postalCodesArray = getPostalCodes();
    bool isCorrect = false; //Checking variable
    for (int i = 0; i < PACKAGE_CENTRES; i++){ 
        if (postalCode == postalCodesArray[i]){ // Match found
            isCorrect = true;
            break;
        } 
    }
    // If there was no match, the method must end here:
    if (isCorrect == false){
        cout << "Wrong postal code!!" << endl;
        cout << endl << "Press ENTER key to continue..." << endl;
        return;
    }
    
    // Search if the package is in the SPCS
    if (packageList.searchPackageByNum(label) == 0){
        cout << "Sorry, the package was not found at the SPCS. Maybe it is already in a package centre." << endl;
        cout << endl << "Press ENTER key to continue..." << endl;
        return;
    }
    
    // Move from SPCS to PC
    Package p = packageList.removeNode(label);
    PackageCenter& searchedPC = pcTree.getPC(postalCode);
    searchedPC.hub.push(p);
    
    cout << "The package has been successfully transported." << endl;
    cout << endl << "Press ENTER key to continue..." << endl;
}

void fromPCtoPC(string label, string postalCode) {
    // Apply format
    while(label.length() < 4) {
        label = "0" + label;
    }
    
    // We have to make sure the introduced postal code matches any existing PCentre:
    const string* postalCodesArray = getPostalCodes();
    bool isCorrect = false; //Checking variable
    for (int i = 0; i < PACKAGE_CENTRES; i++){ 
        if (postalCode == postalCodesArray[i]){ // Match found
            isCorrect = true;
            break;
        } 
    }
    // If there was no match, the method must end here:
    if (isCorrect == false){
        cout << "Wrong postal code!!" << endl;
        cout << endl << "Press ENTER key to continue..." << endl;
        return;
    }
    
    bool found = false;
    // Search in every PC just in case it has already been moved
    for (int i = 0; i < PACKAGE_CENTRES; i++){  
        PackageCenter& searchedPC = pcTree.getPC(postalCodesArray[i]);  
        if(searchedPC.hub.searchPackageByNum(label) == 1){
            // Move from the PC the package is locate to another PC
            Package p = searchedPC.hub.removeNode(label);
            PackageCenter& toPC = pcTree.getPC(postalCode);
            toPC.hub.push(p);
            found = true;
            cout << "The package has been successfully transported." << endl;
            cout << endl << "Press ENTER key to continue..." << endl;
        }
    }
    
    if(!found){
        cout << "Sorry, the package was not found at its corresponding package centre. Maybe it is at the SPCS or has already been delivered." << endl;
        cout << endl << "Press ENTER key to continue..." << endl;
    }
}