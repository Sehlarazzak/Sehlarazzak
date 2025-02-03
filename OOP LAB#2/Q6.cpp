#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Subject {
    string name;  
};

struct Student {
    int id;  
    vector<Subject> subjects;  
};

void printStudentInfo(const vector<Student>& students) {
    for (const auto& student : students) {
        cout << "Student ID: " << student.id << endl;
        cout << "Subjects: ";
        for (const auto& subject : student.subjects) {
            cout << subject.name << " ";
        }
        cout << endl;
    }
}

int main() {
    int N;
    
    cout << "Enter the number of students: ";
    cin >> N;

    vector<Student> students(N);

    for (int i = 0; i < N; ++i) {
        cout << "\nEnter details for Student " << i + 1 << " (ID): ";
        cin >> students[i].id;

        int numSubjects;
        cout << "Enter the number of subjects for Student " << i + 1 << ": ";
        cin >> numSubjects;

        for (int j = 0; j < numSubjects; ++j) {
            Subject subject;
            cout << "Enter subject " << j + 1 << ": ";
            cin >> subject.name;
            students[i].subjects.push_back(subject);
        }
    }

    cout << "\nStudent Information:\n";
    printStudentInfo(students);

    return 0;
}

