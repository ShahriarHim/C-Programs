#include <stdio.h>
#include <stdlib.h>
void Descending(int arr[], int size) {
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
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("%s\n", argv[0]);
        return 1;
    }
    int size = argc - 1;
    int *arr = (int *)malloc(size * sizeof(int));
    for (int i = 1; i < argc; i++) {
        arr[i - 1] = atoi(argv[i]);
    }
    Descending(arr, size);
    printf("Sorted array in descending order: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}


