//RR (Round Robin)
#include <stdio.h>

void round_robin(int processes[], int n, int bt[], int quantum) {
    int wt[n], tat[n];
    int remaining_time[n];

    for (int i = 0; i < n; i++)
        remaining_time[i] = bt[i];

    int t = 0; // Current time

    while (1) {
        int done = 1;

        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                done = 0;

                if (remaining_time[i] > quantum) {
                    t += quantum;
                    remaining_time[i] -= quantum;
                }
                else {
                    t += remaining_time[i];
                    wt[i] = t - bt[i];
                    remaining_time[i] = 0;
                }
            }
        }

        if (done == 1)
            break;
    }

    // Calculate turnaround time
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];

    // Print results
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++)
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i], bt[i], wt[i], tat[i]);
}

int main() {
    int processes[] = { 1, 2, 3 };
    int n = sizeof(processes) / sizeof(processes[0]);

    int burst_time[] = { 10, 5, 8 };
    int quantum = 2;

    round_robin(processes, n, burst_time, quantum);

    return 0;
}
