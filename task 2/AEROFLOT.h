#pragma once

#include "AeroflotException.h"

#include <iostream>
#include <string>

class AEROFLOT {
public:
    AEROFLOT(); // Default constructor
    AEROFLOT(const std::string& destination, int flightNumber, const std::string& aircraftType); // Constructor with parameters
    AEROFLOT(const AEROFLOT& AEROFLOT); // Copy constructor
    ~AEROFLOT(); // Destructor

    // Getter and setter methods
    const std::string& getDestination() const;
    int getFlightNumber() const;
    const std::string& getAircraftType() const;
    int getNumFlights() const;
    AEROFLOT getFlight(int index) const {
        return flights[index];
    }
    
    void setDestination(const std::string& destination);
    void setFlightNumber(const int flightNumber);
    void setAircraftType(const std::string& aircraftType);
    void setNumFlights(const int num);
    
    void displayFlights();
    void displayFlightsToDestination(const std::string& dest);
    void editFlight(const int index);
    void addFlightToPosition(int position, const AEROFLOT& flight);

    // Operator overloads
    friend std::ostream& operator<<(std::ostream& out, const AEROFLOT& AEROFLOT);
    friend std::istream& operator>>(std::istream& in, AEROFLOT& AEROFLOT);
    
    void operator+=(const AEROFLOT& newFlight);
    void operator-=(const int indexToRemove);
    
private:
    int numFlights;
    std::string destination;
    int flightNumber;
    std::string aircraftType;
    
    AEROFLOT* flights;
};
