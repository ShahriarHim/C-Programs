#include <stdio.h>

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
};

int findShortestJob(struct Process processes[], int n, int currentTime) {
    int minBT = 9999;
    int minIdx = -1;

    for (int i = 0; i < n; ++i) {
        if (processes[i].arrivalTime <= currentTime && processes[i].remainingTime < minBT && processes[i].remainingTime > 0) {
            minBT = processes[i].remainingTime;
            minIdx = i;
        }
    }
    return minIdx;
}

void psjfScheduling(struct Process processes[], int n) {
    int currentTime = 0;
    int completedProcesses = 0;

    printf("Gantt Chart:\n");

    while (completedProcesses < n) {
        int shortestJobIdx = findShortestJob(processes, n, currentTime);

        if (shortestJobIdx == -1) {
            currentTime++;
            continue;
        }

        processes[shortestJobIdx].remainingTime--;
        printf("   P%d   %d", processes[shortestJobIdx].id, currentTime + 1);

        currentTime++;

        if (processes[shortestJobIdx].remainingTime == 0) {
            completedProcesses++;
            processes[shortestJobIdx].completionTime = currentTime;
            processes[shortestJobIdx].turnaroundTime = processes[shortestJobIdx].completionTime - processes[shortestJobIdx].arrivalTime;
            processes[shortestJobIdx].waitingTime = processes[shortestJobIdx].turnaroundTime - processes[shortestJobIdx].burstTime;
        }
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter total process number: ");
    scanf("%d", &n);

    struct Process processes[10];
    
    printf("Enter arrival and burst time for all process:\n");

    for (int i = 0; i < n; i++) {
        printf("Enter arrival and burst time for process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrivalTime, &processes[i].burstTime);
        processes[i].id = i + 1;
        processes[i].remainingTime = processes[i].burstTime;
    }

    psjfScheduling(processes, n);


    printf("\nProcess\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; ++i) {
        printf("%d\t%d\t%d\t%d\n", processes[i].id, processes[i].completionTime, processes[i].turnaroundTime, processes[i].waitingTime);
    }

    return 0;
}
