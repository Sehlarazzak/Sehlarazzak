#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string description;
    bool done;
};

class TodoManager {
private:
    vector<Task> tasks;
    string filename = "tasks.txt";

    void loadTasks() {
        tasks.clear();
        ifstream file(filename);
        string line;
        while (getline(file, line)) {
            if (!line.empty()) {
                bool isDone = (line.substr(0, 4) == "[X] ");
                string desc = isDone ? line.substr(4) : line.substr(4);
                tasks.push_back({desc, isDone});
            }
        }
        file.close();
    }

    void saveTasks() {
        ofstream file(filename);
        for (const auto& task : tasks) {
            file << (task.done ? "[X] " : "[ ] ") << task.description << endl;
        }
        file.close();
    }

public:
    TodoManager() {
        loadTasks();
    }

    void addTask(const string& desc) {
        tasks.push_back({desc, false});
        saveTasks();
    }

    void viewTasks() {
        loadTasks();
        cout << "=== To-Do List ===" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i+1 << ". " << (tasks[i].done ? "[X] " : "[ ] ") << tasks[i].description << endl;
        }
    }

    void markTaskDone(int taskNumber) {
        if (taskNumber >= 1 && taskNumber <= tasks.size()) {
            tasks[taskNumber-1].done = true;
            saveTasks();
            cout << "Task marked as done." << endl;
        } else {
            cout << "Invalid task number." << endl;
        }
    }
};

int main() {
    TodoManager manager;
    int choice;

    do {
        cout << "\n1. Add Task\n2. View Tasks\n3. Mark Task as Done\n4. Exit\nEnter your choice: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1: {
                string taskDesc;
                cout << "Enter task description: ";
                getline(cin, taskDesc);
                manager.addTask(taskDesc);
                break;
            }
            case 2:
                manager.viewTasks();
                break;
            case 3: {
                int taskNum;
                manager.viewTasks();
                cout << "Enter task number to mark as done: ";
                cin >> taskNum;
                manager.markTaskDone(taskNum);
                break;
            }
            case 4:
                cout << "Exiting To-Do Manager. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
