// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Student{
     string name;
     string id;
     vector<int> scores;
     float average;
};

void average(vector<Student> students){
     string id;
     cout<<"Enter student ID: ";
     cin>>id;
     float average;
     string name;
     for(Student stud:students){
          if (stud.id == id){
               average = stud.average;
               name = stud.name;
               break;
          }
     }
     if (name.empty()){
          cout<<"There is no student with that ID in our database.";
     }else{
          cout<<name<<"'s average score: "<<fixed<<setprecision(2)<<average<<endl;
     }
}
     
void addStudent (vector<Student>& students){
     string name;
     string id;
     int num;
     
     cout<<"Student name: ";
     getline(cin >> ws, name);
     cout<<"Student ID: ";
     cin>>id;
     cout<<"How many scores? ";
     cin>>num;
     if (cin.fail()){
               cout << "Letters are not allowed.\n";
              cin.clear();
              cin.ignore(1000, '\n');
              return;
     }else if (num<=0){
          cout<<"At least one score must be entered.";
          return;
     }
     
     vector<int> scores;
     int score;
     for (int i{1}; i<=num;i++){
          cout<<"Enter score "<<i<<": ";
          cin>>score;
          if ((score < 0) || (score > 100)){
               cout<<"The scores must be between 0 and 100";
               return;
          }else if (cin.fail()){
               cout << "Letters are not allowed.\n";
              cin.clear();
              cin.ignore(1000, '\n');
              return;
          }
          scores.push_back(score);
     }
     int sum{0};
     for (int score: scores){
          sum+=score;
     }
     float average{static_cast<float>(sum)/static_cast<float>(scores.size())};
     students.push_back({name, id, scores, average});
     cout<<"Student '"<<name<<"' added successfully"<<endl;
}

void viewStudents(vector<Student>& students){
     if (students.empty()){
          cout<<"No students have been entered yet.";
          return;
     }
     cout<<left;
     cout<<setw(15)<<"Name"
     <<setw(10)<<"ID"
     <<setw(20)<<"Scores"
     <<setw(10)<<"Average"<<endl;
     
     for (Student stud: students){
          string scores;
          for (int score: stud.scores){
               scores += (to_string(score) + ", ");
          }
          cout<<setw(15)<<stud.name
          <<setw(10)<<stud.id
          <<setw(20)<<scores
          <<setw(10)<<fixed<<setprecision(2)<<stud.average<<endl;
     }
}
void quit(){
     cout<<"Goodbye!"<<endl;
}

int main(){
     cout<<string(40,'-')<<"\nSTUDENT RECORD SYSTEM MENU\n"<<string(40,'-')<<
     "\n1. Add student\n2. Display all students\n3. Calculate average score\n4. Quit"<<endl;
     vector<Student> students;
     while (true){
          int option;
          cout<<"\nEnter your choice (1-4): ";
          cin>>option;
          if (option == 1){
               addStudent(students);
          }else if (option == 2){
               viewStudents(students);
          }else if (option == 3){
               average(students);
          }else if (option == 4){
               quit();
               break;
          }else if (cin.fail()){
               cout << "Letters are not allowed.\n";
              cin.clear();
              cin.ignore(1000, '\n');
              continue;
          }else{
               cout<<"Error: Invalid input.";
          }
          
     }
     
     return 0;
}