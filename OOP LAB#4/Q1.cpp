#include <iostream>
#define PI 3.14159

class Circle {
private:
    double radius;

public:
    Circle(double r) {
        radius = r;
    }

    double getArea() const {
        return PI * radius * radius;
    }

    double getPerimeter() const {
        return 2 * PI * radius;
    }
};

int main() {
    double r;
    std::cout << "Enter radius: ";
    std::cin >> r;
    
    Circle circle(r);
    std::cout << "Area: " << circle.getArea() << std::endl;
    std::cout << "Perimeter: " << circle.getPerimeter() << std::endl;
    
    return 0;
}

