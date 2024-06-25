#include <iostream>
#include <vector>
#include <string>

class Task {
public:
    std::string description;
    bool completed;

    Task(std::string desc) : description(desc), completed(false) {}
};

class ToDoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& taskDescription) {
        tasks.push_back(Task(taskDescription));
        std::cout << "Task added successfully.\n";
    }

    void viewTasks() {
        if (tasks.empty()) {
            std::cout << "No tasks in the list.\n";
            return;
        }

        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". [" << (tasks[i].completed ? "X" : " ") << "] " << tasks[i].description << "\n";
        }
    }

    void markTaskCompleted(size_t taskIndex) {
        if (taskIndex < 1 || taskIndex > tasks.size()) {
            std::cout << "Invalid task number.\n";
            return;
        }

        tasks[taskIndex - 1].completed = true;
        std::cout << "Task marked as completed.\n";
    }

    void removeTask(size_t taskIndex) {
        if (taskIndex < 1 || taskIndex > tasks.size()) {
            std::cout << "Invalid task number.\n";
            return;
        }

        tasks.erase(tasks.begin() + taskIndex - 1);
        std::cout << "Task removed successfully.\n";
    }
};

void displayMenu() {
    std::cout << "\nTo-Do List Manager\n";
    std::cout << "1. Add Task\n";
    std::cout << "2. View Tasks\n";
    std::cout << "3. Mark Task as Completed\n";
    std::cout << "4. Remove Task\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    ToDoList todoList;
    int choice;
    std::string taskDescription;
    size_t taskIndex;

    while (true) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cin.ignore(); // to clear the newline character from the buffer
                std::cout << "Enter the task description: ";
                std::getline(std::cin, taskDescription);
                todoList.addTask(taskDescription);
                break;
            case 2:
                todoList.viewTasks();
                break;
            case 3:
                std::cout << "Enter the task number to mark as completed: ";
                std::cin >> taskIndex;
                todoList.markTaskCompleted(taskIndex);
                break;
            case 4:
                std::cout << "Enter the task number to remove: ";
                std::cin >> taskIndex;
                todoList.removeTask(taskIndex);
                break;
            case 5:
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
