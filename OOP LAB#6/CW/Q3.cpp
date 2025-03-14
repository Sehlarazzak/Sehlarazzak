#include <iostream>
using namespace std;

class Employee {
protected:
    int id;
    string name;
public:
    Employee(int empId, string empName) : id(empId), name(empName) {}
    virtual void showDetails() const {
        cout << "Employee ID: " << id << " | Name: " << name << endl;
    }
    virtual ~Employee() {}
};

class IOrderTaker {
public:
    virtual void takeOrder() = 0;
    virtual ~IOrderTaker() {}
};

class IOrderPreparer {
public:
    virtual void prepareOrder() = 0;
    virtual ~IOrderPreparer() {}
};

class IBiller {
public:
    virtual void generateBill() = 0;
    virtual ~IBiller() {}
};

class Waiter : public Employee, public IOrderTaker {
public:
    Waiter(int empId, string empName) : Employee(empId, empName) {}
    void takeOrder() override {
        cout << name << " is taking the order." << endl;
    }
};

class Chef : public Employee, public IOrderPreparer {
public:
    Chef(int empId, string empName) : Employee(empId, empName) {}
    void prepareOrder() override {
        cout << name << " is preparing the order." << endl;
    }
};

class Cashier : public Employee, public IBiller {
public:
    Cashier(int empId, string empName) : Employee(empId, empName) {}
    void generateBill() override {
        cout << name << " is generating the bill." << endl;
    }
};

class Manager : public Employee, public IOrderTaker, public IBiller {
public:
    Manager(int empId, string empName) : Employee(empId, empName) {}
    void takeOrder() override {
        cout << name << " (Manager) is taking an order." << endl;
    }
    void generateBill() override {
        cout << name << " (Manager) is generating the bill." << endl;
    }
};

class Menu {
protected:
    string itemName;
    double price;
public:
    Menu(string name, double cost) : itemName(name), price(cost) {}
    virtual double calculateCost() const = 0; // Pure virtual function
    virtual void showItem() const {
        cout << "Item: " << itemName << " | Price: $" << price;
    }
    virtual ~Menu() {}
};

class FoodMenu : public Menu {
public:
    FoodMenu(string name, double cost) : Menu(name, cost) {}
    double calculateCost() const override {
        return price; // No extra tax on food
    }
};

class BeverageMenu : public Menu {
public:
    BeverageMenu(string name, double cost) : Menu(name, cost) {}
    double calculateCost() const override {
        return price * 1.10; 
    }
};

int main() {
    Waiter waiter(101, "Alice");
    Chef chef(102, "Bob");
    Cashier cashier(103, "Charlie");
    Manager manager(104, "Diana");
    waiter.takeOrder();
    chef.prepareOrder();
    cashier.generateBill();
    manager.takeOrder();
    manager.generateBill();
    FoodMenu burger("Burger", 8.99);
    BeverageMenu coffee("Coffee", 3.50);   
    cout << "\nMenu Items:" << endl;
    burger.showItem();
    cout << " | Total Cost: $" << burger.calculateCost() << endl;    
    coffee.showItem();
    cout << " | Total Cost (with tax): $" << coffee.calculateCost() << endl;
    
    return 0;
}