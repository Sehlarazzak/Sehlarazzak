#include <iostream>
#include <string>

using namespace std;

struct Employee {
    int employee_id;
    string name;
    double salary;
};

struct Organisation {
    string organisation_name;
    int organisation_number;
    
   
    Employee emp;
};

int main() 
{
    Organisation org;
    
    org.organisation_name = "Tech Innovations Ltd.";
    org.organisation_number = 12345;
    
    org.emp.employee_id = 101;
    org.emp.name = "John Doe";
    org.emp.salary = 50000.50;
    
    cout << "Organisation Name: " << org.organisation_name << endl;
    cout << "Organisation Number: " << org.organisation_number << endl;
    cout << "Employee ID: " << org.emp.employee_id << endl;
    cout << "Employee Name: " << org.emp.name << endl;
    cout << "Employee Salary: " << org.emp.salary << endl;

    return 0;
}

