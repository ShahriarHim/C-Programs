#include <stdio.h>

int perfectNumber(int n) {
    int sum=0;
    for (int i=1; i<=n/2; i++) {
        if (n%i==0) {
            sum+=i;
        }
    }
    return sum==n;
}
int main() {
    int s,e;
    printf("Input: \n");
    scanf("%d", &s);
    scanf("%d", &e);
    
    printf("Output: \n");
    for (int i=s; i<=e; i++) 
    {
        if (perfectNumber(i)) 
        {
            printf("%d \n", i);
        }
    }
    return 0;
}

