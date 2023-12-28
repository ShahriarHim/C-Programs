#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>


int main() {
	pid_t pid_1, pid_2;
	pid_1=fork();
	if (pid_1==0) {
    	pid_2=fork();
    	if (pid_2==0) {
        	printf("I am grandchild\n");
    	}
    	else {
        	wait(NULL);
        	printf("I am child\n");
    	}
	}
	else {
    	wait(NULL);
    	printf("I am parent\n");
	}
	return 0;
}

