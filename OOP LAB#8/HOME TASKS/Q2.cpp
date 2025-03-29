#include <iostream>
using namespace std;

class Shape {
private:
    float area;

public:
    Shape(float a = 0) : area(a) {}

    Shape operator+(const Shape& obj) {
        return Shape(area + obj.area);
    }

    void Area() const {
        cout << "Area: " << area << " sq. units" << endl;
    }
};

int main() {
    Shape shape1(25.5);  
    Shape shape2(40.3);  

    cout << "Shape 1 ";
    shape1.Area();

    cout << "Shape 2 ";
    shape2.Area();

    Shape shape3 = shape1 + shape2;

    cout << "After Adding Shape 1 and Shape 2 ";
    shape3.Area();

    return 0;
}
