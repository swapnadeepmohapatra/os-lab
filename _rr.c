#include <stdio.h>

void findWaitingTime(int processes[], int n, int bt[], int wt[], int quantum)
{
    int remainingTime[n];
    for (int i = 0; i < n; i++)
        remainingTime[i] = bt[i];
    int currentTime = 0;
    while (1)
    {
        int done = 1;
        for (int i = 0; i < n; i++)
        {
            if (remainingTime[i] > 0)
            {
                done = 0;
                if (remainingTime[i] > quantum)
                {
                    currentTime += quantum;
                    remainingTime[i] -= quantum;
                }
                else
                {
                    currentTime = currentTime + remainingTime[i];
                    wt[i] = currentTime - bt[i];
                    remainingTime[i] = 0;
                }
            }
        }
        if (done == 1)
            break;
    }
}

void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[])
{
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

void findAvgTime(int processes[], int n, int bt[], int quantum)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    findWaitingTime(processes, n, bt, wt, quantum);
    findTurnAroundTime(processes, n, bt, wt, tat);
    printf("Processes Burst Time Waiting Time Turn-Around Time\n");
    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf(" %d \t\t %d \t\t %d \t\t %d\n", i + 1, bt[i], wt[i], tat[i]);
    }
    printf("Average waiting time = %.2f\n", (float)total_wt / (float)n);
    printf("Average turn-around time = %.2f\n", (float)total_tat / (float)n);
}
int main()
{
    int processes[] = {1, 2, 3, 4, 5};
    int n = sizeof processes / sizeof processes[0];
    int burst_time[n];
    int arrival_time[n];
    int quantum;
    printf("Enter the burst time and arrival time for each process:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d %d", &burst_time[i], &arrival_time[i]);
    }
    printf("Enter the quantum time: ");
    scanf("%d", &quantum);
    findAvgTime(processes, n, burst_time, quantum);
    return 0;
}