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
        packageCenter.postalCode = postalCodesArray[i];
        packageCenter.acronym = acronymsArray[i];
        packageCenter.coordinates = coordinatesArray[i];
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
            emptyAllHubs();
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
                Package pa = searchedPC.hub.pop();
                pa.setStatus(Delivered);
                searchedPC.auxQueue.enqueue(pa);
            }
        }
        
        // We can't forget to change the package's status before losing its reference:
        p.setStatus(Hub);
        // Now the new package can be pushed into the stack:
        searchedPC.hub.push(p);
    }
    
    // At the end of the method, the global variable stepsTaken must be updated:
    stepsTaken++;
}

int countPackagesInPC(const string& postalCode) {
    PackageCenter searchedPC = pcTree.getPC(postalCode);
    return searchedPC.hub.length();
}

void printNumPackagesPC() {
    cout << endl << " The number of packages in each Package Centre at the moment is:" << endl << endl;
    for (int i = 0; i < PACKAGE_CENTRES; i++){
        int numPackages = countPackagesInPC(postalCodesArray[i]);
        cout << "- Package Centre " << acronymsArray[i] << " with postal code " << postalCodesArray[i] << ": " <<
        numPackages << " packages." << endl;
    }
}

void printNumPackagesQueue() {
    cout << endl << " The number of packages delivered from every Package Centre at this very moment is:" << endl << endl;
    for (int i = 0; i < PACKAGE_CENTRES; i++){
        PackageCenter searchedPC = pcTree.getPC(postalCodesArray[i]);
        int numPackages = searchedPC.auxQueue.length();
        cout << "- Package Centre " << acronymsArray[i] << " with postal code " << postalCodesArray[i] << " delivered " <<
        numPackages << " packages." << endl;
    }
}

void printLongestHub(){
    int maxIndex = 0; // Initialised to avoid any issues
    int maxLength = -1; // Impossible value (any negative integer would work)
    for (int i = 0; i < PACKAGE_CENTRES; i++){
        int numPackages = countPackagesInPC(postalCodesArray[i]);
        if (numPackages > maxLength){
            maxLength = numPackages;
            maxIndex = i;
        }
    }
    cout << "The hub with the most packages is located in " << acronymsArray[maxIndex] <<
    ", holding " << maxLength << " packages." << endl;
    cout << "Its postal code is " << postalCodesArray[maxIndex] << endl;
}

void printShortestHub(){
    int minIndex = 0; // Initialised to avoid any issues
    int minLength = HUB_CAPACITY + 1; // Impossible value (any bigger integer would work)
    for (int i = 0; i < PACKAGE_CENTRES; i++){
        int numPackages = countPackagesInPC(postalCodesArray[i]);
        if (numPackages < minLength){
            minLength = numPackages;
            minIndex = i;
        }
    }
    cout << "The hub with the fewest packages is located in " << acronymsArray[minIndex] <<
    ", holding " << minLength << " packages." << endl;
    cout << "Its postal code is " << postalCodesArray[minIndex] << endl;
}

void printFrequencies() {
    int sample = 0;
    // Calculate sample
    for (int i = 0; i < PACKAGE_CENTRES; i++){
        PackageCenter searchedPC = pcTree.getPC(postalCodesArray[i]);
        int numPackages = searchedPC.hub.length();
        int numDeliveredPackages = searchedPC.auxQueue.length();
        sample = sample + numPackages + numDeliveredPackages;
    }
    
    for (int i = 0; i < PACKAGE_CENTRES; i++){
        PackageCenter searchedPC = pcTree.getPC(postalCodesArray[i]);
        int numPackages = searchedPC.hub.length();
        int numDeliveredPackages = searchedPC.auxQueue.length();
        int absFreq = numPackages + numDeliveredPackages;
        cout     << "Package centre:"    << setw(5) << acronymsArray[i] <<
        setw(16) << "Postal code:"       << setw(9) << postalCodesArray[i] <<
        setw(23) << "Absolute frequency:"<< setw(7) << absFreq <<
        setw(23) << "Relative frequency:"<< setw(9) << absFreq << "/" << sample << endl;
    }
}

void getNextPackagesToBeDelivered(const string& postalCode) {

    // We have to make sure the introduced postal code matches any existing PCentre:
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
        string substrCode = pl.packageId.substr(pl.packageId.length()-5,5);
        
        if (postalCode == substrCode) {
            cout     << "Package id:"        << setw(20) << pl.packageId <<
            setw(18) << "Client ID:"         << setw(12) << pl.clientId <<
            setw(20) << "Package latitude:"  << setw(12) << pl.coordinates.latitude <<
            setw(20) << "Package longitude:" << setw(12) << pl.coordinates.longitude << 
            setw(14) << "Postal code:"       << setw(9) << substrCode << endl;
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
        
        // Now we search inside all hubs' vans (waiting to be delivered):
        for (int i = 0; i < PACKAGE_CENTRES; i++){  
            PackageCenter searchedPC = pcTree.getPC(postalCodesArray[i]);  
            if(searchedPC.hub.searchPackageByNum(strNum) == 1){  
                return i;
            }
        }
        
        // Our only possible option now is that the package has already been delivered:
        for (int i = 0; i < PACKAGE_CENTRES; i++){  
            PackageCenter searchedPC = pcTree.getPC(postalCodesArray[i]);  
            if(searchedPC.auxQueue.searchPackageByNum(strNum) == 1){  
                return 10;
            }
        }
        
        // If none of the previous options have worked, then we return a different error value:
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
        cout << "Sorry, the package could not be found." << endl;
    }
    else if (result == 9) {
        cout << "The package is currently located at the Central Station" << endl;
    }
    else if (result == 10) {
        cout << "The package has already been successfully delivered!" << endl;
    }
    else {
        cout << "The package is currently located at the " << acronymsArray[result] << " Package Centre." << endl;
    }
}

void deletePackage(string label) {
    int result = searchPackage(label);
    int number;
    try {
        number = stoi(label);
        
        // Invalid inputs: not an integer, or an int out of (1-PACKAGE_CARGO) range    
        if((number < 1) || (number > PACKAGE_CARGO)) {
            cout << endl << "Invalid input. Please enter a valid number." << endl;
            sleep(1);
            system("cls");
            return;
        }
        
        // Apply format
        string strNum = to_string(number);
        while(strNum.length() < 4) {
            strNum = "0" + strNum;
        }
    
        if(result == -1) {
            return;
        }
        else if (result == -2) {
            cout << "Sorry, the package can't be deleted, it has already been delivered." << endl;
        }
        else if (result == 9) {
            Package p = packageList.removePackage(strNum);
            cout << "The package has been deleted from the Central Station" << endl;
        }
        else {
            PackageCenter& searchedPC = pcTree.getPC(postalCodesArray[result]);
            Package p = searchedPC.hub.removePackage(strNum);
            cout << "The package has been deleted from the " << acronymsArray[result] << " Package Centre." << endl;
        }
        
    } catch (const invalid_argument& e) {
        cout << endl << "Invalid input. Please enter a valid number." << endl;
        sleep(1);
        system("cls");
        return;
        
    } catch (const out_of_range& e) {
        cout << endl << "Invalid input. Please enter a valid number." << endl;
        sleep(1);
        system("cls");
        return;
    }
}

void fromSPCStoPC(string label, string postalCode){
    
    int number;
    try {
        number = stoi(label);
        string strNum = to_string(number);
        
        // Invalid inputs: not an integer, or an int out of (1-PACKAGE_CARGO) range    
        if((number < 1) || (number > PACKAGE_CARGO)) {
            cout << endl << "Invalid input. Please enter a valid number." << endl;
            sleep(1);
            system("cls");
            return;
        }
        
        // Apply format
        while(strNum.length() < 4) {
            strNum = "0" + strNum;
        }
        
        // We have to make sure the introduced postal code matches any existing PCentre:
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
        
        // Search if the package is in the SPCS
        if (packageList.searchPackageByNum(strNum) == 0){
            cout << "Sorry, the package was not found at the SPCS. Maybe it is already in a package centre?" << endl;
            return;
        }
        
        // Move from SPCS to PC
        Package p = packageList.removePackage(strNum);
        PackageCenter& searchedPC = pcTree.getPC(postalCode);
        searchedPC.hub.push(p);
        
        cout << "The package has been successfully transported." << endl;
    
    } catch (const invalid_argument& e) {
        cout << endl << "Invalid input. Please enter a valid number." << endl;
        sleep(1);
        system("cls");
        return;
        
    } catch (const out_of_range& e) {
        cout << endl << "Invalid input. Please enter a valid number." << endl;
        sleep(1);
        system("cls");
        return;
    }
}

void fromPCtoPC(string label, string postalCode) {
    int number;
    try {
        number = stoi(label);
        string strNum = to_string(number);
        
        // Invalid inputs: not an integer, or an int out of (1-PACKAGE_CARGO) range    
        if((number < 1) || (number > PACKAGE_CARGO)) {
            cout << endl << "Invalid input. Please enter a valid number." << endl;
            sleep(1);
            system("cls");
            return;
        }
        
        // Apply format
        while(strNum.length() < 4) {
            strNum = "0" + strNum;
        }
    
        // We have to make sure the introduced postal code matches any existing PCentre:
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
        
        bool found = false;
        // Search in every PC just in case it has already been moved
        for (int i = 0; i < PACKAGE_CENTRES; i++){  
            PackageCenter& searchedPC = pcTree.getPC(postalCodesArray[i]);  
            if(searchedPC.hub.searchPackageByNum(strNum) == 1){
                
                // If the user attempts to move a package to the exact same Centre it currently is:
        
                if(postalCodesArray[i] == postalCode) {
                    cout << "The package is already located where you want to move it!!" << endl;
                    return;
                }
                // Otherwise, the package is moved from where it's currently located to another PC
                
                PackageCenter& destinationPC = pcTree.getPC(postalCode);
                Package p = searchedPC.hub.removePackage(strNum);
                destinationPC.hub.push(p);
                found = true;
                cout << "The package has been successfully transported." << endl;
                return;
            }
        }
        
        if(!found){
            cout << "Sorry, the package was not found at its corresponding package centre. Maybe it is at the SPCS or has already been delivered." << endl;
        }
        
    } catch (const invalid_argument& e) {
        cout << endl << "Invalid input. Please enter a valid number." << endl;
        sleep(1);
        system("cls");
        return;
        
    } catch (const out_of_range& e) {
        cout << endl << "Invalid input. Please enter a valid number." << endl;
        sleep(1);
        system("cls");
        return;
    }
}

void emptyAllHubs(){
    for (int i = 0; i < PACKAGE_CENTRES; i++){  
            PackageCenter& searchedPC = pcTree.getPC(postalCodesArray[i]);
            while (!searchedPC.hub.isEmpty()){
                Package p = searchedPC.hub.pop();
                p.setStatus(Delivered);
                searchedPC.auxQueue.enqueue(p);
            }
    }
}