#include "../incs/philo.h"

void *my_thread_func(void *arg)
{
    char *name = (char *)arg; // 引数を文字列として受け取る
    printf("%s: starting work\n", name);
    sleep(10);
    printf("%s: done\n", name);
    return NULL; // 戻り値は不要なのでNULL
}

int main(void)
{
    pthread_t tid;
    pthread_create(&tid, NULL, my_thread_func, "Thread A");
    pthread_join(tid, NULL); // 終了待ち
    return 0;
}
