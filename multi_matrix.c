#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "builtinfuncs.h"
void *MultiplyMatrices(void *struct_matrix)
{
    struct MatrixBase *arg_ptr = (struct MatrixBase *)struct_matrix;

    float result[arg_ptr->row1][arg_ptr->col2];
    arg_ptr->answ = malloc(arg_ptr->row1 * sizeof(int *));

    for (int i = 0; i < arg_ptr->row1; i++)
    {
        for (int j = 0; j < arg_ptr->col2; j++)
        {
            for (int k = 0; k < arg_ptr->row2; k++)
            {
                result[i][j] = result[i][j] + (arg_ptr->matrix1[i][k] * arg_ptr->matrix2[k][j]);
            }
        }
    }
    arg_ptr->answ = result;

    
    pthread_exit(0);
}

void *PrintMatrix(void *struct_matrix){
    struct MatrixBase *arg_ptr = (struct MatrixBase *)struct_matrix;
    printf("FIRST MATRIX\n");
    for (int i = 0; i < arg_ptr->row1; i++)
    {
        for (int j = 0; j < arg_ptr->col1; j++)
        {
            printf("%0.6f ", arg_ptr->matrix1[i][j]);
        }
        printf("\n");
    }

    printf("SECOND MATRIX\n");
    for (int i = 0; i < arg_ptr->row2; i++)
    {
        for (int j = 0; j < arg_ptr->col2; j++)
        {
            printf("%0.4f ", arg_ptr->matrix2[i][j]);
        }
        printf("\n");
    }
    printf("RESULT\n");
    for (int i = 0; i < arg_ptr->row1; i++)
    {
        for (int j = 0; j < arg_ptr->col2; j++)
        {
            printf("%0.4f ", arg_ptr->answ[i][j]);
        }
        printf("\n");
    }
}
int main(int argc, char *argv[])
{
    int threads = atoi(argv[1]);

    struct MatrixBase t_params[threads];
    pthread_t arr[threads];
    for (int i = 0; i < threads; i++)
    {
        pthread_create(&arr[i], NULL, MultiplyMatrices, &t_params[i]);
    }

    for (int i = 0; i < threads; i++)
    {
        pthread_join(arr[i], NULL);
    }

    //PrintMatrix(t)
}