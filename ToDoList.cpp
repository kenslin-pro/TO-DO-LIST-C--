#include <iostream>
#include <vector>
#include <algorithm>

class ToDoList
{
private:
    std::vector<std::string> tasks;

public:
    void addTask(const std::string &task)
    {
        tasks.push_back(task);
        std::cout << "Task added: " << task << std::endl;
    }

    void removeTask(const std::string &task)
    {
        auto it = std::find(tasks.begin(), tasks.end(), task);
        if (it != tasks.end())
        {
            tasks.erase(it);
            std::cout << "Task removed: " << task << std::endl;
        }
        else
        {
            std::cout << "Task not found: " << task << std::endl;
        }
    }

    void viewTasks() const
    {
        if (tasks.empty())
        {
            std::cout << "No tasks available." << std::endl;
        }
        else
        {
            std::cout << "Tasks:" << std::endl;
            for (const auto &task : tasks)
            {
                std::cout << "- " << task << std::endl;
            }
        }
    }
};

int main()
{
    ToDoList toDoList;

    while (true)
    {
        std::cout << "\n===== To-Do List Manager =====" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. Remove Task" << std::endl;
        std::cout << "3. View Tasks" << std::endl;
        std::cout << "4. Quit" << std::endl;

        int choice;
        std::cout << "Enter your choice (1-4): ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            std::string task;
            std::cout << "Enter the task: ";
            std::cin.ignore(); // Ignore newline from previous input
            std::getline(std::cin, task);
            toDoList.addTask(task);
            break;
        }
        case 2:
        {
            std::string task;
            std::cout << "Enter the task to remove: ";
            std::cin.ignore(); // Ignore newline from previous input
            std::getline(std::cin, task);
            toDoList.removeTask(task);
            break;
        }
        case 3:
            toDoList.viewTasks();
            break;
        case 4:
            std::cout << "Exiting the program. Goodbye!" << std::endl;
            return 0;
        default:
            std::cout << "Invalid choice. Please enter a number between 1 and 4." << std::endl;
        }
    }

    return 0;
}
