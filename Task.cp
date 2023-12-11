#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

class Todolist {
private:
    vector<Task> tasks;

public:
    void addTask(const string& description) {
        Task newTask{description, false};
        tasks.push_back(newTask);
        cout << "Task Added: " << description << endl;
    }

    void markTaskAsComplete(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].completed = true;
            cout << "Task Completed: " << tasks[index].description << endl;
        } else {
            cout << "Invalid task index" << endl;
        }
    }

    void displayTasks() {
        cout << "Task List:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << "[" << i + 1 << "]";
            if (tasks[i].completed) {
                cout << "[X] ";
            } else {
                cout << "[ ] ";
            }
            cout << tasks[i].description << endl;
        }
    }
};

int main() {
    Todolist todolist;
    string description;  // Move the declaration outside the switch block

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add Task\n";
        cout << "2. Mark Task as Complete\n";
        cout << "3. Display Tasks\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Task Description: ";
                cin.ignore();
                getline(cin, description);
                todolist.addTask(description);
                break;

            case 2:
                cout << "Enter the index of the task to mark as complete: ";
                int index;
                cin >> index;
                todolist.markTaskAsComplete(index - 1);
                break;

            case 3:
                todolist.displayTasks();
                break;

            case 4:
                cout << "Goodbye!" << endl;
                return 0;

            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }

    return 0;
}