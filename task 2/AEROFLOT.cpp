#include "AEROFLOT.h"

AEROFLOT::AEROFLOT() 
    : destination("None")
    , flightNumber(0)
    , aircraftType("None")
{
    std::cout << "Default AEROFLOT constructor called." << std::endl;
}

AEROFLOT::AEROFLOT(const std::string& dest, int flight, const std::string& type)
    : destination(dest)
    , flightNumber(flight)
    , aircraftType(type)
{
    std::cout << "Constructor with parameters called." << std::endl;
}

AEROFLOT::AEROFLOT(const AEROFLOT& AEROFLOT) 
    : destination(AEROFLOT.destination)
    , flightNumber(AEROFLOT.flightNumber)
    , aircraftType(AEROFLOT.aircraftType)
{
    std::cout << "Copy constructor called." << std::endl;
}

AEROFLOT::~AEROFLOT() {
    std::cout << "Destructor called." << std::endl;
}

const std::string& AEROFLOT::getDestination() const {
    return destination;
}

int AEROFLOT::getFlightNumber() const {
    return flightNumber;
}

const std::string& AEROFLOT::getAircraftType() const {
    return aircraftType;
}

int AEROFLOT::getNumFlights() const {
    return numFlights;
}

void AEROFLOT::setDestination(const std::string& dest) {
    destination = dest;
}

void AEROFLOT::setFlightNumber(const int flight) {
    if (flight < 0) {
        throw std::invalid_argument("Flight number cannot be negative.");
    }
    flightNumber = flight;
}

void AEROFLOT::setAircraftType(const std::string& type) {
    aircraftType = type;
}

void AEROFLOT::setNumFlights(const int num) {
    try {
        if (std::cin.fail()) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            throw std::invalid_argument("Invalid input. Please enter an integer.");
        }

        numFlights = num;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}

void AEROFLOT::displayFlights() {
    if (!numFlights) {
        for (int i = 0; i < numFlights; i++) {
            std::cout << flights[i];
        }
    }
}

void AEROFLOT::displayFlightsToDestination(const std::string& dest) {
    bool found = false;
    for (int i = 0; i < numFlights; i++) {
        if (flights[i].getDestination() == dest) {
            std::cout << flights[i]; 
            found = true;
        }
    }
    if (!found) {
        std::cout << "No flights to the specified destination." << std::endl;
    }
}

void AEROFLOT::addFlightToPosition(const int position, const AEROFLOT& flight) {
    try {
        if (position < 0 || position > numFlights) {
            throw std::invalid_argument("Invalid position for adding a new flight.");
        }

        // Increase the size of the flights array by one
        AEROFLOT* newFlights = new AEROFLOT[numFlights + 1];

        // Copy existing flights up to the specified position
        for (int i = 0; i < position; i++) {
            newFlights[i] = flights[i];
        }

        // Insert the new flight at the specified position
        newFlights[position] = flight;

        // Copy the remaining flights after the inserted position
        for (int i = position + 1; i <= numFlights; i++) {
            newFlights[i] = flights[i - 1];
        }

        // Deallocate memory for the old flights array
        delete[] flights;

        // Update flights pointer to point to the new array
        flights = newFlights;

        // Increment the number of flights
        numFlights++;

        std::cout << "Flight successfully added at position " << position << ".\n";
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
}


void AEROFLOT::editFlight(const int index) {
    if (index < 0 || index >= numFlights) {
        throw std::out_of_range("Invalid index for editing a flight.");
    }
    std::cout << "Editing Flight at index " << index << "\n";
    
    try {
        // Prompt user for what to change
        std::cout << "Choose what to change:\n";
        std::cout << "1. Flight Number\n";
        std::cout << "2. Destination\n";
        std::cout << "3. Aircraft Type\n";
        int choice;
        std::cin >> choice;

        if (std::cin.fail()) {
            throw std::invalid_argument("Invalid input. Please enter an integer.");
        }

        switch (choice) {
            case 1:
                // Change Flight Number
                int newFlightNumber;
                std::cout << "Enter new Flight Number: ";
                std::cin >> newFlightNumber;
                flights[index].setFlightNumber(newFlightNumber);
                break;
            case 2:
                // Change Destination
                std::cout << "Enter new Destination: ";
                std::cin >> flights[index].destination;
                break;
            case 3:
                // Change Aircraft Type
                std::cout << "Enter new Aircraft Type: ";
                std::cin >> flights[index].aircraftType;
                break;
            default:
                throw std::invalid_argument("Invalid choice. Please choose 1, 2, or 3.");
        }

        std::cout << "Flight at index " << index << " successfully edited.\n";
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        // Clear input buffer to avoid infinite loop in case of non-integer input
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}


std::ostream& operator<<(std::ostream& out, const AEROFLOT& AEROFLOT) {
    out << "Destination: " << AEROFLOT.destination << "\n";
    out << "Flight Number: " << AEROFLOT.flightNumber << "\n";
    out << "Aircraft Type: " << AEROFLOT.aircraftType << "\n";
    return out;
}

std::istream& operator>>(std::istream& in, AEROFLOT& AEROFLOT) {
    std::cout << "Enter Destination: ";
    in >> AEROFLOT.destination;
    
    int flightNumber;
    std::cout << "Enter Flight Number: ";
    in >> flightNumber;
    
    if (flightNumber < 0) {
        throw std::invalid_argument("Flight number cannot be negative.");
    }
    
    AEROFLOT.flightNumber = flightNumber;
    
    std::cout << "Enter Aircraft Type: ";
    in >> AEROFLOT.aircraftType;
    return in;
}

void AEROFLOT::operator+=(const AEROFLOT& newFlight) {
    try {
        // Create a new array with increased size
        AEROFLOT* newFlights = new AEROFLOT[numFlights + 1];

        // Copy existing flights to the new array
        for (int i = 0; i < numFlights; i++) {
            newFlights[i] = flights[i];
        }

        // Add the new flight to the end of the array
        newFlights[numFlights] = newFlight;

        // Deallocate memory for the old flights array
        delete[] flights;

        // Update flights pointer to point to the new array
        flights = newFlights;

        // Increment the number of flights
        numFlights++;

        std::cout << "Flight successfully added.\n";
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
    
}

void AEROFLOT::operator-=(const int indexToRemove) {
    try {
        if (indexToRemove < 0 || indexToRemove >= numFlights) {
            throw std::out_of_range("Invalid index for removing a flight.");
        }
        
        // Create a new array with reduced size
        AEROFLOT* newFlights = new AEROFLOT[numFlights - 1];

        // Copy existing flights to the new array excluding the specified index
        int newIndex = 0;
        for (int i = 0; i < numFlights; i++) {
            if (i != indexToRemove) {
                newFlights[newIndex] = flights[i];
                newIndex++;
            }
        }

        // Deallocate memory for the old flights array
        delete[] flights;

        // Update flights pointer to point to the new array
        flights = newFlights;

        // Update the number of flights
        numFlights--;

        std::cout << "Flight at index " << indexToRemove << " successfully removed.\n";
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }
    
}
