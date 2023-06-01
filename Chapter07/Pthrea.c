#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

int* enjoy(void *arg)
{
    int *i = (int *)malloc(sizeof(int));
    *i = 10;
    printf("Enjoying %d\n", *i);
    return i;
}