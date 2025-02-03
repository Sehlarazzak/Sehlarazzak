#include <iostream>
#include <string>

using namespace std;

struct Person {
    int id;
    string name;
};

void printPersons(const Person persons[], int N) 
{
    for (int i = 0; i < N; ++i) {
        cout << "ID: " << persons[i].id << ", Name: " << persons[i].name << endl;
    }
}

void sortPersons(Person persons[], int N) {
    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < N - i - 1; ++j) {
            if (persons[j].id > persons[j + 1].id || 
                (persons[j].id == persons[j + 1].id && persons[j].name[0] > persons[j + 1].name[0])) {
                
                Person temp = persons[j];
                persons[j] = persons[j + 1];
                persons[j + 1] = temp;
            }
        }
    }
}

int main() {
    int N;
    cout << "Enter the number of persons: ";
    cin >> N;

    Person* persons = new Person[N];

    cout << "Enter the details (id and name) of " << N << " persons:" << endl;
    for (int i = 0; i < N; ++i) {
        cout << "Person " << i + 1 << " - ID: ";
        cin >> persons[i].id;
        cout << "Person " << i + 1 << " - Name: ";
        cin >> persons[i].name;
    }

    cout << "\nOriginal list of persons:" << endl;
    printPersons(persons, N);
	
    sortPersons(persons, N);

    cout << "\nList sorted by ID and name:" << endl;
    printPersons(persons, N);

    delete[] persons;

    return 0;
}
