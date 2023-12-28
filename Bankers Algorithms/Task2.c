#include <stdio.h>
#include <stdbool.h>

#define N 6
#define M 4

int main() {
    int allocation[N][M] = {
        {0, 1, 0, 3},
        {2, 0, 0, 3},
        {3, 0, 2, 0},
        {2, 1, 1, 5},
        {0, 0, 2, 2},
        {1, 2, 3, 1}
    };
    int max[N][M] = {
        {6, 4, 3, 4},
        {3, 2, 2, 4},
        {9, 1, 2, 6},
        {2, 2, 2, 8},
        {4, 3, 3, 7},
        {6, 2, 6, 5}
    };
    int available[M] = {2, 2, 2, 1};

    int work[M];
    for (int i = 0; i < M; i++) {
        work[i] = available[i];
    }

    bool finish[N] = {false};

    int sequence[N];
    int sequenceIdx = 0;

    bool found;
    do {
        found = false;
        for (int i = 0; i < N; i++) {
            if (!finish[i]) {
                bool canRun = true;
                for (int j = 0; j < M; j++) {
                    if (max[i][j] - allocation[i][j] > work[j]) {
                        canRun = false;
                        break;
                    }
                }

                if (canRun) {
                    for (int j = 0; j < M; j++) {
                        work[j] += allocation[i][j];
                    }

                    finish[i] = true;
                    sequence[sequenceIdx] = i;
                    sequenceIdx++;
                    found = true;
                }
            }
        }
    } while (found);

    bool isSafe = true;
    for (int i = 0; i < N; i++) {
        if (!finish[i]) {
            isSafe = false;
            break;
        }
    }

    if (isSafe) {
        printf("System is safe.\n");
        printf("Safe sequence: ");
        for (int i = 0; i < N; i++) {
            printf("->P%d", sequence[i]);
        }
        printf("\n");
    } else {
        printf("System is not safe.\n");
    }

    return 0;
}
