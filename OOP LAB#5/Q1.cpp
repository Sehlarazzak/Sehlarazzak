#include <iostream>

class Engine {
private:
    bool isRunning;

public:
    Engine() : isRunning(false) {}

    void start() {
        if (!isRunning) {
            isRunning = true;
            std::cout << "Engine started" << std::endl;
        } else {
            std::cout << "Engine is already running" << std::endl;
        }
    }

    void stop() {
        if (isRunning) {
            isRunning = false;
            std::cout << "Engine stopped" << std::endl;
        } else {
            std::cout << "Engine is already stopped" << std::endl;
        }
    }
};

class Car {
private:
    Engine engine; // Composition: Car "has-a" Engine

public:
    void startCar() {
        engine.start();
    }

    void stopCar() {
        engine.stop();
    }
};

int main() {
    Car myCar;
    myCar.startCar();
    myCar.stopCar();
    return 0;
}

