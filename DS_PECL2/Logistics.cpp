#include "Logistics.hpp"
#include "Utilities.hpp"
#include "Package.hpp"
#include "Stack.hpp"
#include <iostream>
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
    //PACKAGES_PER_DELIVERY
    for (int i = 0; i < 5 ; i++){
        
        // We must first check if there are pending packages:
        
        if (packageList.isEmpty()){
            cout << "Oh no! The package list emptied out! The leftover packages will be delivered now..." << endl;
            return; // ESTO DEBERÍA HACER QUE SE SALIERA DEL METODO
        }
        
        // The usual scenario
        
        /* To begin with the delivery, we must know where the package must
         * be sent. Therefore, we need to obtain its postal code: */
        
        Package p = packageList.removeFront();
        string pLabel = p.getLabel().packageId;
        string postalCode = pLabel.substr(pLabel.length() - 5,5); // Last 5 characters (postal code)
        
        // Now we must find what Package Centre is this package assigned to:
        PackageCenter searchedPC = pcTree.getPC(postalCode);
        
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
