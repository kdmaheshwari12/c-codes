#include <iostream>
#include <cstring>
using namespace std;

const int MAX_TASKS = 100;

class Task{
	public:
	    char description[100];
	    bool completed;
};

class ToDoList{
	private:
	    Task tasks[MAX_TASKS];
	    int taskCount;
	
	public:
	    ToDoList():taskCount(0){}
	    void addTask(){
	        if (taskCount >= MAX_TASKS){
	            cout << "Task list is full." << endl;
	            return;
	        }
	        cout << "Enter task description: ";
	        cin.ignore();
	        cin.getline(tasks[taskCount].description, 100);
	        tasks[taskCount].completed = false;
	        taskCount++;
	        cout << "Task added successfully." << endl;
	    }
	    void markTaskAsCompleted(){
	        int taskNumber;
	        cout << "Enter the task number to mark as completed: ";
	        cin >> taskNumber;
	        if (taskNumber < 1 || taskNumber > taskCount){
	            cout << "Invalid task number." << endl;
	            return;
	        }
	        tasks[taskNumber - 1].completed = true;
	        cout << "Task marked as completed." << endl;
	    }
	    void viewTasks(){
	        if (taskCount == 0){
	            cout << "No tasks available." << endl;
	            return;
	        }
	        for (int i = 0; i < taskCount; i++){
	            cout << i + 1 << ". " << tasks[i].description;
	            if (tasks[i].completed){
	                cout << " [Completed]";
	            }
	            cout << endl;
	        }
	    }
};
int main(){
    ToDoList toDoList;
    int choice;

    while (true){
        cout << "\nTo-Do List Application\n";
        cout << "1. Add Task\n";
        cout << "2. Mark Task as Completed\n";
        cout << "3. View Tasks\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice){
            case 1:
                toDoList.addTask();
                break;
            case 2:
                toDoList.markTaskAsCompleted();
                break;
            case 3:
                toDoList.viewTasks();
                break;
            case 4:
                cout << "Exiting the application." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
