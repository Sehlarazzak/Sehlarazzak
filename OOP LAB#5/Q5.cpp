#include <iostream>

class Car {
public:
    int engine_horsepower;
    int seating_capacity;
    int no_of_speakers;

    Car(int hp, int seats, int speakers) : engine_horsepower(hp), seating_capacity(seats), no_of_speakers(speakers) {}

    void displayCarDetails() const {
        std::cout << "Engine Horsepower: " << engine_horsepower << std::endl;
        std::cout << "Seating Capacity: " << seating_capacity << std::endl;
        std::cout << "Number of Speakers: " << no_of_speakers << std::endl;
    }

    void updateCarDetails(int hp, int seats, int speakers) const {
        Car* nonConstThis = const_cast<Car*>(this);
        nonConstThis->engine_horsepower = hp;
        nonConstThis->seating_capacity = seats;
        nonConstThis->no_of_speakers = speakers;
    }
};

int main() {
    Car myCar(200, 5, 6);
    myCar.displayCarDetails();
    
    myCar.updateCarDetails(250, 4, 8);
    std::cout << "\nAfter updating:\n";
    myCar.displayCarDetails();
    
    return 0;
}

