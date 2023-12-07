#include "Menu.hpp"
#include "Logistics.hpp"
#include "Utilities.hpp"
#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <cstdlib>
using namespace std;

void startingMenu(Logistics logistics){
    int choice;
    cout << setw(85) << "-------------------------------------   PACKAGE DISTRIBUTION SERVICE SIMULATOR   -------------------------------------" << endl;
    cout << endl;
    do {
        cout << "(Just in case we want to add any extra improvement)" << endl << endl;
        cout << "STARTING MENU || Enter a number to choose an action:" << endl << endl;
        cout << " 1. Start the simulation and go to main the menu (You won't be able to come back to this menu!)" << endl;
        cout << " 0. Exit" << endl << endl;
        cout << "Enter a number: " << endl;
        
        // Stores input as string
        string input;
        getline(cin, input);
        
        if (!input.empty()) {
            try {
                choice = stoi(input); // String to integer
                switch (choice) {

                    case 0: // Exit
                        cout << endl;
                        cout << "Goodbye!" << endl;
                        exit(0);
                        break;
                    
                    case 1: // Start the simulation and go to main menu
                        system("cls");
                        logistics.generatePackages(); 
                        cout << "Packages are being created..." << endl;
                        sleep(2);
                        cout << "Packages have been created successfully." << endl;
                        cout << "Redirecting to the main menu..." << endl;
                        sleep(2);
                        system("cls");
                        mainMenu(logistics);
                        break;
                    
                    default: // Not a valid number
                        cout << endl << "Invalid input. Please enter a valid number." << endl;
                        sleep(1);
                        system("cls");
                        break;
                }
            
            // Catching exceptions
            } catch (const invalid_argument& e) {
                cout << endl << "Invalid input. Please enter a valid number." << endl;
                sleep(1);
                system("cls");
                
            } catch (const out_of_range& e) {
                cout << endl << "Invalid input. Please enter a valid number." << endl;
                sleep(1);
                system("cls");
            }
                
        } else { // If the input buffer is empty
            cout << endl << "Invalid input. Please enter a valid number." << endl;
            sleep(1);
            system("cls");
        }        
    } while (true);
}

void mainMenu(Logistics logistics){
    int choice;
    cout << setw(85) << "-------------------------------------   PACKAGE DISTRIBUTION SERVICE SIMULATOR   -------------------------------------" << endl;
    cout << endl;
    do {
        cout << "MAIN MENU || Steps taken: " << getStepsTaken() << endl << endl;
        cout << "Enter a number to choose an action:" << endl << endl;
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

        string input;
        getline(cin, input);
        if (!input.empty()) {
            try {
                choice = stoi(input);
                switch (choice) {
                
                    case 0: // Exit
                        cout << endl << "Goodbye!" << endl;
                        exit(0);
                        break;

                    case 1: // Show packages ready to be sent to a given Packet Centre
                        cout << endl;
                        cout << "Nothing is going on here right now :(  -> packages ready to be delivered to PCs" << endl;
                        break;
                               
                    case 2: // Show statistics of all Package Centres
                        cout << endl;
                        cout << "Nothing is going on here right now :(  -> PCs statistics" << endl;
                        break;        
                    
                    case 3: // Search for a package
                        cout << endl << "Introduce the label of the package you are looking for:" << endl;
                        // string label;
                        // getline(cin >> ws, label);
                        // cout << endl;
                        break;
                    
                    case 4: // Delete a package
                        cout << endl << "Introduce the label of the package you want to delete:" << endl;
                        // string label;
                        // getline(cin >> ws, label);
                        // cout << endl;
                        break;

                    case 5: // Transport package form Salamanca's PCS to a given Package Centre
                        cout << endl << "Nothing is going on here right now :(  -> transport from SPCS to PC" << endl;
                        break;
                    
                    case 6: // Transport package from its Package Centre to a different Package Centre
                        cout << endl << "Nothing is going on here right now :(  -> transport from PC to PC" << endl;
                        break;
                    
                    case 7: // Carry on with the packages' delivery
                        cout << endl << "Nothing is going on here right now :(  -> 1 Step" << endl;
                        break;    
                    
                    default: // Not valid number
                        cout << endl << "Invalid input. Please enter a valid number." << endl;
                        sleep(2);
                        system("cls");
                        break;
                }
            
            // Catching exceptions
            } catch (const invalid_argument& e) {
                cout << endl << "Invalid input. Please enter a valid number." << endl;
                sleep(1);
                system("cls");
                
            } catch (const out_of_range& e) {
                cout << endl << "Invalid input. Please enter a valid number." << endl;
                sleep(1);
                system("cls");
            }
            
        } else { // If the input buffer is empty
            
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

            cout << endl << "Packages are being delivered..." << endl;
            sleep(2);
            system("cls");
            
        }
        
    } while (true);
}
