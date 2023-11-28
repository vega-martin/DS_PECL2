#include "Menu.hpp"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <unistd.h>
using namespace std;

void startingMenu(){
    int choice;
    cout << setw(85) << "-------------------------------------   PARCEL SERVICE SIMULATOR   -------------------------------------" << endl;

    do {
        cout << endl;
        cout << "Just in case we want to add some of the improvements" << endl;
        cout << endl;
        cout << "STARTING MENU (enter a number to choose an action):" << endl;
        cout << endl;
        cout << " 1. Start simulation and go to main menu (You won't be able to come back to this menu)." << endl;
        cout << " 0. Exit\n" << endl;
        cout << "Enter a number: " << endl;
        cin >> choice;
        cout << endl;
        
        string label;
        switch(choice){
            case 0:
                cout << "Good bye!" << endl;
                return;
                
            case 1:
                system("cls");
                cout << "Packages are being created." << endl;
                // generate packages
                sleep(5);
                system("cls");
                mainMenu();
                break;
                
            default:
                system("cls");
                cout << "Invalid choice"<< endl;
                break;
        }
    } while (choice != 0);
}

void mainMenu(){
    int choice;
    cout << setw(85) << "-------------------------------------   PARCEL SERVICE SIMULATOR   -------------------------------------" << endl;

    do {
        cout << endl;
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
        cin >> choice;
        cout << endl;
        
        string label;
        switch(choice){
            case 0:
                cout << "Good bye!" << endl;
                return;
                
            case 1:
                cout << "Nothing is going on here right now :(  -> packages ready to be delivered to PCs" << endl;
                break;
                
            case 2:
                cout << "Nothing is going on here right now :(  -> PCs statistics" << endl;
                break;
                
            case 3:
                cout << "Introduce the label of the package you are looking for:" << endl;
                //getline(cin >> ws, label);
                //cout << endl;
                break;
                
            case 4:
                cout << "Introduce the label of the package you want to delete:" << endl;
                //getline(cin >> ws, label);
                //cout << endl;
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
                system("cls");
                cout << "Invalid choice"<< endl;
                break;
        }
    } while (choice != 0);
}

