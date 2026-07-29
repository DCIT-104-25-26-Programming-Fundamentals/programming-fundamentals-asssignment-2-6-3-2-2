// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 2
// =============================================================================
//
// TASK: Student Grade System
//
// Write a C++ program that reads a student's score and outputs the
// corresponding letter grade based on the scale below.
//
// Grading Scale:
//   Score 80 – 100  →  Grade A
//   Score 70 – 79   →  Grade B
//   Score 60 – 69   →  Grade C
//   Score 50 – 59   →  Grade D
//   Score below 50  →  Grade F
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLES
// -----------------------------------------------------------------------------
//
//   Enter student score (0-100): 85
//   Grade: A
//
//   Enter student score (0-100): 73
//   Grade: B
//
//   Enter student score (0-100): 45
//   Grade: F
//
//   Enter student score (0-100): 110
//   Error: Score must be between 0 and 100.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST use functions (see scaffold below).
// - Validate the score inside getGrade(). If it is out of range, return '\0'
//   (null character) and let main() print the error message.
// - Use if / else if / else to determine the grade.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <string>
using namespace std;

char getGrade(int score){
    char grade;
    if (score>=80 && score<=100){
        grade = 'A';
    }else if (score>=70 && score<=79){
        grade = 'B';
    }else if (score>=60 && score<=69){
        grade = 'C';
    }else if (score>=50 && score<=59){
        grade = 'D';
    }else if (score>=0 && score<=49){
        grade = 'F';
    }else{
        grade = '\0';
    }
    return grade;
}

int main(){
    int score;
    cout<<"Enter student score (0-100): ";
    cin>>score;
    if (getGrade(score) == '\0'){
        cout<<"Error: Score must be between 0 and 100."<<endl;
    }else{
        cout<<"Grade: "<<getGrade(score)<<endl;
    }
    return 0;
}