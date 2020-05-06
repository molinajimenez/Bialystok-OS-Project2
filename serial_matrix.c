#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_VALUE 500
struct matrixParams
{
    int rows1, cols1, rows2, cols2;
    float *mat1;
    float *mat2;
};
int *getRandomInterval(int lower, int upper, int count)
{
    int i;
    int *arr = malloc(count * sizeof(int));
    srand(time(0));
    for (i = 0; i < count; i++)
    {
        arr[i] = (rand() % (upper - lower + 1)) + lower;
    }

    return arr;
}
float getRandomFloatInterval(int limit)
{
    return (float)rand() / (float)(RAND_MAX / limit);
}

void multiplyMatrix(struct matrixParams params)
{
    int result_matrix[params.rows1][params.rows2];
    //float matrix1 = params.mat1;
    //float matrix2 = params.mat2;
    for (int rows_mat1 = 0; rows_mat1 < params.rows1; rows_mat1++)
    {
        for (int cols_mat2 = 0; cols_mat2 < params.rows2; cols_mat2++)
        {
            int global_sum = 0;
            for (int cols_mat1 = 0; cols_mat1 < params.cols1; cols_mat1++)
            {

                //global_sum = global_sum + params.mat1[rows_mat1][cols_mat1] * params.mat2[cols_mat1][cols_mat2];
                global_sum = global_sum + *(*(params.mat1 + rows_mat1) + cols_mat2)) * *(*(params.mat2 + cols_mat1) + cols_mat1);
            }

            result_matrix[rows_mat1][cols_mat2] = global_sum;
        }
    }
}
struct matrixParams RandomDimMatrixFill(int limit)
{
    struct matrixParams params;
    //we define pointers of integers
    int *dim_matrix1;
    int *dim_matrix2;
    //we receive array of random integers. Index 0 is rows, index 1 is
    dim_matrix1 = getRandomInterval(20, 500, 2);
    float matrix1[dim_matrix1[0]][dim_matrix1[1]];
    dim_matrix2 = getRandomInterval(20, 500, 1);
    float matrix2[dim_matrix1[1]][dim_matrix2[0]];

    //fill matrix 1
    for (int rows1; rows1 < dim_matrix1[0]; rows1++)
    {
        for (int cols1; cols1 < dim_matrix1[1]; cols1++)
        {

            matrix1[rows1][cols1] = getRandomFloatInterval(limit);
        }
    }
    //fill matrix 2
    for (int rows2; rows2 < dim_matrix1[1]; rows2++)
    {
        for (int cols2; cols2 < dim_matrix2[0]; cols2++)
        {

            matrix2[rows2][cols2] = getRandomFloatInterval(limit);
        }
    }

    //we set variables of params
    params.rows1 = dim_matrix1[0];
    params.cols1 = dim_matrix1[1];
    params.rows2 = dim_matrix1[1];
    params.cols2 = dim_matrix2[0];
    params.mat1 = (*matrix1);
    params.mat2 = (*matrix2);
    return params;
}

struct matrixParams fillMatrix(int row1, int col1, int col2, int limit)
{
    float matrix1[row1][col1];
    float matrix2[col1][col2];

    //fill matrix 1
    for (int rows1; rows1 < row1; rows1++)
    {
        for (int cols1; cols1 < col1; cols1++)
        {

            matrix1[rows1][cols1] = getRandomFloatInterval(limit);
        }
    }
    //fill matrix 2
    for (int rows2; rows2 < col2; rows2++)
    {
        for (int cols2; cols2 < col1; cols2++)
        {

            matrix2[rows2][cols2] = getRandomFloatInterval(limit);
        }
    }
    struct matrixParams params = {
        row1, col1,
        col1, col2,
        *(matrix1), *(matrix2)};
}
int main(int argc, char *argv[])
{
    struct matrixParams myParams;
    if (*argv[1] == (char)'m')
    {
        myParams = fillMatrix(*argv[2], *argv[3], *argv[4], MAX_VALUE);
    }
    else
    {
        myParams = RandomDimMatrixFill(MAX_VALUE);
    }

    multiplyMatrix(myParams);
}
