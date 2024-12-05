#include <stdio.h>
void inputMatrix(int rows, int cols, int matrix[rows][cols]) {
    printf("Enter matrix elements: ");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int rowsA, int colsA, int matrixA[rowsA][colsA],
                      int rowsB, int colsB, int matrixB[rowsB][colsB],
                      int result[rowsA][colsB]) {
    // Initialize result matrix to 0
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            result[i][j] = 0;
        }
    }
    
    // Perform matrix multiplication
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            for (int k = 0; k < colsA; ++k) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

// Function to print a matrix
void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d	", matrix[i][j]);
        }
        printf("");
    }
}

int main() {
    int rowsA, colsA, rowsB, colsB;

    // Get dimensions of matrices from the user
    printf("Enter the number of rows and columns for matrix A: ");
    scanf("%d %d", &rowsA, &colsA);

    printf("Enter the number of rows and columns for matrix B: ");
    scanf("%d %d", &rowsB, &colsB);

    // Check if multiplication is possible
    if (colsA != rowsB) {
        printf("Error: Matrix multiplication not possible.");
        return 1;
    }

    int matrixA[rowsA][colsA], matrixB[rowsB][colsB], result[rowsA][colsB];

    // Input matrices
    printf("Enter values for matrix A: ");
    inputMatrix(rowsA, colsA, matrixA);

    printf("Enter values for matrix B: ");
    inputMatrix(rowsB, colsB, matrixB);

    // Multiply matrices
    multiplyMatrices(rowsA, colsA, matrixA, rowsB, colsB, matrixB, result);

    // Print the resulting matrix
    printf("Resultant matrix: ");
    printMatrix(rowsA, colsB, result);

    return 0;
}
