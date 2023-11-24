#include "Menu.h"

using namespace std;

void Menu::task_1() {
    AEROFLOT flights;   // flights array initiator
    
    while (true) {
        cout << "Options:" << endl;
        cout << "1. Add a new flight" << endl;
        cout << "2. Edit a flight" << endl;
        cout << "3. Delete a flight" << endl;
        cout << "4. Display all flights" << endl;
        cout << "5. Display flights to a specific destination" << endl;
        cout << "6. Exit" << endl;
        
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        
        try {
            switch (choice) {
                case 1: { // Add a new flight
                    AEROFLOT newFlight;
                    try {
                        std::cin >> newFlight; // Use the overloaded '>>' operator
                        flights += newFlight;
                        cout << "The flight was added." << endl;
                    } catch (const std::invalid_argument& e) {
                        std::cerr << "Error: " << e.what() << std::endl;
                        continue;
                    }
                    
                    break;
                }
                case 2: {
                    try {
                        cout << "Input an index of the flight to be edited: ";
                        int indexToEdit;
                        cin >> indexToEdit;
                        
                        flights.editFlight(indexToEdit);
                    } catch (const std::exception& e) {
                        std::cerr << "Error: " << e.what() << "\n";
                    }
                    break;
                }
                case 3: {
                    try {
                        cout << "Input an index of the flight to be deleted: ";
                        int indexToDelete;
                        cin >> indexToDelete;
                        
                        flights -= indexToDelete;
                    } catch (const std::exception& e) {
                        std::cerr << "Error: " << e.what() << "\n";
                    }
                    break;
                }
                case 4:
                    flights.displayFlights();
                    break;
                case 5:
                    try {
                        std::string destination;
                        std::cout << "Enter the destination to display flights: ";
                        std::cin >> destination;
                        
                        flights.displayFlightsToDestination(destination);
                    } catch (const std::exception& e) {
                        std::cerr << "Error: " << e.what() << "\n";
                    }
                    break;
                case 6:
                    return;
                    break;
                default:
                    break;
            }
        } catch (const std::invalid_argument& e) {
            std::cerr << "Invalid input: " << e.what() << std::endl;
        }
        
    }
    
    
    
//    cout << "Enter data" << endl;
//    cin >> aeroflot;
//    cout << endl;
//    cout << aeroflot;
//    
}

void Menu::task_2() {
    string fileName;
        cout << "Enter the file name to read from: ";
        cin >> fileName;
    
    try {
        ifstream inputFile(fileName);  
        if (!inputFile.is_open()) {
            throw runtime_error("Error opening the file.");
        }

        string word;
        while (inputFile >> word) {
            if (word.find_first_of("AEIOUaeiou") == 0) {
                cout << word << endl;
            }
        }
        inputFile.close();
    } catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }
}

void Menu::mainMenu() {
    char option;
    
    while (true) {
         try {
            cout << "========== Main menu ==========" << endl;
            cout << "1. Run Task 1" << endl;
            cout << "2. Run Task 2" << endl;
            cout << "0. Exit" << endl;
            cout << "===========================" << endl;
            cout << "Enter the option: ";
            
            cin >> option;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clear the input buffer
            
            switch (option) {
                case '1':
                    task_1();
                    break;
                case '2':
                    task_2();
                    break;
                case '0':
                    cout << "Exiting the program." << endl;
                    return;
                default:
                    throw invalid_argument("Incorrect value");
            }
        }
        catch (const exception& e) {
            cerr << "Invalid input: " << e.what() << endl;
        }
    }
}
