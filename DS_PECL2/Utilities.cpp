#include "Utilities.hpp"
#include "AVLTree.hpp"
#include "Package.hpp"
#include "DLList.hpp"
#include <string>
#include <iostream>
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
/*
template <typename T>
//DoublyLinkedList<T> generatePackages(){
void generatePackages(){
    DoublyLinkedList<T> packages;
    
    Package vega;
    Package adri;
    
    vega.setClientId("05955285X");
    adri.setClientId("03247820J");
    
    packages.insertBack(vega);
    packages.insertBack(adri);
    
    for(int i = 0; i < 7 - 2; i++){
		Package p;
        cout << p.getLabel().packageId << endl;
		packages.insertBack(p);
	}
    
    //return packages;
};*/
