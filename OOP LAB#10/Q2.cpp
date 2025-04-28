#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

struct Employee {
    int id;
    string name;
    string designation;
    int years_of_service;
};

class EmployeeDatabase {
private:
    vector<Employee> employees;
    string filename = "employees.txt";

public:
    void createDummyData() {
        ofstream file(filename);
        file << "1,John Doe,manager,3\n";
        file << "2,Jane Smith,developer,1\n";
        file << "3,Michael Johnson,manager,1\n";
        file << "4,Sarah Brown,manager,5\n";
        file << "5,Emily Davis,developer,2\n";
        file.close();
    }

    void loadData() {
        employees.clear();
        ifstream file(filename);
        string line;
        while (getline(file, line)) {
            stringstream ss(line);
            string idStr, name, designation, yearsStr;
            getline(ss, idStr, ',');
            getline(ss, name, ',');
            getline(ss, designation, ',');
            getline(ss, yearsStr, ',');
            Employee emp = { stoi(idStr), name, designation, stoi(yearsStr) };
            employees.push_back(emp);
        }
        file.close();
    }

    vector<Employee> findManagers() {
        vector<Employee> result;
        for (auto& emp : employees) {
            if (emp.designation == "manager" && emp.years_of_service >= 2) {
                result.push_back(emp);
            }
        }
        return result;
    }

    void deleteExceptManagers(const vector<Employee>& managers) {
        ofstream file(filename);
        for (auto& emp : managers) {
            file << emp.id << "," << emp.name << "," << emp.designation << "," << emp.years_of_service << "\n";
        }
        file.close();
    }

    void writeIncrementedData(const vector<Employee>& managers) {
        ofstream file(filename, ios::app); 
        for (auto& emp : managers) {
            file << emp.id + 100 << "," << emp.name << "," << emp.designation << "," << emp.years_of_service + 1 << "\n";
        }
        file.close();
    }

    void displayAll() {
        cout << "Current Employees in File:\n";
        for (auto& emp : employees) {
            cout << emp.id << " " << emp.name << " " << emp.designation << " " << emp.years_of_service << "\n";
        }
    }
};

int main() {
    EmployeeDatabase db;

    db.createDummyData();
    db.loadData();
    db.displayAll();

    vector<Employee> managers = db.findManagers();
    cout << "\nManagers with at least 2 years of service:\n";
    for (auto& emp : managers) {
        cout << emp.id << " " << emp.name << " " << emp.designation << " " << emp.years_of_service << "\n";
    }

    db.deleteExceptManagers(managers);

    db.writeIncrementedData(managers);

    cout << "\nFinal State After Deletions and Insertions:\n";
    db.loadData();
    db.displayAll();

    return 0;
}
