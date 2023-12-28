#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <unistd.h>
int main() {
	int *process_count = mmap(NULL, sizeof *process_count, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	*process_count = 0;

	int a = fork();
	int b = fork();
	int c = fork();

	if (a == 0 || b == 0 || c == 0) {
    	if (getpid() % 2 != 0) {
        	fork();
    	}
    	exit(0);
	}
	wait(NULL);
	(*process_count)++;
	if (a > 0 && b > 0 && c > 0) {
    	printf("Number of processes created : %d\n", *process_count);
    	munmap(process_count, sizeof *process_count);
	}
	return 0;
}


