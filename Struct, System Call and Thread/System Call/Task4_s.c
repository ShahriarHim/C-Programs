#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>


int main(int argc, char *argv[]) {
    if (argc < 2) {
        return 1;
    }
    int size = argc - 1;
    int *arr = (int *)malloc(size * sizeof(int));
    for (int i = 1; i < argc; i++) {
        arr[i - 1] = atoi(argv[i]);
    }
    pid_t pid = fork();
    if (pid == -1) {
        printf("Fork failed.\n");
        return 1;
    }
    if (pid == 0) { 

        int i, j, temp;
        for (i = 0; i < size; i++) {
            for (j = i + 1; j < size; j++) {
                if (arr[i] < arr[j]) {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        printf("Sorted array in child process: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        int status;
        wait(&status);

        for (int i = 0; i < size; i++) {
            if (arr[i] % 2 == 0) {
                printf("%d is even.\n", arr[i]);
            } else {
                printf("%d is odd.\n", arr[i]);
            }
        }
    }
    free(arr);
    return 0;
}

