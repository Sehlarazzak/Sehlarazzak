#include <iostream>
#include <string>

class Student {
private:
    const int roll_no;

public:
    Student(int roll) : roll_no(roll) {}
    
    void display() const {
        std::cout << "Student Roll Number: " << roll_no << std::endl;
    }
};

int main() {
    int roll;
    std::cout << "Enter roll number: ";
    std::cin >> roll;
    
    Student student(roll);
    student.display();
    
    return 0;
}
