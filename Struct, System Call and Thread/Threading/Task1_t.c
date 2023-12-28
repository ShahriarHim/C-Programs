#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
int thread_no;
void *thread_function(void *arg) {
    printf("Thread %d  running\n", thread_no);
    printf("Thread %d  closed\n", thread_no);
    return NULL;
}
int main() {
    thread_no = 1;
    while (thread_no <= 5) {
   	 pthread_t thread;
   	 pthread_create(&thread, NULL, thread_function, NULL);
   	 pthread_join(thread, NULL);
   	 thread_no++;
    }
    return 0;
}

