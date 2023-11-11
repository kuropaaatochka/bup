#include "Menu.h"

using namespace std;

void Menu::task_1() {
    
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
