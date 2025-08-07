#include <stdio.h>

#define MAX 10 // Define a maximum size for matrices

// Global or static variables to manage indices and sum across recursive calls
static int sum = 0;
static int i = 0, j = 0, k = 0;

// Function to recursively multiply two matrices
void multiplyMatrixRecursive(int A[][MAX], int B[][MAX], int C[][MAX], int row1, int col1, int row2, int col2) 
{
    // Base case: If we have processed all rows of the first matrix
    if (i >= row1) 
    {
        return;
    }

    // Process columns of the second matrix
    if (j < col2) 
    {
        // Perform the inner product summation
        if (k < col1) 
        {
            sum += A[i][k] * B[k][j];
            k++;
            multiplyMatrixRecursive(A, B, C, row1, col1, row2, col2); // Recursive call for inner product
        }
        C[i][j] = sum; // Store the calculated element in the result matrix
        sum = 0; // Reset sum for the next element
        k = 0; // Reset k for the next column
        j++; // Move to the next column in the result matrix
        multiplyMatrixRecursive(A, B, C, row1, col1, row2, col2); // Recursive call for the next column
    }

    // Move to the next row in the result matrix
    j = 0; // Reset j for the next row
    i++; // Move to the next row
    multiplyMatrixRecursive(A, B, C, row1, col1, row2, col2); // Recursive call for the next row
}

// Wrapper function to initiate the recursive multiplication
void multiplyMatrices(int A[][MAX], int B[][MAX], int C[][MAX], int row1, int col1, int row2, int col2) 
{
    if (col1 != row2) {
        printf("Matrix multiplication is not possible. Number of columns in the first matrix must equal number of rows in the second matrix.\n");
        return;
    }

    // Initialize the result matrix to zeros (important for sum accumulation)
    for (int r = 0; r < row1; r++) 
    {
        for (int c = 0; c < col2; c++) 
        {
            C[r][c] = 0;
        }
    }

    // Start the recursive multiplication
    multiplyMatrixRecursive(A, B, C, row1, col1, row2, col2);
}

int main() {
    int A[MAX][MAX] = {{1, 2}, {3, 4}};
    int B[MAX][MAX] = {{5, 6}, {7, 8}};
    int C[MAX][MAX];

    int row1 = 2, col1 = 2;
    int row2 = 2, col2 = 2;

    multiplyMatrices(A, B, C, row1, col1, row2, col2);

    // Print the result matrix
    printf("Resultant Matrix:\n");
    for (int r = 0; r < row1; r++) {
        for (int c = 0; c < col2; c++) {
            printf("%d ", C[r][c]);
        }
        printf("\n");
    }

    return 0;
}