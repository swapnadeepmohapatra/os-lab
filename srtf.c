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

// Sorting process according to their Arrival Time.
void sort_processes(struct Process *processes, int n)
{
    int i, j;
    struct Process temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (processes[j].arrival_time > processes[j + 1].arrival_time)
            {
                temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

// Find total burst time
int total_burst_time(struct Process *processes, int n)
{
    int total_burst_time = 0;
    for (int i = 0; i < n; i++)
    {
        total_burst_time += processes[i].burst_time;
    }
    return total_burst_time;
}

// Calculate the waiting time, turnaround time and response time for each process, using premption for shortest remaining time first
void calculate_times(struct Process *processes, int n)
{
    int i, j;
    int total_burst = total_burst_time(processes, n);
    int remaining_burst_time[n];
    for (i = 0; i < n; i++)
    {
        remaining_burst_time[i] = processes[i].burst_time;
    }
    int current_time = 0;
    int completed = 0;
    int min_burst_index = 0;
    int min_burst = 10000;
    int flag = 0;
    while (completed != n)
    {
        for (i = 0; i < n; i++)
        {
            if (processes[i].arrival_time <= current_time && remaining_burst_time[i] < min_burst && remaining_burst_time[i] > 0)
            {
                min_burst = remaining_burst_time[i];
                min_burst_index = i;
                flag = 1;
            }
        }
        if (flag == 0)
        {
            current_time++;
            continue;
        }
        remaining_burst_time[min_burst_index]--;
        min_burst = remaining_burst_time[min_burst_index];
        if (min_burst == 0)
        {
            min_burst = 10000;
        }
        if (remaining_burst_time[min_burst_index] == 0)
        {
            completed++;
            processes[min_burst_index].completion_time = current_time + 1;
            processes[min_burst_index].waiting_time = processes[min_burst_index].completion_time - processes[min_burst_index].arrival_time - processes[min_burst_index].burst_time;
            if (processes[min_burst_index].waiting_time < 0)
            {
                processes[min_burst_index].waiting_time = 0;
            }
        }
        current_time++;
    }
}

// Calculate the turnaround time and response time for each process
void calculate_turnaround_response_times(struct Process *processes, int n)
{
    for (int i = 0; i < n; i++)
    {
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].response_time = processes[i].waiting_time;
    }
}

// Calculate the average waiting time, turnaround time and response time
void calculate_average_times(struct Process *processes, int n)
{
    float total_waiting_time = 0;
    float total_turnaround_time = 0;
    float total_response_time = 0;
    for (int i = 0; i < n; i++)
    {
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;
        total_response_time += processes[i].response_time;
    }
    printf("Average Waiting Time: %.2f\n", total_waiting_time / n);
    printf("Average Turnaround Time: %.2f\n", total_turnaround_time / n);
    printf("Average Response Time: %.2f\n", total_response_time / n);
}

// Display the process details
void display(struct Process *processes, int n)
{
    printf("PID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\tResponse Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time, processes[i].response_time);
    }
}

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process processes[n];
    take_input(processes, n);
    sort_processes(processes, n);
    calculate_times(processes, n);
    calculate_turnaround_response_times(processes, n);
    calculate_average_times(processes, n);
    display(processes, n);
    return 0;
}