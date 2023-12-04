#include "Menu.hpp"
#include "Utilities.hpp"
#include "Package.hpp"
#include "DLList.hpp"
#include <iostream>
#include <iomanip>
#include <unistd.h>
using namespace std;


DoublyLinkedList allPackages;
void startingMenu(){
    int choice;
    cout << setw(85) << "-------------------------------------   PARCEL SERVICE SIMULATOR   -------------------------------------" << endl;
    cout << endl;
    do {
        cout << "Just in case we want to add some of the improvements" << endl;
        cout << endl;
        cout << "STARTING MENU (enter a number to choose an action):" << endl;
        cout << endl;
        cout << " 1. Start simulation and go to main menu (You won't be able to come back to this menu)." << endl;
        cout << " 0. Exit\n" << endl;
        cout << "Enter a number: " << endl;
        
        if (cin >> choice) {
            cout << endl;
            switch (choice) {
                case 0:
                    cout << "Goodbye!" << endl;
                    exit(0);
                    break;

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

                default:
                    cout << "Invalid input. Please enter a number." << endl;
                    cout << "Redirecting to a new main menu..." << endl;
                    sleep(2);
                    system("cls");
                    break;
            }
        } else {
            cout << endl;
            cout << "Invalid input. Please enter a number." << endl;
            sleep(2);
            system("cls");

            // Clear the input buffer to avoid an infinite loop
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (true);
}

void mainMenu(){
    int choice;
    cout << setw(85) << "-------------------------------------   PARCEL SERVICE SIMULATOR   -------------------------------------" << endl;
    cout << endl;
    do {
        cout << "MAIN MENU (enter a number to choose an action):" << endl;
        cout << endl;
        cout << " 1. Show packages ready to be sent to given Packet Centre." << endl;
        cout << " 2. Show statistics of all Paket Centres." << endl;
        cout << " 3. Search package." << endl;
        cout << " 4. Delete package." << endl;
        cout << " 5. Transport package form Salamanca's Packet Central Station to given Packet Centre." << endl;
        cout << " 6. Transport package from its Packet Centre to given Packet Centre." << endl;
        cout << " 7. Next step." << endl;
        cout << " 0. Exit\n" << endl;
        cout << "Enter a number: " << endl;
        
        if (cin >> choice) {
            cout << endl;
            switch (choice) {
                case 0:
                    cout << "Goodbye!" << endl;
                    exit(0);
                    break;

                case 1:
                    cout << "Nothing is going on here right now :(  -> packages ready to be delivered to PCs" << endl;
                    break;

                case 2:
                    cout << "Nothing is going on here right now :(  -> PCs statistics" << endl;
                    break;

                case 3:
                    cout << "Introduce the label of the package you are looking for:" << endl;
                    // string label;
                    // getline(cin >> ws, label);
                    // cout << endl;
                    break;

                case 4:
                    cout << "Introduce the label of the package you want to delete:" << endl;
                    // string label;
                    // getline(cin >> ws, label);
                    // cout << endl;
                    break;

                case 5:
                    cout << "Nothing is going on here right now :(  -> transport from SPCS to PC" << endl;
                    break;

                case 6:
                    cout << "Nothing is going on here right now :(  -> transport from PC to PC" << endl;
                    break;

                case 7:
                    cout << "Nothing is going on here right now :(  -> 1 Step" << endl;
                    break;

                default:
                    cout << "Invalid choice" << endl;
                    sleep(2);
                    system("cls");
                    break;
            }
        } else {
            cout << endl;
            cout << "Invalid input. Please enter a number." << endl;
            cout << "Redirecting to a new main menu..." << endl;
            sleep(2);
            system("cls");

            // Clear the input buffer to avoid an infinite loop
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (true);
}
