#ifndef LOGISTICS_HPP
#define LOGISTICS_HPP
#include "AVLTree.hpp"
#include "DLList.hpp"
#include "DLList.hpp"
//#include "Utilities.hpp"

class Logistics
{
private:
    AVLTree pcTree;
    DLList packageList;

public:
    
    // Constructor:
    Logistics();
    
    // Getters:
    AVLTree getPcTree();
    DLList getPackageList();
    
    // Other methods:    
    void generatePackageCentres();
    void generatePackages();
    
    void packageDelivery(Logistics logistics);


};

#endif // LOGISTICS_HPP
