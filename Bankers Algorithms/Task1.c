#include <stdio.h>

#define N 5
#define M 4

void detectDeadlock(int allocation[N][M], int max[N][M], int available[M]);

int main() {
    int allocation[N][M] = {
        {0, 1, 0, 3},
        {2, 0, 0, 0},
        {3, 0, 2, 0},
        {2, 1, 1, 5},
        {0, 0, 2, 2}
    };

    int max[N][M] = {
        {6, 4, 3, 4},
        {3, 2, 2, 1},
        {9, 1, 2, 6},
        {2, 2, 2, 8},
        {4, 3, 3, 7}
    };

    int available[M] = {3, 3, 2, 1};

    detectDeadlock(allocation, max, available);

    return 0;
}

void detectDeadlock(int allocation[N][M], int max[N][M], int available[M]) {
    int finish[N] = {0};
    int dead[N] = {0};
    int i, j, k;

    int need[N][M];
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    int flag = 1;

    while (flag) {
        flag = 0;

        for (i = 0; i < N; i++) {
            int c = 0;

            for (j = 0; j < M; j++) {
                if (finish[i] == 0 && need[i][j] <= available[j]) {
                    c++;

                    if (c == M) {
                        for (k = 0; k < M; k++) {
                            available[k] += allocation[i][k];
                            finish[i] = 1;
                            flag = 1;
                        }

                        if (finish[i] == 1) {
                            i = N;
                        }
                    }
                }
            }
        }
    }

    j = 0;
    flag = 0;

    for (i = 0; i < N; i++) {
        if (finish[i] == 0) {
            dead[j] = i;
            j++;
            flag = 1;
        }
    }

    if (flag == 1) {
        printf("\nDeadlock Ahead\n");

    } else {
        printf("\nSafe here\n");
    }
}
