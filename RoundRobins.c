#include <stdio.h>

#define MAX_PROCESSES 10

typedef struct {
    int pid; // Process ID
    int burst_time; // Burst time
    int remaining_time; // Remaining time for execution
} Process;

int main() {
    int num_processes, time_quantum, total_waiting_time = 0, total_turnaround_time = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);
    
    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);
    
    Process processes[MAX_PROCESSES];
    
    // Input the burst times for each process
    printf("Enter the burst times for each process:\n");
    for (int i = 0; i < num_processes; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].pid = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
    }
    
    // Perform round-robin scheduling
    int current_time = 0;
    while (1) {
        int all_processes_completed = 1;
        for (int i = 0; i < num_processes; i++) {
            if (processes[i].remaining_time > 0) {
                all_processes_completed = 0;
                if (processes[i].remaining_time > time_quantum) {
                    current_time += time_quantum;
                    processes[i].remaining_time -= time_quantum;
                } else {
                    current_time += processes[i].remaining_time;
                    total_turnaround_time += current_time;
                    processes[i].remaining_time = 0;
                    total_waiting_time += current_time - processes[i].burst_time;
                }
            }
        }
        if (all_processes_completed)
            break;
    }
    
    // Calculate average waiting and turnaround time
    float avg_waiting_time = (float) total_waiting_time / num_processes;
    float avg_turnaround_time = (float) total_turnaround_time / num_processes;
    
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
    
    return 0;
}
