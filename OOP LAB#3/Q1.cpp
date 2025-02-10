#include<iostream>

using namespace std;

class User {
public:
    int Age;
    string Name;
};

int main() 
{
    User user;
   
    user.Name = "Teo";
    user.Age = 24;
 
    cout << "My name is " << user.Name << " and I am " << user.Age << " years old." << endl;
    
    return 0;
}
