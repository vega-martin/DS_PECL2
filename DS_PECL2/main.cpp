#include "Menu.hpp"
#include "Logistics.hpp"
using namespace std;

int main() {
    
    // Global instance of the Logistics class, will be used across the whole program:
    Logistics logistics;

    // Main menu is executed here:
    startingMenu(logistics);

    return 0;
}
