#include <iostream>
#include <cmath>

using namespace std;

// Base Class
class Shape {
protected:
    string color;
public:
    Shape(string c) : color(c) {}

    virtual void draw() const = 0;
    virtual double calculateArea() const = 0;
    virtual double calculatePerimeter() const = 0;

    virtual ~Shape() {}  
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(string c, double r) : Shape(c), radius(r) {}

    void draw() const override {
        cout << "Drawing Circle of radius " << radius << " and color " << color << endl;
    }

    double calculateArea() const override {
        return M_PI * radius * radius;
    }

    double calculatePerimeter() const override {
        return 2 * M_PI * radius;
    }
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(string c, double w, double h) : Shape(c), width(w), height(h) {}

    void draw() const override {
        cout << "Drawing Rectangle of width " << width << " and height " << height << endl;
    }

    double calculateArea() const override {
        return width * height;
    }

    double calculatePerimeter() const override {
        return 2 * (width + height);
    }
};

class Triangle : public Shape {
private:
    double a, b, c;  
public:
    Triangle(string col, double s1, double s2, double s3) 
        : Shape(col), a(s1), b(s2), c(s3) {}

    void draw() const override {
        cout << "Drawing Triangle with sides " << a << ", " << b << ", " << c << endl;
    }

    double calculateArea() const override {
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    double calculatePerimeter() const override {
        return a + b + c;
    }
};

class Polygon : public Shape {
private:
    int sides;
    double length;
public:
    Polygon(string c, int s, double l) : Shape(c), sides(s), length(l) {}

    void draw() const override {
        cout << "Drawing Polygon with " << sides << " sides and length " << length << endl;
    }

    double calculateArea() const override {
        return (sides * length * length) / (4 * tan(M_PI / sides));
    }

    double calculatePerimeter() const override {
        return sides * length;
    }
};

int main() {
    Circle circle("Red", 5);
    Rectangle rectangle("Blue", 4, 6);
    Triangle triangle("Green", 3, 4, 5);
    Polygon polygon("Yellow", 6, 4);

    circle.draw();
    cout << "Area: " << circle.calculateArea() << ", Perimeter: " << circle.calculatePerimeter() << endl;

    rectangle.draw();
    cout << "Area: " << rectangle.calculateArea() << ", Perimeter: " << rectangle.calculatePerimeter() << endl;

    triangle.draw();
    cout << "Area: " << triangle.calculateArea() << ", Perimeter: " << triangle.calculatePerimeter() << endl;

    polygon.draw();
    cout << "Area: " << polygon.calculateArea() << ", Perimeter: " << polygon.calculatePerimeter() << endl;

    return 0;
}
