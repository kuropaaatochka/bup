#pragma once

#include <iostream>
#include <fstream>
#include <string>

// Define the Animal class as the base class
class Animal {
public:
    Animal() = default;  // Default constructor

    virtual void displayInfo() const = 0;
    virtual void modify() = 0;
    virtual void saveToFile(std::ofstream& file) const = 0;
    virtual void loadFromFile(std::ifstream& file) = 0;

    virtual ~Animal() = default;  // Virtual destructor
};
