// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
using namespace std;

int sum(vector<int> myVector){
    int sum{0};
    for (int i{0};i<myVector.size();i++){
        sum += myVector[i];
    }
    return sum;
}
    
float average(vector<int> myVector){
    float total{static_cast<float>(sum(myVector))};
    float arraySize{static_cast<float>(myVector.size())};
    float average{total/arraySize};
    
    return average;
}
    
int maximum(vector<int> myVector){
    int maxVal{myVector[0]};
    for (int i{0};i<myVector.size();i++){
        if(maxVal < myVector[i]){
            maxVal = myVector[i];
        }else{
            continue;
        }
    }
    return maxVal;
}

int minimum(vector<int> myVector){
    int minVal{myVector[0]};
    for (int i{0};i<myVector.size();i++){
        if(minVal > myVector[i]){
            minVal = myVector[i];
        }else{
            continue;
        }
    }
    return minVal;
}

int main(){
    int listSize;
    cout<<"How many numbers? ";
    cin>>listSize;
    if (listSize <= 0){
        cout<<"Error: A positive integer must be entered."<<endl;
        return 0;
    }
    vector<int> myVector(listSize);
    for (int i{1}; i <= (listSize);i++){
        cout<<"Enter number "<<i<<": ";
        cin>>myVector[i-1];
    }
     cout<<"\nResults:"
     <<"\nSum: "<<sum(myVector)
     <<"\nAverage: "<<average(myVector)
     <<"\nMaximum: "<<maximum(myVector)
     <<"\nMinimum: "<<minimum(myVector)
     <<endl;
}