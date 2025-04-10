#include <iostream>
#include <fstream>
using namespace std;

class Vehicle {
public:
    string regNo;
    string color;

    Vehicle(string reg, string col) {

        regNo = reg;
        color = col;
    }

    void displayData() {

        cout << "\nVehicle Registration: " << regNo << endl;
        cout << "Color: " << color << endl;
    }

    void writeToFile(ofstream &outFile) {

        outFile << "\nVehicle Registration: " << regNo << endl;
        outFile << "Color: " << color << endl;
    }
};

class Car : public Vehicle {
public:
    int noOfSeats;

    Car(string reg, string col, int seats) : Vehicle(reg, col) {

        noOfSeats = seats;
    }

    void displayData() {

        cout << "\nCar Details:" << endl;
        Vehicle::displayData();
        cout << "Number of seats: " << noOfSeats << endl;
    }

    void writeToFile(ofstream &outFile) {

        outFile << "\nCar Details:" << endl;
        Vehicle::writeToFile(outFile);
        outFile << "Number of seats: " << noOfSeats << endl;
    }
};

class Bike : public Vehicle {

public:
    int engineCapacity;

    Bike(string reg, string col, int capacity) : Vehicle(reg, col) {

        engineCapacity = capacity;
    }

    void displayData() {

        cout << "\nBike Details:" << endl;
        Vehicle::displayData();
        cout << "Engine Capacity: " << engineCapacity << "cc" << endl;
    }

    void writeToFile(ofstream &outFile) {

        outFile << "\nBike Details:" << endl;
        Vehicle::writeToFile(outFile);
        outFile << "Engine Capacity: " << engineCapacity << "cc" << endl;
    }
};

int main() {

    Car c1("XYR345", "Navy Blue", 7);
    Bike b1("UQY896", "Black", 150);

    c1.displayData();
    b1.displayData();

    ofstream outFile("VehicleDetails.txt");
    if (outFile.is_open()) {

        c1.writeToFile(outFile);
        b1.writeToFile(outFile);
        outFile.close();

        cout << "\nDetails have been written to 'VehicleDetails.txt'." << endl;

    } else {

        cout << "Error opening file!" << endl;
    }

    return 0;
}
