#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
using namespace std;

class DatabaseSystem {
public:
    void createDummyData() {
        ofstream users("users.txt");
        users << "1,Linus,Torvalds,Finland,linus@example.com\n";
        users << "2,Ada,Lovelace,UK,ada@example.com\n";
        users << "3,Alan,Turing,UK,alan@example.com\n";
        users.close();

        ofstream products("products.txt");
        products << "1,Laptop,High-performance laptop,1500\n";
        products << "2,Phone,Smartphone,800\n";
        products << "3,Tablet,Lightweight tablet,600\n";
        products << "4,Monitor,4K Monitor,400\n";
        products.close();

        ofstream orders("orders.txt");
        orders << "1,1,1,1500\n";  
        orders << "2,2,2,800\n";  
        orders << "3,1,3,600\n";   
        orders << "4,3,4,400\n";   
        orders.close();
    }

    void fetchProductsOfUser(const string& firstName) {
        unordered_map<string, string> userIdMap; 
        ifstream userFile("users.txt");
        string line;

        while (getline(userFile, line)) {
            stringstream ss(line);
            string id, fname, lname, address, email;
            getline(ss, id, ',');
            getline(ss, fname, ',');
            getline(ss, lname, ',');
            getline(ss, address, ',');
            getline(ss, email, ',');
            userIdMap[id] = fname;
        }
        userFile.close();

        string userId = "";
        for (auto& pair : userIdMap) {
            if (pair.second == firstName) {
                userId = pair.first;
                break;
            }
        }

        if (userId.empty()) {
            cout << "User " << firstName << " not found!\n";
            return;
        }

        vector<string> productIds;
        ifstream orderFile("orders.txt");
        while (getline(orderFile, line)) {
            stringstream ss(line);
            string orderId, user, productOrdered, totalPaid;
            getline(ss, orderId, ',');
            getline(ss, user, ',');
            getline(ss, productOrdered, ',');
            getline(ss, totalPaid, ',');

            if (user == userId) {
                productIds.push_back(productOrdered);
            }
        }
        orderFile.close();

        unordered_map<string, string> productMap; 
        ifstream productFile("products.txt");
        while (getline(productFile, line)) {
            stringstream ss(line);
            string pid, pname, desc, price;
            getline(ss, pid, ',');
            getline(ss, pname, ',');
            getline(ss, desc, ',');
            getline(ss, price, ',');
            productMap[pid] = pname;
        }
        productFile.close();

        cout << "\nProducts ordered by " << firstName << ":\n";
        for (auto& pid : productIds) {
            if (productMap.find(pid) != productMap.end()) {
                cout << "- " << productMap[pid] << endl;
            }
        }
    }
};

int main() {
    DatabaseSystem db;
    db.createDummyData();
    db.fetchProductsOfUser("Linus");

    return 0;
}


