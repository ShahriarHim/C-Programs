#include <stdio.h>
#include <stdlib.h>

void check(int n) {
    if (n% 2 == 0) {
        printf("%d is even.\n", n);
    } else {
        printf("%d is odd.\n", n);
    }
}
int main(int argc, char *argv[]) {
    if (argc < 2) {
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        int n = atoi(argv[i]);
        check(n);
    }
    return 0;
}

