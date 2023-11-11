#pragma once

#include <iostream>
#include <string>

class АЕRОFLОТ {
    АЕRОFLОТ(); // Default constructor
    АЕRОFLОТ(const std::string& destination, int flightNumber, const std::string& aircraftType);
    АЕRОFLОТ(const АЕRОFLОТ& АЕRОFLОТ); // Copy constructor
    ~АЕRОFLОТ(); // Destructor

    // Getter and setter methods
    const std::string& getDestination() const;
    int getFlightNumber() const;
    const std::string& getAircraftType() const;
    void setDestination(const std::string& destination);
    void setFlightNumber(int flightNumber);
    void setAircraftType(const std::string& aircraftType);

    // Operator overloads
    friend std::ostream& operator<<(std::ostream& out, const АЕRОFLОТ& АЕRОFLОТ);
    friend std::istream& operator>>(std::istream& in, АЕRОFLОТ& АЕRОFLОТ);
    
private:
    std::string destination;
    int flightNumber;
    std::string aircraftType;
};
