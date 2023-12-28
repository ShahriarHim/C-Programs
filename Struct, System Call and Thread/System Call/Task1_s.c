#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH 100
 
int main() {
	FILE *filePtr;
	filePtr = fopen("input_systemcall_1.txt", "w");
	if (filePtr == NULL) {
    	perror("Error opening file");
    	exit(1);
	}
 

	char input_line[MAX_LENGTH];
	int user_input = 0;
	while (user_input != -1 ) {
    	fgets(input_line, MAX_LENGTH, stdin);
    	sscanf(input_line, "%d", &user_input);
    	if (user_input != -1) {
        	fputs(input_line, filePtr); 
    	}
	}
 
	
	fclose(filePtr);
 
	return 0;
}
