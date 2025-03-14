#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Task structure to store task details and its completion status
struct Task {
    string description;
    bool isCompleted;

    Task(string desc) : description(desc), isCompleted(false) {}
};

// Function to display the menu
void displayMenu() {
    cout << "\n================= To-Do List Manager =================\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Exit\n";
    cout << "Choose an option (1-4): ";
}

// Function to add a new task
void addTask(vector<Task>& tasks) {
    cin.ignore(); // To ignore the leftover newline from previous input
    string taskDesc;
    cout << "Enter the task description: ";
    getline(cin, taskDesc);  // Read the entire task description
    tasks.push_back(Task(taskDesc));  // Add the new task to the list
    cout << "Task added successfully!\n";
}

// Function to view all tasks with their status (Completed/Pending)
void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }
    
    cout << "\n==================== Your Tasks ====================\n";
    for (int i = 0; i < tasks.size(); i++) {
        cout << (i + 1) << ". " << tasks[i].description
             << " - " << (tasks[i].isCompleted ? "Completed" : "Pending") << endl;
    }
    cout << "=====================================================\n";
}

// Function to mark a task as completed
void markTaskCompleted(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to mark as completed.\n";
        return;
    }

    viewTasks(tasks);

    int taskIndex;
    cout << "Enter the task number to mark as completed: ";
    cin >> taskIndex;

    if (taskIndex < 1 || taskIndex > tasks.size()) {
        cout << "Invalid task number.\n";
    } else {
        tasks[taskIndex - 1].isCompleted = true;  // Mark the task as completed
        cout << "Task marked as completed!\n";
    }
}

int main() {
    vector<Task> tasks;  // Vector to store the tasks
    int choice;

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskCompleted(tasks);
                break;
            case 4:
                cout << "Exiting the To-Do List Manager. Goodbye!\n";
                return 0;  // Exit the program
            default:
                cout << "Invalid choice! Please select a valid option (1-4).\n";
        }
    }

    return 0;
}
