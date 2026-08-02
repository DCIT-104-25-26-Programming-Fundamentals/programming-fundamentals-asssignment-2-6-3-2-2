// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void writeMatrix(int matrix[10][10],int rows, int cols){
     for (int i{0};i<rows;i++){
          for (int j{0}; j<cols; j++){
               int element;
               cout<<"Enter element ["<<i<<"]["<<j<<"]: ";
               cin>>element;
               matrix[i][j] = element;
          }
     }
}

void readMatrix(int matrix[10][10],int rows, int cols){
     for (int i{0};i<rows;i++){
          for (int j{0}; j<cols; j++){
               cout<<right;
               cout<<setw(5)<<matrix[i][j];
          }
          cout<<endl;
     }
}

void transpose(int matrix[10][10], int rows, int cols){
     writeMatrix(matrix,rows,cols);
     int final_matrix[10][10];
     for (int i{0};i<rows;i++){
          for (int j{0}; j<cols; j++){
               final_matrix[j][i] = matrix[i][j];
          }
     }
     cout<<"Original matrix\n";
     readMatrix(matrix,rows, cols);
     cout<<"Transposed matrix\n";
     readMatrix(final_matrix, cols, rows);

     
}
void addMatrices(int matrixA[10][10], int rowsA, int colsA, int matrixB[10][10], int rowsB, int colsB){
     if(rowsA != rowsB && colsA != colsB){
          cout<<"These matrices cannot be added due to difference in row and column numbers.";
          return;
     }else if (rowsA != rowsB){
          cout<<"These matrices cannot be added due to difference in row numbers.";
          return;
     }else if (colsA != colsB){
          cout<<"These matrices cannot be added due to difference in column numbers.";
          return;
     }
     writeMatrix(matrixA,rowsA,colsA);
     cout<<"Matrix A\n";
     readMatrix(matrixA,rowsA,colsA);
     writeMatrix(matrixB,rowsB,colsB);
     cout<<"Matrix B\n";
     readMatrix(matrixB,rowsB,colsB);
     int final_matrix[10][10];
     for (int i{0};i<rowsA;i++){
          for (int j{0}; j<colsA; j++){
               final_matrix[i][j] = matrixA[i][j] + matrixB[i][j];
          }
     }
     
     cout<<"Sum\n";
     readMatrix(final_matrix,rowsA,colsA);
}

void multiplyMatrices(int matrixA[10][10], int rowsA, int colsA, int matrixB[10][10], int rowsB, int colsB){
     if (colsA != rowsB){
          cout<<"These matrices cannot be multiplied because the number of columns of the first is not the same as the number of rows of the second.";
          return;
     }
     writeMatrix(matrixA,rowsA,colsA);
     cout<<"Matrix A\n";
     readMatrix(matrixA,rowsA,colsA);
     writeMatrix(matrixB,rowsB,colsB);
     cout<<"Matrix B\n";
     readMatrix(matrixB,rowsB,colsB);
     
     int final_matrix[10][10]{0};
     for (int j{0}; j<rowsA;j++){
          for (int k{0};k<colsB;k++){
               for (int i{0}; i<colsA;i++){
                    final_matrix[j][k] += matrixA[j][i] * matrixB[i][k];
               }
          }
     }
     
     cout<<"Product\n";
     readMatrix(final_matrix,rowsA,colsB);

}

int main(){
     int matrix[10][10];
     int rowSize;
     int colSize;
     cout<<"Enter number of rows: ";
     cin>>rowSize;
     cout<<"Enter number of columns: ";
     cin>>colSize;

     transpose(matrix,rowSize,colSize);
     
     int matrixA[10][10];
     int rowSizeA;
     int colSizeA;
     cout<<"Enter number of rows: ";
     cin>>rowSizeA;
     cout<<"Enter number of columns: ";
     cin>>colSizeA;
     int matrixB[10][10];
     int rowSizeB;
     int colSizeB;
     cout<<"Enter number of rows: ";
     cin>>rowSizeB;
     cout<<"Enter number of columns: ";
     cin>>colSizeB;
     addMatrices(matrixA,rowSizeA,colSizeA,matrixB,rowSizeB,colSizeB);
     
     cout<<"Enter number of rows: ";
     cin>>rowSizeA;
     cout<<"Enter number of columns: ";
     cin>>colSizeA;
     cout<<"Enter number of rows: ";
     cin>>rowSizeB;
     cout<<"Enter number of columns: ";
     cin>>colSizeB;
     multiplyMatrices(matrixA,rowSizeA,colSizeA,matrixB,rowSizeB,colSizeB);

     return 0;
}