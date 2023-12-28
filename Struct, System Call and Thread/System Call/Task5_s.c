#include <stdio.h> 
#include <sys/wait.h>  
#include <stdlib.h>  
#include <unistd.h>
int main() {
	printf("Parent process ID : %d\n", getpid());
	if(!fork()) { 
    	printf("Child process ID : %d\n", getpid());
    	for(int i=0;i<3; i++) {
        	if(!fork()) {
            	printf("Grandchild process ID : %d\n", getpid());
            	exit(0);
        	}
        	else {
            	wait(NULL);
        	}
    	}
	}
	return 0;
}


