
#include <iostream>
using namespace std;

void addTask(string tasks[], bool completed[], int &count) {
    if (count < 100) {
        cout << "Enter task name: ";
        cin >> tasks[count];

        completed[count] = false;
        count++;

        cout << "Task added successfully!" << endl;
    } else {
        cout << "Task limit reached!" << endl;
    }
}

void viewTasks(string tasks[], bool completed[], int count) {
    if (count == 0) {
        cout << "No tasks available!" << endl;
        return;
    }

    cout << "\n----- YOUR TASKS -----" << endl;

    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". " << tasks[i];

        if (completed[i]) {
            cout << " - Completed";
        } else {
            cout << " - Pending";
        }

        cout << endl;
    }
}

void markCompleted(bool completed[], int count) {
    if (count == 0) {
        cout << "No tasks available!" << endl;
        return;
    }

    int taskNumber;
    cout << "Enter task number to mark completed: ";
    cin >> taskNumber;

    if (taskNumber >= 1 && taskNumber <= count) {
        completed[taskNumber - 1] = true;
        cout << "Task marked as completed!" << endl;
    } else {
        cout << "Invalid task number!" << endl;
    }
}

void deleteTask(string tasks[], bool completed[], int &count) {
    if (count == 0) {
        cout << "No tasks available!" << endl;
        return;
    }

    int taskNumber;
    cout << "Enter task number to delete: ";
    cin >> taskNumber;

    if (taskNumber >= 1 && taskNumber <= count) {
        int position = taskNumber - 1;

        for (int i = position; i < count - 1; i++) {
            tasks[i] = tasks[i + 1];
            completed[i] = completed[i + 1];
        }

        count--;
        cout << "Task deleted successfully!" << endl;
    } else {
        cout << "Invalid task number!" << endl;
    }
}

int main() {
    int choice;
    int count = 0;

    string tasks[100];
    bool completed[100];

    do {
        cout << "\n===== TO-DO LIST MANAGER =====" << endl;
        cout << "1. Add New Task" << endl;
        cout << "2. View All Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Delete Task" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks, completed, count);
                break;

            case 2:
                viewTasks(tasks, completed, count);
                break;

            case 3:
                markCompleted(completed, count);
                break;

            case 4:
                deleteTask(tasks, completed, count);
                break;

            case 5:
                cout << "Thank you for using To-Do List Manager!" << endl;
                break;

            default:
                cout << "Invalid Choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}
