#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_VALUE 500

int *getRandomInterval(int lower, int upper, int count)
{
    int i;
    int *arr = malloc(count * sizeof(int));
    for (i = 0; i < count; i++)
    {
        arr[i] = (rand() % (upper - lower + 1)) + lower;
    }

    return arr;
}
double getRandomdoubleInterval(int limit)
{
    return (double)rand() / (double)(RAND_MAX / limit);
}

/*void multiplyMatrix(void)
{
    int result_matrix[params.rows1][params.rows2];
    //double matrix1 = params.mat1;
    //double matrix2 = params.mat2;
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
}*/
void RandomDimMatrixFill(int limit)
{

    //we define pointers of integers
    int *dim_matrix1;
    int *dim_matrix2;
    //we receive array of random integers. Index 0 is rows, index 1 is
    dim_matrix1 = getRandomInterval(20, 500, 2);
    double matrix1[dim_matrix1[0]][dim_matrix1[1]];
    dim_matrix2 = getRandomInterval(20, 500, 1);
    double matrix2[dim_matrix1[1]][dim_matrix2[0]];
    double result_matrix[dim_matrix1[0]][dim_matrix1[1]];
    double global_sum = 0;
    //fill matrix 1
    for (int rows1 = 0; rows1 < dim_matrix1[0]; rows1++)
    {
        for (int cols1 = 0; cols1 < dim_matrix1[1]; cols1++)
        {

            matrix1[rows1][cols1] = getRandomdoubleInterval(limit);
            printf("matrix 1, %d\n", matrix1[rows1][cols1]);
        }
    }

    //fill matrix 2
    for (int rows2 = 0; rows2 < dim_matrix1[1]; rows2++)
    {
        for (int cols2 = 0; cols2 < dim_matrix2[0]; cols2++)
        {

            matrix2[rows2][cols2] = getRandomdoubleInterval(limit);
            printf("matrix 2, %d\n", matrix2[rows2][cols2]);
        }
    }

    // multiplication.

    for (int rows_mat1 = 0; rows_mat1 < dim_matrix1[0]; rows_mat1++)
    {
        for (int cols_mat2 = 0; cols_mat2 < dim_matrix1[1]; cols_mat2++)
        {
            for (int cols_mat1 = 0; cols_mat1 < dim_matrix1[1]; cols_mat1++)
            {

                global_sum = global_sum + matrix1[rows_mat1][cols_mat1] * matrix2[cols_mat1][cols_mat2];
                //printf("%d\n",global_sum);
            }

            result_matrix[rows_mat1][cols_mat2] = global_sum;
            global_sum = 0;
        }
    }
}

void fillMatrix(int row1, int col1, int col2, int limit)
{
    double matrix1[row1][col1];
    double matrix2[col1][col2];

    //fill matrix 1
    for (int rows1 = 0; rows1 < row1; rows1++)
    {
        for (int cols1 = 0; cols1 < col1; cols1++)
        {

            matrix1[rows1][cols1] = getRandomdoubleInterval(limit);
        }
    }
    //fill matrix 2
    for (int rows2=0; rows2 < col2; rows2++)
    {
        for (int cols2=0; cols2 < col1; cols2++)
        {

            matrix2[rows2][cols2] = getRandomdoubleInterval(limit);
        }
    }
}
int main(int argc, char *argv[])
{
    srand(time(0));
    RandomDimMatrixFill(MAX_VALUE);
    return 0;
}
