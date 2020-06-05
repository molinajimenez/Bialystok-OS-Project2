#include <stdio.h>
#include <stdlib.h>
struct MatrixBase{
    int row1,col1;
    int row2,col2;
    int min,max;
    float **matrix1;
    float **matrix2;
};

float GetRandomFloatNumber(float min, float max)    
{  
    return (min + 1) + (((float) rand()) / (float) RAND_MAX) * (max - (min + 1));    
}