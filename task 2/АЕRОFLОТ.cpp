#include "АЕRОFLОТ.h"
//#include "АЕRОFLОТ.h"

АЕRОFLОТ::АЕRОFLОТ() 
    : destination("None")
    , flightNumber(0)
    , aircraftType("None")
{
    std::cout << "Default constructor called." << std::endl;
}

АЕRОFLОТ::АЕRОFLОТ(const std::string& dest, int flight, const std::string& type)
    : destination(dest)
    , flightNumber(flight)
    , aircraftType(type)
{
    std::cout << "Constructor with parameters called." << std::endl;
}

АЕRОFLОТ::АЕRОFLОТ(const АЕRОFLОТ& АЕRОFLОТ) 
    : destination(АЕRОFLОТ.destination)
    , flightNumber(АЕRОFLОТ.flightNumber)
    , aircraftType(АЕRОFLОТ.aircraftType)
{
    std::cout << "Copy constructor called." << std::endl;
}

АЕRОFLОТ::~АЕRОFLОТ() {
    std::cout << "Destructor called." << std::endl;
}

const std::string& АЕRОFLОТ::getDestination() const {
    return destination;
}

int АЕRОFLОТ::getFlightNumber() const {
    return flightNumber;
}

const std::string& АЕRОFLОТ::getAircraftType() const {
    return aircraftType;
}

void АЕRОFLОТ::setDestination(const std::string& dest) {
    destination = dest;
}

void АЕRОFLОТ::setFlightNumber(int flight) {
    if (flight < 0) {
        throw std::invalid_argument("Flight number cannot be negative.");
    }
    flightNumber = flight;
}

void АЕRОFLОТ::setAircraftType(const std::string& type) {
    aircraftType = type;
}


std::ostream& operator<<(std::ostream& out, const АЕRОFLОТ& АЕRОFLОТ) {
    out << "Destination: " << АЕRОFLОТ.destination << "\n";
    out << "Flight Number: " << АЕRОFLОТ.flightNumber << "\n";
    out << "Aircraft Type: " << АЕRОFLОТ.aircraftType << "\n";
    return out;
}

std::istream& operator>>(std::istream& in, АЕRОFLОТ& АЕRОFLОТ) {
    std::cout << "Enter Destination: ";
    in >> АЕRОFLОТ.destination;
    
    int flightNumber;
    std::cout << "Enter Flight Number: ";
    in >> flightNumber;
    
    if (flightNumber < 0) {
        throw std::invalid_argument("Flight number cannot be negative.");
    }
    
    АЕRОFLОТ.flightNumber = flightNumber;
    
    std::cout << "Enter Aircraft Type: ";
    in >> АЕRОFLОТ.aircraftType;
    return in;
}
