#include "Logistics.hpp"
#include "Utilities.hpp"
#include "DLList.hpp"
#include "Package.hpp"
#include <iostream>

Logistics::Logistics()
{    
}

AVLTree Logistics::getPcTree(){
    return pcTree;
}

DLList Logistics::getPackageList(){
    return packageList;
}

void Logistics::generatePackageCentres(){

    for (int i = 0; i < PACKAGE_CENTRES; i++){
        PackageCenter packageCenter;
        packageCenter.key = i;
        packageCenter.postalCode = postalCodes[i];
        packageCenter.acronym = acronyms[i];
        packageCenter.coordinates = coordinates[i];
        pcTree.insert(packageCenter.key);
    }
};

void Logistics::generatePackages(){
    
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

void Logistics::packageDelivery(Logistics logistics){
    
    for (int i = 0; i < PACKAGES_PER_DELIVERY; i++){
        
        // We must first check if there are pending packages:
   
        if (logistics.packageList.isEmpty()){
            cout << "Oh no! The package list emptied out! The leftover packages will be delivered now..." << endl;
            return; // ESTO DEBERÍA HACER QUE SE SALIERA DEL METODO
        }
        
        else { // The usual scenario
        
        /* To begin with the delivery, we must know where the package must
         * be sent. Therefore, we need to obtain its postal code: */
    
        Package p = logistics.packageList.removeFront();
        string pLabel = p.getLabel().packageId;
        string postalCode = pLabel.substr(pLabel.length() - 5,5); // Last 5 characters (postal code)
        
        // Now we must find what Package Centre is this package assigned to:
        
        // AQUI VA ALGO DE BUSCAR EL PACKAGE_CENTRE EN EL AVL TREE, PERO OJO 
        // IGUAL QUEREMOS BUSCAR POR CODIGO POSTAL, SE NOS COMPLICA LA COSA
        // A VER SI ERES CAPAZ DE TERMINARLO
        
        // At the end of the method, the global variable stepsTaken must be updated:
        increaseStepsTaken();
        }
    }
}

