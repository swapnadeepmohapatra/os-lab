// Implement Shortest Job First CPU scheduling algorithim

#include <stdio.h>

struct Process
{
    int pid;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int response_time;
    int completion_time;
};

// Take input from user
void take_input(struct Process *processes, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].pid = i + 1;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
        processes[i].response_time = 0;
    }
}

// Sorting process according to their Burst Time.
void sort_processes(struct Process *processes, int n)
{
    int i, j;
    struct Process temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (processes[j].burst_time > processes[j + 1].burst_time)
            {
                temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

// Calculate the waiting time, turnaround time and response time for each process
void calculate_times(struct Process *processes, int n)
{
    int i;
    processes[0].waiting_time = 0;
    processes[0].turnaround_time = processes[0].burst_time;
    processes[0].response_time = 0;
    int cummulative_burst_time = 0;
    for (i = 1; i < n; i++)
    {
        cummulative_burst_time = cummulative_burst_time + processes[i - 1].burst_time;
        processes[i].waiting_time = cummulative_burst_time - processes[i].arrival_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        processes[i].response_time = processes[i].waiting_time;
    }
}

// Print the processes
void print_processes(struct Process *processes, int n)
{
    int i;
    printf("PID\tAT\tBT\tWT\tTAT\tRT\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time, processes[i].response_time);
    }
}

int main()
{
    // Take input from user
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct Process processes[n];

    take_input(processes, n);

    sort_processes(processes, n);

    calculate_times(processes, n);

    print_processes(processes, n);
}