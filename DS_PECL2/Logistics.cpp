#include "Logistics.hpp"
#include "Utilities.hpp"

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

void Logistics::packageDelivery(){
    
}

