#include<iostream>

using namespace std;

class Employee {
public:
    string firstName;
    string lastName;
    double monthlySalary;

    Employee(string fName, string lName, double salary) 
	{
        firstName = fName;
        lastName = lName;
        monthlySalary = (salary > 0) ? salary : 0.0;
    }
    
    double getYearlySalary()
	{
        return monthlySalary * 12;
    }
    
    void giveRaise()
	{
        monthlySalary *= 1.1;
    }
};

int main() {
    Employee emp1("John", "Doe", 3000.0);
    Employee emp2("Jane", "Smith", 4000.0);
    
    cout << "Yearly Salary of " << emp1.firstName << " " << emp1.lastName << ": " << emp1.getYearlySalary() << "\n";
    cout << "Yearly Salary of " << emp2.firstName << " " << emp2.lastName << ": " << emp2.getYearlySalary() << "\n";
 
    emp1.giveRaise();
    emp2.giveRaise();
    
    cout << "After 10% raise:\n";
    cout << "Yearly Salary of " << emp1.firstName << " " << emp1.lastName << ": " << emp1.getYearlySalary() << "\n";
    cout << "Yearly Salary of " << emp2.firstName << " " << emp2.lastName << ": " << emp2.getYearlySalary() << "\n";
    
    return 0;
}


