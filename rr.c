#include <stdio.h>

#define MAX_PROCESSES 10
#define TIME_QUANTUM 4

struct Process
{
    int id;
    int burst_time;
    int arrival_time;
    int remaining_time;
};

int main()
{
    int num_processes;

    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    struct Process processes[MAX_PROCESSES];
    printf("Enter the burst time and arrival time for each process:\n");

    for (int i = 0; i < num_processes; ++i)
    {
        printf("Process %d: ", i + 1);
        scanf("%d %d", &processes[i].burst_time, &processes[i].arrival_time);
        processes[i].id = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
    }

    int total_time = 0;
    int total_waiting_time = 0;
    printf("\nProcess execution order:\n");

    while (1)
    {
        int done = 1;
        for (int i = 0; i < num_processes; ++i)
        {
            if (processes[i].remaining_time > 0)
            {
                done = 0;
                if (processes[i].remaining_time > TIME_QUANTUM)
                {
                    total_time += TIME_QUANTUM;
                    processes[i].remaining_time -= TIME_QUANTUM;
                }
                else
                {
                    total_time += processes[i].remaining_time;
                    total_waiting_time += total_time - processes[i].arrival_time - processes[i].burst_time;
                    processes[i].remaining_time = 0;
                    printf("Process %d\n", processes[i].id);
                }
            }
        }
        if (done == 1)
            break;
    }

    printf("\nAverage waiting time: %.2f\n", (float)total_waiting_time / num_processes);
    return 0;
}
