#include<iostream>

using namespace std;

class Date 
{
public:
    int month;
    int day;
    int year;

    Date(int m, int d, int y) : month(m), day(d), year(y) {}

    void displayDate() {
        cout << month << "/" << day << "/" << year << endl;
    }
};

int main() 
{
    Date date(10, 3, 2024);

    cout << "The date is: ";
    date.displayDate();
    
    return 0;
}
