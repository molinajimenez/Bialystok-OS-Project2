#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "utils.h"
#define NUMBERTHREADS 4;
struct MatrixBase global_struct;
pthread_mutex_t mutex;

void *matrix_multiplication_runner(void *t)
{
    double localSum;
    int x = *((int *)t);
    for (int i = 0; i < global_struct.row1; i++)
    {
        for (int j = 0; j < global_struct.col2; j++)
        {
            localSum = 0;
            for (int k = x; k < global_struct.row2; k += 4)
            {
                localSum = localSum + (global_struct.matrix1[i][k] * global_struct.matrix2[k][j]);
            }
            // pthread_mutex_lock(&mutex);
            global_struct.resultMatrix[i][j] = localSum;
            // pthread_mutex_unlock(&mutex);
        }
    }

    pthread_exit(0);
}

int main(int argc, char *argv[])
{
    if (argc >= 2)
    {

        //params.threads = atoi(argv[1]);
        printf("OKI");
    }
    else
    {
        //we assume that the user is at least running on a dual core processor

        printf("OKI");
    }
    global_struct = GenerateMatrices(argv);
    global_struct = FillMatrices(global_struct);

    pthread_t tids[4];
    pthread_attr_t attr;
    pthread_mutex_init(&mutex,NULL);

    for (int i = 0; i < 4; i++)
    {
        pthread_attr_init(&attr);
        pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

        pthread_create(&tids[i], &attr, matrix_multiplication_runner, &i);
    }
    for (int i = 0; i < 4; i++)
    {
        pthread_join(tids[i], NULL);
    }

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