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
    task_2();
}
