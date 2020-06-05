#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *matrix_multiplication_runner(void *t)
{
    int a = *((int *)t);

    printf("Thread %d started \n", a);
    pthread_exit(0);


}

int main(int argc, char *argv[])
{
    int threads;
    if (argc >= 2)
    {
        threads = atoi(argv[1]);
        printf("Number of threads: %d\n",threads);
    }
    else
    {
        //we assume that the user is at least running on a dual core
        threads = 2;
        
    }

    pthread_t tids[threads];
    pthread_attr_t attr;
    
    for (int i = 0; i < threads; i++)
    {
        pthread_attr_init(&attr);
        pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
        pthread_create(&tids[i], &attr, matrix_multiplication_runner, &i);
        pthread_join(tids[i], NULL);
    }



}