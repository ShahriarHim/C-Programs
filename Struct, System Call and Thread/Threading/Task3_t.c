#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

char name1[100];
char name2[100];
char name3[100];
int thread_count;
int sum1, sum2, sum3;

struct thread_input {
	char word_arr[100];
};


int get_ascii_sum(char *word_arr) {
	int sum = 0;
	int len = strlen(word_arr);
	for (int i = 0; i < len; i++) {
    	sum += word_arr[i];
	}
	return sum;
}
void *thread_func(void *ptr) {
	struct thread_input input;

	if (thread_count == 1) {
    	printf("Enter first name: ");
    	scanf("%[^\n]%*c", input.word_arr);
    	sum1 = get_ascii_sum(input.word_arr);
    	strcpy(name1, input.word_arr);
	} else if (thread_count == 2) {
    	printf("Enter second name: ");
    	scanf("%[^\n]%*c", input.word_arr);
    	sum2 = get_ascii_sum(input.word_arr);
    	strcpy(name2, input.word_arr);
	} else if (thread_count == 3) {
    	printf("Enter third name: ");
    	scanf("%[^\n]%*c", input.word_arr);
    	sum3 = get_ascii_sum(input.word_arr);
    	strcpy(name3, input.word_arr);
	}

	return NULL;

}

int main() {
	thread_count = 1;


	while (thread_count <= 3) {
    	pthread_t thr;
    	if (pthread_create(&thr, NULL, thread_func, NULL) != 0) {
        	fprintf(stderr, "Error creating thread\n");
        	return 1;
    	}
    	if (pthread_join(thr, NULL) != 0) {
        	fprintf(stderr, "Error joining thread\n");
        	return 1;
    	}
    	thread_count++;
	}

	if (sum1 == sum2 && sum1 == sum3) {
    	printf("Youreka\n");
	} else if ((sum1 != sum2 && sum1 == sum3) || (sum1 == sum2 && sum1 != sum3) || (sum2 == sum3 && sum2 != sum1)) {
    	printf("Miracle\n");
	} else {
    	printf("Hasta la vista\n");
	}

	return 0;

}
