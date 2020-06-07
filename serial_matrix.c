#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include <math.h>
struct MatrixBase GenerateMatrices(char *argv[])
{
    struct MatrixBase matrix;

    matrix.row1 = atoi(argv[2]);
    matrix.col1 = atoi(argv[3]);
    matrix.row2 = atoi(argv[3]);
    matrix.col2 = atoi(argv[4]);
    matrix.min = atoi(argv[5]);
    matrix.max = atoi(argv[6]);

    matrix.matrix1 = malloc(matrix.row1 * sizeof(double *));
    for (int i = 0; i < matrix.row1; i++)
    {
        matrix.matrix1[i] = malloc(matrix.col1 * sizeof(double));
    }

    matrix.matrix2 = malloc(matrix.row2 * sizeof(double *));
    for (int i = 0; i < matrix.row2; i++)
    {
        matrix.matrix2[i] = malloc(matrix.col2 * sizeof(double));
    }

    return matrix;
}

struct MatrixBase FillMatrices(struct MatrixBase matrix)
{
    for (int i = 0; i < matrix.row1; i++)
    {
        for (int j = 0; j < matrix.col1; j++)
        {
            matrix.matrix1[i][j] = GetRandomFloatNumber(matrix.min, matrix.max);
            // printf("%0.99lf\n",matrix.matrix1[i][j]);
        }
    }

    for (int i = 0; i < matrix.row2; i++)
    {
        for (int j = 0; j < matrix.col2; j++)
        {
            matrix.matrix2[i][j] = GetRandomFloatNumber(matrix.min, matrix.max);
            // printf("%0.99lf\n",matrix.matrix1[i][j]);

        }
    }

    return matrix;
}

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
                // if (isnan(operation))
                // {
                //     printf("Current value is NaN: \n Result -> %.4f\n",result[i][j]);
                //     printf("Current values are: \n Row -> %.4f\n Column -> %.4f\n",matrix.matrix1[i][k], matrix.matrix2[k][j]);
                //     printf("Previuos value is: \n Result -> %.4f\n",result[i][j]);
                //     printf("Previuos values are: \n Row -> %.4f\n Column -> %.4f\n",matrix.matrix1[i][k-1], matrix.matrix2[k-1][j]);
                //     printf("--------------------------------------------------\n");
                // }
                // else
                // {
                   
                // }
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