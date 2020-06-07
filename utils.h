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
};

double GetRandomFloatNumber(double min, double max)
{
    // if(SEED == 0){
    //     srand(0);
    //     SEED = 1;
    // }
    return (min + 1) + (((double)rand()) / (double)RAND_MAX) * (max - (min + 1));
}