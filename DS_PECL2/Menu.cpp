#include "Menu.hpp"
#include "Logistics.hpp"
#include "Utilities.hpp"
#include <iostream>
#include <iomanip>
#include <unistd.h>
#include <cstdlib>
using namespace std;

void mainMenu(){
    int choice;
    do {
        cout << setw(85) << "-------------------------------------   PACKAGE DISTRIBUTION SERVICE SIMULATOR   -------------------------------------" << endl;
        cout << endl;
        cout << "MAIN MENU || Steps taken: " << stepsTaken << endl << endl;
        cout << "Enter a number to choose an action:" << endl << endl;
        cout << " 1. Show packages ready to be sent to a given Package Centre." << endl;
        cout << " 2. Show statistics of all Package Centres." << endl;
        cout << " 3. Search package." << endl;
        cout << " 4. Delete package." << endl;
        cout << " 5. Transport package form Salamanca's Package Central Station to a given Package Centre." << endl;
        cout << " 6. Transport package from its Package Centre to a different Package Centre." << endl;
        cout << " 7. Deliver all packages inside every Package Centre." << endl;
        cout << " 0. Exit" << endl << endl;
        cout << "===  BEWARE  ========================================================================\n" << endl;
        cout << "If you press the ENTER key without entering any option \npackages WILL be processed!!\n" << endl;
        cout << "=====================================================================================\n" << endl;
        cout << "Enter a number: " << endl;
        
        string input;
        string postalCode;
        string label;
        getline(cin, input);
        if (!input.empty()) {
            try {
                choice = stoi(input);
                switch (choice) {
                
                    case 0: // Exit
                        cout << endl << "Goodbye!" << endl;
                        exit(0);
                        break;

                    case 1: // Show packages ready to be sent to a given Package Centre
                        cout << endl;
                        cout << "Introduce the postal code of the Package Centre you are interested in:" << endl;
                        getline(cin >> ws, postalCode);
                        cout << endl;
                        getNextPackagesToBeDelivered(postalCode);
                        cout << endl << "Press ENTER to continue..." << endl;
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        
                        system("cls"); 
                        break;
                               
                    case 2: // Show statistics of all Package Centres
                        cout << endl << "Redirecting to the statistics menu..." << endl;
                        sleep(1);
                        system("cls");
                        statisticsMenu();
                        break;        
                    
                    case 3: // Search for a package
                        cout << endl << "Introduce the number of the package you are looking for:" << endl;
                        getline(cin >> ws, label);
                        cout << endl;
                        searchAnswer(label);
                        cout << endl << "Press ENTER to continue..." << endl;
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        system("cls");
                        break;
                    
                    case 4: // Delete a package
                        cout << endl << "Introduce the number of the package you want to delete:" << endl;
                        getline(cin >> ws, label);
                        cout << endl;
                        deletePackage(label);
                        cout << endl << "Press ENTER to continue..." << endl;
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        system("cls");
                        break;
                    
                    case 5: // Transport package form Salamanca's PCS to a given Package Centre
                        cout << endl << "Enter the number of the package you want to transport:" << endl;
                        getline(cin >> ws, label);
                        cout << "Enter the postal code of the Package Centre you want to send the package to:" << endl;
                        getline(cin >> ws, postalCode);
                        fromSPCStoPC(label, postalCode);
                        cout << endl << "Press ENTER to continue..." << endl;
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        system("cls");
                        break;
                    
                    case 6: // Transport package from its Package Centre to a different Package Centre
                        cout << endl << "Enter the number of the package you want to transport:" << endl;
                        getline(cin >> ws, label);
                        cout << "Enter the postal code of the Package Centre you want to send the package to:" << endl;
                        getline(cin >> ws, postalCode);
                        fromPCtoPC(label, postalCode);
                        cout << endl << "Press ENTER to continue..." << endl;
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        system("cls");
                        break;
                    
                    case 7: // Deliver all packages inside every Package Centre
                        emptyAllHubs();
                        cout << endl << "All packages inside every Package Centre have been delivered" << endl;
                        sleep(1);
                        system("cls");
                        break;    
                    
                    default: // Not valid number
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
            // Take multiple steps at a time
            for(int i = 0; i < 5; i++){
                packageDelivery();
            }
            cout << endl << "Packages are being delivered..." << endl;
            sleep(1);
            system("cls");
        }
        
    } while (true);
}


void statisticsMenu() {
    int choice;
    do {
        cout << setw(85) << "-------------------------------------------------   STATISTICS MENU   ------------------------------------------------" << endl;
        cout << endl;
        cout << "Enter a number to choose an action:" << endl << endl;
        cout << " 1. Show number of packages in each Package Centre at the moment." << endl;
        cout << " 2. Show total number of packages that had gone to each Package Centre." << endl;
        cout << " 3. Package Centre with most Packages." << endl;
        cout << " 4. Package Centre with least Packages." << endl;
        cout << " 5. Absolute and relative frequecies of each Package Centre." << endl;
        cout << " 6. Go back to the main menu." << endl;
        cout << " 0. Exit the program.\n" << endl;
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

                    case 1: // Show number of packages in each Package Centre at the moment
                        printNumPackagesPC();
                        cout << endl << "Press ENTER to continue..." << endl;
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        system("cls");
                        break;
                               
                    case 2: // Show total number of packages that had gone to each Package Centre
                        printNumPackagesQueue();
                        cout << endl << "Press ENTER to continue..." << endl;
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        system("cls");
                        break;        
                    
                    case 3: // Package Centre with most Packages
                        printLongestHub();
                        cout << endl << "Press ENTER to continue..." << endl;
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        system("cls");
                        break;
                    
                    case 4: // Package Centre with least Packages
                        printShortestHub();
                        cout << endl << "Press ENTER to continue..." << endl;
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        system("cls");
                        break;

                    case 5: // Absolute and relative frequecies of each Package Centre
                        printFrequencies();
                        cout << endl << "Press ENTER to continue..." << endl;
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        system("cls");
                        break;
                    
                    case 6: // Go back to the main menu
                        cout << endl << "Redirecting to the main menu..." << endl;
                        sleep(1);
                        system("cls");
                        mainMenu();
                        break;  
                    
                    default: // Not valid number
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