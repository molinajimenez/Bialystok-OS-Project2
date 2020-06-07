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
        }
    }

    for (int i = 0; i < matrix.row2; i++)
    {
        for (int j = 0; j < matrix.col2; j++)
        {
            matrix.matrix2[i][j] = GetRandomFloatNumber(matrix.min, matrix.max);
        }
    }

    return matrix;
}

void MultiplyMatrices(struct MatrixBase matrix)
{
    float result[matrix.row1][matrix.col2];

    for (int i = 0; i < matrix.row1; i++)
    {
        for (int j = 0; j < matrix.col2; j++)
        {
            for (int k = 0; k < matrix.row2; k++)
            {
                float operation = result[i][j] + (matrix.matrix1[i][k] * matrix.matrix2[k][j]);
                if (isnan(operation))
                {
                    printf("value is NaN");
                }
                else
                {
                    result[i][j] = operation;
                }
            }
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
            if (isnan(result[i][j]))
            {
                
                printf("%.99g \n", result[i][j]);
                
            }
            //printf("%.99g \n", result[i][j]);
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