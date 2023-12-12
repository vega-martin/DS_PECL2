#include "Menu.hpp"
#include "Logistics.hpp"

int main() {
    
    // If you wish to redirect the consol output to a .txt file, uncomment the following line:
    freopen("debug.txt", "w", stdout);
    
    // Packages are generated and inserted into the doubly linked list:    
    generatePackages();
    
    // Package Centers are established and inserted into the self balancing tree:
    generatePackageCentres();
    
    // Main menu is executed here:
    mainMenu();

    return 0;
}

