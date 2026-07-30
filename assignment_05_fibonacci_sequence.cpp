// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
//
// TASK: Fibonacci Sequence Generator
//
// The Fibonacci sequence is a series of numbers where each number is the sum
// of the two numbers before it:
//
//   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
//
// Write a C++ program with TWO parts, each implemented as a function.
//
// -----------------------------------------------------------------------------
// PART A — Print the First N Terms
// -----------------------------------------------------------------------------
// - Ask the user how many terms (N) to display.
// - Print the first N numbers of the Fibonacci sequence on one line.
//
// Example:
//   How many terms? 7
//   Fibonacci sequence: 0 1 1 2 3 5 8
//
// -----------------------------------------------------------------------------
// PART B — Check if a Number Belongs to the Sequence
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Determine whether that number is a Fibonacci number.
// - Print an appropriate message.
//
// Example:
//   Enter a number to check: 13
//   13 is a Fibonacci number.
//
//   Enter a number to check: 20
//   20 is NOT a Fibonacci number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use a loop (not recursion) to generate the sequence in both parts.
// - N must be a positive integer. If it is not, print an error message.
// - Each part must be implemented in its own function (see scaffold below).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> Fibonacci(int num){
     vector<int> sequence{0,1};
     if (num<=0){
          return {};
     }else if (num == 1) {
          return vector<int> {0};
     }else{
          for (int i{2}; i<num; i++){
               sequence.push_back(sequence[i-1]+sequence[i-2]);
          }
     }
     return sequence;
}

bool isInFibonacci(int num){
     vector<int> sequence{0,1};
     bool test{true};
     if (num<0){
          test = false;
     }else{
          for (int i{2};sequence[sequence.size()-1] < num;i++){
               sequence.push_back(sequence[i-1]+sequence[i-2]);
          }
     }
     if (sequence.back() != num ){
          test= false;
     }
     return test; 
}

int main(){
     int seqSize;
     cout<<"How many terms? ";
     cin>>seqSize;
     vector<int> sequence{Fibonacci(seqSize)};
     if(sequence.empty()){
          cout<<"Error: The number of terms must be a positive integer.";
          return 0;
     }
     string seqStr{""};
     for (int item: sequence){
          seqStr+=(to_string(item)+" ");
     }
     cout<<"Fibonacci sequence: "<<seqStr<<endl;
     
     int num;
     cout<<"Enter a number to check: ";
     cin>>num;
     if (isInFibonacci(num)){
          cout<<num<<" is a Fibonacci number."<<endl;
     }else{
          cout<<num<<" is NOT a Fibonacci number."<<endl;
     }
}