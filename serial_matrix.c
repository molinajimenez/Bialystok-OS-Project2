#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include <math.h>

struct MatrixBase global_struct;

void MultiplyMatrices(struct MatrixBase matrix)
{
    double sum;

    for (int i = 0; i < matrix.row1; i++)
    {
        for (int j = 0; j < matrix.col2; j++)
        {
            sum = 0;
            for (int k = 0; k < matrix.row2; k++)
            {
                sum = sum + (matrix.matrix1[i][k] * matrix.matrix2[k][j]);
            }
            matrix.resultMatrix[i][j] = sum;
        }
    }

    /*printf("FIRST MATRIX\n");
    for (int i = 0; i < matrix.row1; i++)
    {
        for (int j = 0; j < matrix.col1; j++)
        {
            printf("%0.6f ", matrix.matrix1[i][j]);
        }
        printf("\n");
    }

    printf("SECOND MATRIX\n");
    for (int i = 0; i < matrix.row2; i++)
    {
        for (int j = 0; j < matrix.col2; j++)
        {
            printf("%0.4f ", matrix.matrix2[i][j]);
        }
        printf("\n");
    }*/

    printf("First matrix consists of dimensions [row, col]\n %d %d\n", matrix.row1, matrix.col1);
    printf("Second matrix consists of dimensions [row, col]\n %d %d\n", matrix.row2, matrix.col2);
    printf("Result matrix consists of dimensions [row, col]\n %d %d\n", matrix.row1, matrix.col2);

    printf("RESULT\n");
    for (int i = 0; i < matrix.row1; i++)
    {
        for (int j = 0; j < matrix.col2; j++)
        {
            printf("%0.2f ", matrix.resultMatrix[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[])
{

    global_struct = GenerateMatrices(argv);
    global_struct = FillMatrices(global_struct);
    MultiplyMatrices(global_struct);
}