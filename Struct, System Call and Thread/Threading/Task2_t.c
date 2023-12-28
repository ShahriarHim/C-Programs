#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
int thread_count = 0;
int thread_limit = 1;
void *thread(void *ptr) {
	for (int i = 0; i < 5; i++) {
    	printf("Thread %d prints %d\n", thread_count, thread_limit);
    	thread_limit++;
	}
	return NULL;
}
int main() {
	while (thread_count <= 5) {
    	pthread_t thread_exe;
    	pthread_create(&thread_exe, NULL,thread, NULL);
    	pthread_join(thread_exe, NULL);
    	thread_count++;
	}
	return 0;
}




