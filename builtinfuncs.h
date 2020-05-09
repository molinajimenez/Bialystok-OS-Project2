#include <stdio.h>
#include <stdlib.h>
struct MatrixBase
{
    int row1, col1;
    int row2, col2;
    int min, max;
    float **matrix1;
    float **matrix2;
    float **answ;
};
float GetRandomFloatNumber(float min, float max)
{
    return (min + 1) + (((float)rand()) / (float)RAND_MAX) * (max - (min + 1));
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
                result[i][j] = result[i][j] + (matrix.matrix1[i][k] * matrix.matrix2[k][j]);
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
            printf("%0.4f ", result[i][j]);
        }
        printf("\n");
    }
}
