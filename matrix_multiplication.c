//1. Implementation of Matrix Multiplication using Dynamic Memory Allocation. Ensure  to allocate the memory using appropriate functions and access the array using  pointers.



#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j, k;
    int row1, col1, row2, col2;

    // asking for the number of rows and columns of the first matrix
    printf("Enter rows and columns for the first matrix: ");
    scanf("%d %d", &row1, &col1);

    // asking for the number of rows and columns of the second matrix
    printf("Enter rows and columns for the second matrix: ");
    scanf("%d %d", &row2, &col2);

    // checking if the matrices can be multiplied
    if (col1 != row2) {
        printf("Matrix multiplication not possible because the number of columns in the first matrix "
               "must equal the number of rows in the second matrix.\n");
        return 1;
    }

    // allocating memory dynamically for the first matrix
    int **matrix1 = (int **)malloc(row1 * sizeof(int *));
    for (i = 0; i < row1; i++)
        matrix1[i] = (int *)malloc(col1 * sizeof(int));

    // Allocating memory dynamically for the second matrix
    int **matrix2 = (int **)malloc(row2 * sizeof(int *));
    for (i = 0; i < row2; i++)
        matrix2[i] = (int *)malloc(col2 * sizeof(int));

    // allocating memory dynamically for the result matrix
    int **result = (int **)malloc(row1 * sizeof(int *));
    for (i = 0; i < row1; i++)
        result[i] = (int *)malloc(col2 * sizeof(int));

    // taking input elements for the first matrix
    printf("Now, let's fill in the first matrix. Please enter the elements:\n");
    for (i = 0; i < row1; i++) {
        for (j = 0; j < col1; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1); // prompting with element position
            scanf("%d", (*(matrix1 + i) + j));
        }
    }

    // taking input elements for the second matrix
    printf("Next, we'll fill in the second matrix. Please enter the elements:\n");
    for (i = 0; i < row2; i++) {
        for (j = 0; j < col2; j++) {
            printf("Element [%d][%d]: ", i + 1, j + 1); // prompting with element position
            scanf("%d", (*(matrix2 + i) + j));
        }
    }

    // initializing the result matrix to zero
    for (i = 0; i < row1; i++)
        for (j = 0; j < col2; j++)
            *(*(result + i) + j) = 0;

    // matrix multiplication
    for (i = 0; i < row1; i++) {
        for (j = 0; j < col2; j++) {
            for (k = 0; k < col1; k++) {
                *(*(result + i) + j) += *(*(matrix1 + i) + k) * *(*(matrix2 + k) + j);
            }
        }
    }

    // displaying the resulting matrix
    printf("Here is the resultant matrix after multiplication:\n");
    for (i = 0; i < row1; i++) {
        for (j = 0; j < col2; j++) {
            printf("%d ", *(*(result + i) + j));
        }
        printf("\n");
    }

    // free allocated memory 
    for (i = 0; i < row1; i++)
        free(matrix1[i]);
    free(matrix1);

    for (i = 0; i < row2; i++)
        free(matrix2[i]);
    free(matrix2);

    for (i = 0; i < row1; i++)
        free(result[i]);
    free(result);

    return 0;
}
