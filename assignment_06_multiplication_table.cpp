// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 6
// =============================================================================
//
// TASK: Multiplication Table Generator
//
// Write a C++ program that generates multiplication tables using loops
// and functions.
//
// -----------------------------------------------------------------------------
// PART A — Single Table
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Print the multiplication table for that number from 1 to 12.
//
// Expected output (if user enters 5):
//
//   Multiplication Table for 5:
//   5  x  1  =  5
//   5  x  2  =  10
//   5  x  3  =  15
//   ...
//   5  x  12 =  60
//
// -----------------------------------------------------------------------------
// PART B — Bonus: Tables from 1 to N
// -----------------------------------------------------------------------------
// - Ask the user to enter a number N.
// - Print the full multiplication table for every number from 1 to N.
// - Add a separator line (e.g. "---") between each table.
//
// Expected output (if user enters 3):
//
//   Multiplication Table for 1:
//   1  x  1  =  1
//   ...
//   1  x  12 =  12
//   ---------------------------
//   Multiplication Table for 2:
//   2  x  1  =  2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - N must be a positive integer. If the user enters an invalid value,
//   print an error message and stop.
// - Each part must be in its own function (see scaffold below).
// - Complete Part A before attempting Part B.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <string>
using namespace std;

string single_mult_table(int num){
     if (num<=0){
          return "";
     }
     string multTable{"Multiplication table for "+to_string(num)+":\n"};
     int product;
     for (int i{1}; i<=12 ; i++){
          product = i * num;
          multTable += (to_string(num) + " × " + to_string(i) + " = " + to_string(product) + "\n");
     }
     return multTable;
}

string multiple_mult_table(int num){
     if (num<=0){
          return "";
     }
     string multTable;
     int product;
     for (int i{1}; i <= num;i++){
          multTable += (string(30,'-')+("\nMultiplication table for ")+to_string(i)+(":\n")+string(30,'-')+("\n"));
          for (int j{1}; j <= 12; j++){
               product = i * j;
               multTable += (to_string(i) + " × " + to_string(j) + " = " + to_string(product) + "\n");
          }
     }
     return multTable;
}
               

int main(){
     int number;
     cout<<"Enter a number for the multiplication table: ";
     cin>>number;
     if (single_mult_table(number).empty()){
          cout<<"Error: A positive integer must be entered."<<endl;
     }
     cout<<single_mult_table(number)<<endl;
     
     cout<<"Enter a number: ";
     cin>>number;
     if (multiple_mult_table(number).empty()){
          cout<<"Error: A positive integer must be entered."<<endl;
     }
     cout<<multiple_mult_table(number)<<endl;
}