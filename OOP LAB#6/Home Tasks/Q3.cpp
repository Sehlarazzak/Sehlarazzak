#include <iostream>
using namespace std;

class Student {
protected:
    int id;
    string name;

public:
    Student(int i, string n) : id(i), name(n) {}
    void getStudentDetails() const {
        cout << "Student ID: " << id << "\nName: " << name << "\n";
    }
};

class Marks : public Student {
protected:
    int marks_oop, marks_pf, marks_ds, marks_db;

public:
    Marks(int i, string n, int oop, int pf, int ds, int db) : Student(i, n), marks_oop(oop), marks_pf(pf), marks_ds(ds), marks_db(db) {}
    void getMarks() const {
        cout << "Marks in Courses:\n";
        cout << "OOP: " << marks_oop << "\nPF: " << marks_pf << "\nDS: " << marks_ds << "\nDB: " << marks_db << "\n";
    }
};

class Result : public Marks {
protected:
    int total_marks;
    double avg_marks;

public:
    Result(int i, string n, int oop, int pf, int ds, int db) : Marks(i, n, oop, pf, ds, db) {
        total_marks = marks_oop + marks_pf + marks_ds + marks_db;
        avg_marks = total_marks / 4.0;
    }
    void display() const {
        cout << "Total Marks: " << total_marks << "\nAverage Marks: " << avg_marks << "\n";
    }
};

int main() {
    Result student(101, "John Doe", 85, 90, 78, 88);
    student.getStudentDetails();
    student.getMarks();
    student.display();
    
    return 0;
}
