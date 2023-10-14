#pragma once

#include <iostream>
#include <string>

// Define custom exception class
class AnimalException : public std::exception {
public:
    AnimalException(const std::string& message) : msg(message) {}

    const char* what() const noexcept override {
        return msg.c_str();
    }

private:
    std::string msg;
};
