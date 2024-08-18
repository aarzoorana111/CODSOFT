#include <iostream>
#include <vector>
#include <string>

// todo program

struct Task {
    std::string description;
    bool completed;
};

void addTask(std::vector<Task>& tasks) {
    Task newTask;
    std::cout << "Enter task description: ";
    std::getline(std::cin, newTask.description);
    newTask.completed = false;
    tasks.push_back(newTask);
}

void viewTasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks available.\n";
        return;
    }
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". " << tasks[i].description;
        if (tasks[i].completed) {
            std::cout << " (Completed)";
        }
        std::cout << std::endl;
    }
}

void deleteTask(std::vector<Task>& tasks) {
    viewTasks(tasks);
    int taskNumber;
    std::cout << "Enter the number of the task to delete: ";
    std::cin >> taskNumber;
    std::cin.ignore();  // Clear newline character left in the buffer

    if (taskNumber < 1 || taskNumber > static_cast<int>(tasks.size())) {
        std::cout << "Invalid task number.\n";
        return;
    }
    tasks.erase(tasks.begin() + taskNumber - 1);
}

void markTaskAsCompleted(std::vector<Task>& tasks) {
    viewTasks(tasks);
    int taskNumber;
    std::cout << "Enter the number of the task to mark as completed: ";
    std::cin >> taskNumber;
    std::cin.ignore();  // Clear newline character left in the buffer

    if (taskNumber < 1 || taskNumber > static_cast<int>(tasks.size())) {
        std::cout << "Invalid task number.\n";
        return;
    }
    tasks[taskNumber - 1].completed = true;
}

int main() {
    std::vector<Task> tasks;
    int choice;

    do {
        std::cout << "\nTo-Do List Menu:\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Delete Task\n";
        std::cout << "4. Mark Task as Completed\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice (1-5): ";
        std::cin >> choice;
        std::cin.ignore();  // Clear newline character left in the buffer

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                deleteTask(tasks);
                break;
            case 4:
                markTaskAsCompleted(tasks);
                break;
            case 5:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }
    } while (choice != 5);

    return 0;
}
