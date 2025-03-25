#include <iostream>
#include <vector>

using namespace std;

class Person {
protected:
    string name, id, address, phoneNumber, email;

public:
    Person(string n, string i, string addr, string phone, string mail)
        : name(n), id(i), address(addr), phoneNumber(phone), email(mail) {}

    virtual void displayInfo() const {
        cout << "\nName: " << name << "\nID: " << id
             << "\nAddress: " << address << "\nPhone: " << phoneNumber
             << "\nEmail: " << email << endl;
    }

    virtual ~Person() {} 
};

class Student : public Person {
private:
    vector<string> coursesEnrolled;
    double gpa;
    int enrollmentYear;

public:
    Student(string n, string i, string addr, string phone, string mail, double g, int year)
        : Person(n, i, addr, phone, mail), gpa(g), enrollmentYear(year) {}

    void enrollCourse(string course) {
        coursesEnrolled.push_back(course);
    }

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Enrollment Year: " << enrollmentYear << "\nGPA: " << gpa << "\nCourses Enrolled: ";
        for (const string &course : coursesEnrolled)
            cout << course << ", ";
        cout << endl;
    }
};


class Professor : public Person {
private:
    string department;
    vector<string> coursesTaught;
    double salary;

public:
    Professor(string n, string i, string addr, string phone, string mail, string dept, double sal)
        : Person(n, i, addr, phone, mail), department(dept), salary(sal) {}

    void addCourse(string course) {
        coursesTaught.push_back(course);
    }

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Department: " << department << "\nSalary: $" << salary << "\nCourses Taught: ";
        for (const string &course : coursesTaught)
            cout << course << ", ";
        cout << endl;
    }
};

class Staff : public Person {
private:
    string department, position;
    double salary;

public:
    Staff(string n, string i, string addr, string phone, string mail, string dept, string pos, double sal)
        : Person(n, i, addr, phone, mail), department(dept), position(pos), salary(sal) {}

    void displayInfo() const override {
        Person::displayInfo();
        cout << "Department: " << department << "\nPosition: " << position << "\nSalary: $" << salary << endl;
    }
};

class Course {
private:
    string courseId, courseName, instructor, schedule;
    int credits;
    vector<Student *> registeredStudents;

public:
    Course(string id, string name, int cr, string instr, string sched)
        : courseId(id), courseName(name), credits(cr), instructor(instr), schedule(sched) {}

    void registerStudent(Student *student) {
        registeredStudents.push_back(student);
        student->enrollCourse(courseName);
    }

    void displayCourseInfo() const {
        cout << "\nCourse ID: " << courseId << "\nCourse Name: " << courseName
             << "\nCredits: " << credits << "\nInstructor: " << instructor
             << "\nSchedule: " << schedule << "\nStudents Enrolled: ";
        for (const Student *student : registeredStudents)
            cout << student->getName() << ", ";
        cout << endl;
    }
};

int main() {
    Student student1("Ali Khan", "S101", "Karachi", "03001234567", "ali@example.com", 3.8, 2023);
    Professor prof1("Dr. Ahmed", "P201", "Lahore", "03219876543", "ahmed@example.com", "Computer Science", 150000);
    prof1.addCourse("Data Structures");
    prof1.addCourse("Algorithms");

    Staff staff1("Mr. Faisal", "ST301", "Islamabad", "03329876542", "faisal@example.com", "Admin", "HR Manager", 80000);

    Course course1("CS101", "Object-Oriented Programming", 3, "Dr. Ahmed", "MWF 10:00-11:30 AM");
    
    course1.registerStudent(&student1);

    cout << "\n--- Student Information ---";
    student1.displayInfo();

    cout << "\n--- Professor Information ---";
    prof1.displayInfo();

    cout << "\n--- Staff Information ---";
    staff1.displayInfo();

    cout << "\n--- Course Information ---";
    course1.displayCourseInfo();

    return 0;
}
