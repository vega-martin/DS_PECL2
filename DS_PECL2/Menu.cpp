#include "Menu.hpp"
#include "Utilities.hpp"
//#include "Package.hpp"
#include "DLList.hpp"
#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <cstdlib>
using namespace std;

DoublyLinkedList allPackages;

void startingMenu(){
    int choice;
    cout << setw(85) << "-------------------------------------   PACKAGE DISTRIBUTION SERVICE SIMULATOR   -------------------------------------" << endl;
    cout << endl;
    do {
        cout << "(Just in case we want to add any extra improvement)" << endl;
        cout << endl;
        cout << "STARTING MENU || Enter a number to choose an action:" << endl;
        cout << endl;
        cout << " 1. Start the simulation and go to main the menu (You won't be able to come back to this menu!)" << endl;
        cout << " 0. Exit" << endl;
        cout << endl;
        cout << "Enter a number: " << endl;
        
        // Stores input as string
        string input;
        getline(cin, input);
        
        if (!input.empty()) {
            try {
                choice = stoi(input); // String to integer
                switch (choice) {
                    
                    // 0. Exit
                    case 0:
                        cout << endl;
                        cout << "Goodbye!" << endl;
                        exit(0);
                        break;
                    
                    // 1. Start simulation and go to main menu
                    case 1:
                        system("cls");
                        allPackages = generatePackages();
                        cout << "Packages are being created..." << endl;
                        sleep(2);
                        cout << "Packages have been created successfully." << endl;
                        cout << "Redirecting to the main menu..." << endl;
                        sleep(2);
                        system("cls");
                        mainMenu();
                        break;
                    
                    // Not valid number
                    default:
                        cout << endl;
                        cout << "Invalid input. Please enter a valid number." << endl;
                        sleep(1);
                        system("cls");
                        break;
                }
            
            // Catching exceptions
            } catch (const invalid_argument& e) {
                cout << endl;
                cout << "Invalid input. Please enter a valid number." << endl;
                sleep(1);
                system("cls");
                
            } catch (const out_of_range& e) {
                cout << endl;
                cout << "Invalid input. Please enter a valid number." << endl;
                sleep(1);
                system("cls");
            }
        
        
        // If the input buffer is empty
        } else {
            cout << endl;
            cout << "Invalid input. Please enter a valid number." << endl;
            sleep(1);
            system("cls");
        }
        
    } while (true);
}

void mainMenu(){
    int choice;
    cout << setw(85) << "-------------------------------------   PACKAGE DISTRIBUTION SERVICE SIMULATOR   -------------------------------------" << endl;
    cout << endl;
    do {
        cout << "MAIN MENU || Enter a number to choose an action:" << endl;
        cout << endl;
        cout << " 1. Show packages ready to be sent to a given Package Centre." << endl;
        cout << " 2. Show statistics of all Package Centres." << endl;
        cout << " 3. Search package." << endl;
        cout << " 4. Delete package." << endl;
        cout << " 5. Transport package form Salamanca's Package Central Station to a given Package Centre." << endl;
        cout << " 6. Transport package from its Package Centre to a different Package Centre." << endl;
        cout << " 7. Carry on with the packages' delivery." << endl;
        cout << " 0. Exit\n" << endl;
        cout << "===  BEWARE  ========================================================================\n" << endl;
        cout << "If you press the ENTER key without entering any option \npackages WILL be processed!!\n" << endl;
        cout << "=====================================================================================\n" << endl;
        cout << "Enter a number: " << endl;
        
        // Stores input as string
        string input;
        getline(cin, input);
        
        // Checks if the input is empty
        if (!input.empty()) {
            // Tries converting the input to int
            try {
                choice = stoi(input);
                
                // Checking numeric input
                switch (choice) {
                    
                    // 0. Exit
                    case 0:
                        cout << endl;
                        cout << "Goodbye!" << endl;
                        exit(0);
                        break;
                    
                    // 1. Show packages ready to be sent to given Packet Centre
                    case 1:
                        cout << endl;
                        cout << "Nothing is going on here right now :(  -> packages ready to be delivered to PCs" << endl;
                        break;
                    
                    // 2. Show statistics of all Paket Centres
                    case 2:
                        cout << endl;
                        cout << "Nothing is going on here right now :(  -> PCs statistics" << endl;
                        break;
                        
                    // 3. Search package
                    case 3:
                        cout << endl;
                        cout << "Introduce the label of the package you are looking for:" << endl;
                        // string label;
                        // getline(cin >> ws, label);
                        // cout << endl;
                        break;
                    
                    // 4. Delete package
                    case 4:
                        cout << endl;
                        cout << "Introduce the label of the package you want to delete:" << endl;
                        // string label;
                        // getline(cin >> ws, label);
                        // cout << endl;
                        break;
                    
                    // 5. Transport package form Salamanca's Packet Central Station to given Packet Centre
                    case 5:
                        cout << endl;
                        cout << "Nothing is going on here right now :(  -> transport from SPCS to PC" << endl;
                        break;
                    
                    // 6. Transport package from its Packet Centre to given Packet Centre
                    case 6:
                        cout << endl;
                        cout << "Nothing is going on here right now :(  -> transport from PC to PC" << endl;
                        break;
                    
                    // 7. Carry on with the packet's delivery
                    case 7:
                        cout << endl;
                        cout << "Nothing is going on here right now :(  -> 1 Step" << endl;
                        break;
                    
                    // Not valid number
                    default:
                        cout << endl;
                        cout << "Invalid input. Please enter a valid number." << endl;
                        sleep(2);
                        system("cls");
                        break;
                }
            
            // Catching exceptions
            } catch (const invalid_argument& e) {
                cout << endl;
                cout << "Invalid input. Please enter a valid number." << endl;
                sleep(1);
                system("cls");
                
            } catch (const out_of_range& e) {
                cout << endl;
                cout << "Invalid input. Please enter a valid number." << endl;
                sleep(1);
                system("cls");
            }
        
        // If the input buffer is empty
        } else {
            
            /************************   CUIDADO   ************************/
            /*
             * AQUI SE SUPONE QUE TENEMOS QUE HACER EL CÓDIGO PARA EL 
             * PASO. QUIERO DECIR, Q LOS PAQUETES SE MUEVAN A DONDE SE
             * TENGAN Q MOVER
             * TAMBIEN HAY QUE AÑADIR UNA VARIABLE GLOBAL QUE CUENTE 
             * CUANTAS VECES SE HA PRESIONADO ENTRE (CUANTOS PASOS HA
             * DADO EL PROGRAMA)
             */
            /************************   CUIDADO   ************************/
            
            
            cout << endl;
            cout << "Packages are being processed." << endl;
            sleep(2);
            system("cls");
            
        }
        
    } while (true);
}
