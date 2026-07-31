// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 7
// =============================================================================
//
// TASK: Console-Based To-Do List Application
//
// Build a simple to-do list program that runs entirely in the console and
// allows the user to manage their tasks interactively using a menu.
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Task
//      - Prompt the user to type a task description.
//      - Add it to the list and confirm it was added.
//
//   2. View All Tasks
//      - Display all tasks currently in the list, numbered from 1.
//      - If the list is empty, print a friendly message saying so.
//
//   3. Delete a Task
//      - Show the list of tasks with their numbers.
//      - Ask the user which task number they want to remove.
//      - Remove the task and confirm the deletion.
//      - If the task number is invalid, print an error message.
//
//   4. Quit
//      - End the program with a farewell message.
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        TO-DO LIST MENU
//   ============================
//   1. Add task
//   2. View tasks
//   3. Delete task
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Enter task: Buy groceries
//   Task added: "Buy groceries"
//
//   Enter your choice (1-4): 2
//   Your Tasks:
//   1. Buy groceries
//   2. Study for exams
//
//   Enter your choice (1-4): 3
//   Enter task number to delete: 1
//   Task "Buy groceries" has been removed.
//
//   Enter your choice (1-4): 4
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Store tasks in a vector<string> (a dynamic list of text).
// - Use a loop to keep the menu running until the user chooses to quit.
// - Each feature MUST be implemented in its own function (see scaffold below).
// - Handle invalid menu choices gracefully (print an error, do not crash).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> addTask(vector<string> todolist){
     string task;
     cout<<"Enter task: ";
     getline(cin>>ws,task);
     todolist.push_back(task);
     cout<<"Task added: '"<<task<<"'"<<endl;
     return todolist;
}

string viewTasks(vector<string> todolist){
     if(todolist.empty()){
          cout<<"There are no tasks entered yet.";
          return "";
     }
     string todoStr{"Your tasks:\n"};
     for (int i{0}; i<todolist.size(); i++){
          todoStr += (to_string(i+1) + ". " + todolist[i] + '\n');
     }
     return todoStr;
}

vector<string> delTask(vector<string> todolist){
     if(todolist.empty()){
          cout<<"There are no tasks entered yet.";
          return todolist;
     }
     int taskNo;
     cout<<"Enter task number to delete: ";
     cin>>taskNo;
     if (cin.fail() || taskNo<=0 || taskNo>todolist.size()) {
          cout<<"Error: Invalid input.";
          cin.clear();
          cin.ignore(1000, '\n');
          return todolist;
     }
     cout<<"Task '"<<todolist[taskNo-1]<<"' has been removed.";
     todolist.erase(todolist.begin()+ taskNo-1);
      return todolist;
}

void quit(){
     cout<<"Goodbye!";
}

int main(){
     vector<string> todolist;
     cout<<string(30,'-')<<"\nTO-DO LIST MENU\n"<<string(30,'-')<<
     "\n1. Add task\n2. View tasks\n3. Delete task\n4. Quit"<<endl;
     while (true){
          int option;
          cout<<"\nEnter your choice (1-4): ";
          cin>>option;
          if (cin.fail()) {
              cout << "Letters are not allowed.\n";
              cin.clear();
              cin.ignore(1000, '\n');
              continue;
          }
          int size = todolist.size();
          switch(option){
               case 1:
                    todolist = addTask(todolist);
                    break;
               case 2:
                    cout<<viewTasks(todolist);
                    break;
               case 3:
                    todolist = delTask(todolist);
                    if (todolist.size() == size){
                         continue;
                    }
                    break;
               case 4:
                    quit();
                    return 0;
               default:
                    cout<<"Your input is invalid."<<endl;
                    break;
          }
     }
     return 0;
}