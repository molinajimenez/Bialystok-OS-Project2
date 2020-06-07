#include <stdio.h>
#include <stdlib.h>
struct MatrixBase
{
    int row1, col1;
    int row2, col2;
    int min, max;
    double **matrix1;
    double **matrix2;
};

double GetRandomFloatNumber(double min, double max)
{
    return (min + 1) + (((double)rand()) / (double)RAND_MAX) * (max - (min + 1));
}