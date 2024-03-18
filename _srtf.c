#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct Process
{
    int pid;
    int AT;
    int BT;
    int RT;
    int CT;
    int WT;
    int TAT;
};

// Function to find the process with the shortest remaining time
int findShortestJob(struct Process *processes, int n, int currentTime)
{
    int Shortestjob = -1;
    int shortestTime = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (processes[i].AT <= currentTime && processes[i].RT < shortestTime && processes[i].RT > 0)
        {
            Shortestjob = i;
            shortestTime = processes[i].RT;
        }
    }
    return Shortestjob;
}

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process *processes = (struct Process *)malloc(n * sizeof(struct Process));
    if (processes == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("Enter arrival time and burst time of process %d: ", i + 1);
        scanf("%d %d", &processes[i].AT, &processes[i].BT);
        processes[i].pid = i + 1;
        processes[i].RT = processes[i].BT;
    }

    int currentTime = 0;
    int completed = 0;

    while (completed < n)
    {
        int shortestJob = findShortestJob(processes, n, currentTime);
        if (shortestJob == -1)
        {
            currentTime++;
            continue;
        }

        processes[shortestJob].RT--;

        if (processes[shortestJob].RT == 0)
        {
            completed++;
            processes[shortestJob].CT = currentTime + 1;
            processes[shortestJob].WT = processes[shortestJob].CT - processes[shortestJob].AT - processes[shortestJob].BT;
            processes[shortestJob].TAT = processes[shortestJob].CT - processes[shortestJob].AT;
        }
        currentTime++;
    }

    // Calculate average waiting time and turnaround time
    float avg_WT = 0;
    float avg_TAT = 0;
    for (int i = 0; i < n; i++)
    {
        avg_WT += processes[i].WT;
        avg_TAT += processes[i].TAT;
    }
    avg_WT /= n;
    avg_TAT /= n;

    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n", processes[i].pid, processes[i].AT, processes[i].BT, processes[i].CT, processes[i].WT, processes[i].TAT);
    }
    printf("\nAverage Waiting Time: %.2f\n", avg_WT);
    printf("Average Turnaround Time: %.2f\n", avg_TAT);

    free(processes);

    return 0;
}
