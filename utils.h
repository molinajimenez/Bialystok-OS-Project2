#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int SEED = 0;

struct MatrixBase
{
    int row1, col1;
    int row2, col2;
    int min, max;
    double **matrix1;
    double **matrix2;
    int num_threads;
    int leap;
    double **resultMatrix;

};

double GetRandomFloatNumber(double min, double max)
{
    // if(SEED == 0){
    //     srand(0);
    //     SEED = 1;
    // }
    return (min + 1) + (((double)rand()) / (double)RAND_MAX) * (max - (min + 1));
}

struct MatrixBase GenerateMatrices(char *argv[])
{
    struct MatrixBase matrix;

    matrix.row1 = atoi(argv[1]);
    matrix.col1 = atoi(argv[2]);
    matrix.row2 = atoi(argv[2]);
    matrix.col2 = atoi(argv[3]);
    matrix.min = atoi(argv[4]);
    matrix.max = atoi(argv[5]);
    
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

    matrix.resultMatrix = malloc(matrix.row1 * sizeof(double *));
    for (int i = 0; i < matrix.row1; i++)
    {
        matrix.resultMatrix[i] = malloc(matrix.col2 * sizeof(double));
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