#include <iostream>
using namespace std;

class Vehicle {
protected:
    double price;

public:
    Vehicle(double p) : price(p) {}
    virtual void display() const = 0; 
    virtual ~Vehicle() {}
};

class Car : public Vehicle {
protected:
    int seatingCapacity;
    int numDoors;
    string fuelType;

public:
    Car(double p, int seat, int doors, string fuel) : Vehicle(p), seatingCapacity(seat), numDoors(doors), fuelType(fuel) {}
};

class Motorcycle : public Vehicle {
protected:
    int numCylinders;
    int numGears;
    int numWheels;

public:
    Motorcycle(double p, int cylinders, int gears, int wheels) : Vehicle(p), numCylinders(cylinders), numGears(gears), numWheels(wheels) {}
};

class Audi : public Car {
private:
    string modelType;

public:
    Audi(double p, int seat, int doors, string fuel, string model) : Car(p, seat, doors, fuel), modelType(model) {}
    void display() const override {
        cout << "Audi Car Details:\n";
        cout << "Price: $" << price << "\nSeating Capacity: " << seatingCapacity << "\nNumber of Doors: " << numDoors << "\nFuel Type: " << fuelType << "\nModel Type: " << modelType << "\n\n";
    }
};

class Yamaha : public Motorcycle {
private:
    string makeType;

public:
    Yamaha(double p, int cylinders, int gears, int wheels, string make) : Motorcycle(p, cylinders, gears, wheels), makeType(make) {}
    void display() const override {
        cout << "Yamaha Motorcycle Details:\n";
        cout << "Price: $" << price << "\nNumber of Cylinders: " << numCylinders << "\nNumber of Gears: " << numGears << "\nNumber of Wheels: " << numWheels << "\nMake Type: " << makeType << "\n\n";
    }
};

int main() {
    Audi myAudi(50000, 5, 4, "Petrol", "A6");
    Yamaha myYamaha(15000, 2, 6, 2, "YZF-R1");
    
    myAudi.display();
    myYamaha.display();
    
    return 0;

