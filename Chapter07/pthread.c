#include <stdio.h>
#include <assert.h>
#include <pthread.h>

void *mythread(void *arg)
{
    printf("%s\n", (char *)arg);
    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t p1, p2;
    // 'pthread_t'可以看做是一个线程的标识符，它在创建线程时被填充，用于标识线程。
    int rc;
    printf("main: begin\n");
    rc = pthread_create(&p1, NULL, mythread, "A");
    assert(rc == 0);
    // 第二个参数代表线程的属性，它用于设置线程的调度策略、优先级等信息，如果为NULL，则使用默认的属性。
    rc = pthread_create(&p2, NULL, mythread, "B");
    assert(rc == 0);
    // 第三个参数是线程运行函数的地址，它是一个指向函数的指针，线程将从这个函数开始运行。
    // join waits for the threads to finish
    rc = pthread_join(p1, NULL);
    assert(rc == 0);
    rc = pthread_join(p2, NULL);
    assert(rc == 0);
    printf("main: end\n");
    return 0;
}