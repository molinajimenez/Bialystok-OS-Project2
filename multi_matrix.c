#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "utils.h"
struct MatrixBase global_struct;
// pthread_mutex_t mutex;

void *matrix_multiplication_runner(void *arg)
{
    double localSum;
    struct MatrixBase *local_struct = (struct MatrixBase *)arg;

    // pthread_mutex_lock(&mutex);

    for (int i = 0; i < local_struct->row1; i++)
    {
        for (int j = 0; j < local_struct->col2; j++)
        {
            localSum = 0;
            for (int k = local_struct->num_threads; k < local_struct->row2; k += global_struct.leap)
            {
                localSum = localSum + (local_struct->matrix1[i][k] * local_struct->matrix2[k][j]);
            }
            local_struct->resultMatrix[i][j] = localSum;
        }
    }
    // pthread_mutex_unlock(&mutex);
    pthread_exit(0);
}

int main(int argc, char *argv[])
{
    global_struct = GenerateMatrices(argv);
    global_struct = FillMatrices(global_struct);
    int threads = atoi(argv[6]);
    global_struct.leap = threads;
    pthread_t tids[global_struct.leap];
    pthread_attr_t attr;
    for (int i = 0; i < global_struct.leap; i++)
    {
        global_struct.num_threads = i;
        pthread_attr_init(&attr);
        pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
        pthread_create(&tids[i], &attr, matrix_multiplication_runner, &global_struct);
    }

    for (int i = 0; i < global_struct.leap; i++)
    {
        pthread_join(tids[i], NULL);
    }
    printf("First matrix consists of dimensions [row, col]\n %d %d\n", global_struct.row1, global_struct.col1);
    printf("Second matrix consists of dimensions [row, col]\n %d %d\n", global_struct.row2, global_struct.col2);
    printf("Result matrix consists of dimensions [row, col]\n %d %d\n", global_struct.row1, global_struct.col2);


    printf("RESULT\n");
    for (int i = 0; i < global_struct.row1; i++)
    {
        for (int j = 0; j < global_struct.col2; j++)
        {
            printf("%0.2f ", global_struct.resultMatrix[i][j]);
        }
        printf("\n");
    }
}
