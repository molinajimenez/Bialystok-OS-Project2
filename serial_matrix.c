#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include <math.h>




void MultiplyMatrices(struct MatrixBase matrix)
{
    double result[matrix.row1][matrix.col2];
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
            result[i][j] = sum;
        }
    }

    printf("FIRST MATRIX\n");
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
    }
    printf("RESULT\n");
    for (int i = 0; i < matrix.row1; i++)
    {
        for (int j = 0; j < matrix.col2; j++)
        {
            printf("%0.2f ", result[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[])
{

    if (*argv[1] == 'm')
    {
        struct MatrixBase matrix = GenerateMatrices(argv);
        matrix = FillMatrices(matrix);
        MultiplyMatrices(matrix);
    }
}