// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void add(int num1,int num2){
     int sum{num1 + num2};
     cout<<"Result: "<<num1<<" + "<<num2<<" = "<<sum;
}

void subtract(int num1,int num2){
     int diff{num1 - num2};
     cout<<"Result: "<<num1<<" - "<<num2<<" = "<<diff;
}

void multiply(int num1,int num2){
     int product{num1 * num2};
     cout<<"Result: "<<num1<<" * "<<num2<<" = "<<product;
}

void divide(int num1,int num2){
     if (num2 == 0){
          cout<<"Error: Cannot divide by zero.";
          return;
     }
     float div{static_cast<float>(num1) / static_cast<float>(num2)};
     cout<<"Result: "<<num1<<" / "<<num2<<" = "<<fixed<<setprecision(2)<<div;
}

void modulo(int num1,int num2){
     if (num2 == 0){
          cout<<"Error: Cannot modulo by zero.";
          return;
     }
     int mod{num1 % num2};
     cout<<"Result: "<<num1<<" % "<<num2<<" = "<<mod;
}

void exponent(int num1,int num2){
     double result{pow(num1, num2)};
     cout<<"Result: "<<num1<<" ^ "<<num2<<" = "<<result;
}
void quit(){
     cout<<"Goodbye!";
}

int main(){
     cout<<string(40,'-')<<"\nSIMPLE CALCULATOR\n"<<string(40,'-')<<
     "\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Modulus\n6. Exponentiation\n7. Quit"<<endl;
     
     int operation;
     int num1;
     int num2;
     while (true){
          cout<<"\n\nSelect an operation (1-7): ";
          cin>>operation;
          if (cin.fail()){
               cout<<"Error: Invalid menu choice.";
               cin.clear();
               cin.ignore(1000,'\n');
               continue;
          }else if(operation == 7){
               quit();
               return 0;
          }else if(operation<1 || operation>7){
               cout<<"Error: Invalid menu choice.";
               cin.clear();
               cin.ignore(1000,'\n');
               continue;
          }
          
          cout<<"Enter the first number: ";
          cin>>num1;
          if (cin.fail()){
               cout<<"Error: Invalid input.";
               cin.clear();
               cin.ignore(1000,'\n');
               continue;
          }
          cout<<"Enter the second number: ";
          cin>>num2;
          if (cin.fail()){
               cout<<"Error: Invalid input.";
               cin.clear();
               cin.ignore(1000,'\n');
               continue;
          }
          
          switch(operation){
               case 1:
                    add(num1,num2);
                    break;
               case 2:
                    subtract(num1, num2);
                    break;
               case 3:
                    multiply(num1, num2);
                    break;
               case 4:
                    divide(num1, num2);
                    break;
               case 5:
                    modulo(num1, num2);
                    break;
               case 6:
                    exponent(num1, num2);
                    break;
               default:
                    cout<<"Error: Invalid input.";
                    break;
          }
     }
}
     