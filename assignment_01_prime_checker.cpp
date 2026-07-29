// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 1
// =============================================================================
//
// TASK: Prime Number Checker
//
// Write a C++ program that checks whether a given number is prime.
//
// A prime number is a whole number greater than 1 that has no divisors
// other than 1 and itself (e.g., 2, 3, 5, 7, 11, 13 ...).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLES
// -----------------------------------------------------------------------------
//
//   Enter a number: 7
//   7 is a prime number.
//
//   Enter a number: 10
//   10 is NOT a prime number.
//
//   Enter a number: 1
//   1 is NOT a prime number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement the logic inside a function (see scaffold below).
// - Numbers less than 2 are NOT prime — handle this inside the function.
// - The main() function must call isPrime() and print the result.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string isPrime (int number){
    string result;
    bool test{true};
    if (number <=1){
        test = false;
    }else{
        for (int i{2}; i <= sqrt(number); ++i){
            if (number % i == 0){
                test = false;
                break;
            }
        }
    }
    if (test == true){
        result = to_string(number)+" is a prime number.";
    }else{
        result = to_string(number)+" is NOT a prime number.";
    }
    return result;
}
int main(){
    int myNumber;
    cout << "Enter a number: ";
    cin >> myNumber;
    string result{isPrime(myNumber)};
    cout << result << endl;
    
    return 0;
}