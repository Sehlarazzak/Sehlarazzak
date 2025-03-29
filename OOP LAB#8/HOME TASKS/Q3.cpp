#include <iostream>
#include <string>
using namespace std;


class Person {
protected:
    int empID;

public:
    virtual void getData() {
        cout << "Enter Employee ID: ";
        cin >> empID;
    }

    virtual void displayData() {
        cout << "Employee ID: " << empID << endl;
    }

    virtual ~Person() {}
};

class Admin : public Person {
protected:
    string name;
    double monthlyIncome;

public:
    void getData() override {
        Person::getData();
        cout << "Enter Employee Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Monthly Income: ";
        cin >> monthlyIncome;
    }

    void displayData() override {
        Person::displayData();
        cout << "Employee Name: " << name << endl;
        cout << "Monthly Income: $" << monthlyIncome << endl;
        cout << "Annual Bonus: $" << bonus() << endl;
    }

    double bonus() {
        return monthlyIncome * 12 * 0.05; // 5% of annual salary
    }
};

// Derived class Accounts
class Accounts : public Person {
protected:
    string name;
    double monthlyIncome;

public:
    void getData() override {
        Person::getData();
        cout << "Enter Employee Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Monthly Income: ";
        cin >> monthlyIncome;
    }

    void displayData() override {
        Person::displayData();
        cout << "Employee Name: " << name << endl;
        cout << "Monthly Income: $" << monthlyIncome << endl;
        cout << "Annual Bonus: $" << bonus() << endl;
    }

    double bonus() {
        return monthlyIncome * 12 * 0.05; 
    }
};

int main() {
    Admin adminEmployee;
    Accounts accountsEmployee;

    cout << "\nEnter details for Admin Employee:\n";
    adminEmployee.getData();

    cout << "\nEnter details for Accounts Employee:\n";
    accountsEmployee.getData();

    cout << "\n--- Employee Details ---\n";
    adminEmployee.displayData();
    cout << "-----------------------\n";
    accountsEmployee.displayData();

    return 0;
}


