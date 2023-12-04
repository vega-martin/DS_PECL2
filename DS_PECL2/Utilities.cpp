#include "Utilities.hpp"
#include "AVLTree.hpp"
#include "Package.hpp"
#include "DLList.hpp"
#include <string>
//#include <iostream>
//#include <iomanip>
using namespace std;

string postalCodes[9] = {"37715","37427","37449","37893","37797","37796","37129","37340","37001"};
string acronyms[9] = {"ADT","PER","ROD","VDT","CDV","MOZ","CDB","ALD","SAL"};
Coords coordinates[9] = {{"41.063717","-5.821883"},
                         {"41.061974","-5.549179"},
                         {"40.904188","-5.817388"},
                         {"40.892504","-5.498010"},
                         {"41.051090","-5.693395"},
                         {"40.859055","-5.652303"},
                         {"40.978764","-5.761869"},
                         {"41.006495","-5.500316"},
                         {"40.965059","-5.664039"}};


template <typename T>
AVLTree generatePackageCenters(){
    AVLTree avltree;
    for (int i = 0; i < 9; i++){
        PackageCenter<T> packageCenter;
        packageCenter.key = i;
        packageCenter.postalCode = postalCodes[i];
        packageCenter.acronym = acronyms[i];
        packageCenter.coordinates = coordinates[i];
        avltree.insert(packageCenter.key);
    }
    return avltree;
};



DoublyLinkedList generatePackages(){
    DoublyLinkedList packagesList;
    
    Package vega;
    Package adri;
    vega.setClientId("05955285X");
    adri.setClientId("03247820J");
    packagesList.insertBack(vega);
    packagesList.insertBack(adri);
    
    /*
    cout << setw(15) << "PackageID:" << setw(16) << vega.getLabel().packageId 
        << setw(15) << "Latitude:" << setw(15) << vega.getLabel().coordinates.latitude
        << setw(15) << "Longitude:" << setw(15) << vega.getLabel().coordinates.longitude
        << setw(15) << "ClientID:" << setw(15) << vega.getLabel().clientId
        << setw(15) << "Status:" << setw(15) << vega.getStatus()
        << endl;
    cout << setw(15) << "PackageID:" << setw(16) << adri.getLabel().packageId 
        << setw(15) << "Latitude:" << setw(15) << adri.getLabel().coordinates.latitude
        << setw(15) << "Longitude:" << setw(15) << adri.getLabel().coordinates.longitude
        << setw(15) << "ClientID:" << setw(15) << adri.getLabel().clientId
        << setw(15) << "Status:" << setw(15) << adri.getStatus()
        << endl;
    */
    
    for(int i = 0; i < 248; i++){
		Package p;
        /*cout << setw(15) << "PackageID:" << setw(16) << p.getLabel().packageId 
        << setw(15) << "Latitude:" << setw(15) << p.getLabel().coordinates.latitude
        << setw(15) << "Longitude:" << setw(15) << p.getLabel().coordinates.longitude
        << setw(15) << "ClientID:" << setw(15) << p.getLabel().clientId
        << setw(15) << "Status:" << setw(15) << p.getStatus()
        << endl;*/
		packagesList.insertBack(p);
	}
    
    return packagesList;
};

template <typename N>
void locateInPC(PackageCenter<N> PC){
    
}
