#include <iostream>
using namespace std;

class Number {
private:
    int value;

public:
    Number(int val) : value(val) {}

    Number& operator--() {
        value *= 4;
        return *this;
    }

    Number operator--(int) {
        Number temp = *this;
        value /= 4;        
        return temp;         
    }

    // Function to display the value
    void display() const {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Number num(16);

    cout << "Initial ";
    num.display();

    --num; 
    cout << "After Prefix -- ";
    num.display();

    num--;  
    cout << "After Postfix -- ";
    num.display();

    return 0;
}
