/* Implement Shortest Job Algorithm */
#include <stdio.h>

typedef struct {
    int pid;
    int burst_time;
    int arrival_time;
    int completion_time; 
    int turn_around_time;
    int waiting_time;
} Process;

void printTable(Process process_list[], size_t length) {
    printf("PID\tBT\tAT\tCT\tTAT\tWT\n");
    for (int i = 0; i < length; i++) {
        printf(
            "%d\t%d\t%d\t%d\t%d\t%d\n", 
            process_list[i].pid, 
            process_list[i].burst_time, 
            process_list[i].arrival_time,
            process_list[i].completion_time,
            process_list[i].turn_around_time,
            process_list[i].waiting_time
        );
    }
}

void shortest_job_algorithm(Process process_list[], size_t length) {

}

int main() {
    size_t length = 5;
    Process process_list[] = {
        {1, 6, 2, 0, 0, 0}, 
        {2, 2, 5, 0, 0, 0}, 
        {3, 8, 1, 0, 0, 0},
        {4, 3, 0, 0, 0, 0},
        {5, 4, 4, 0, 0, 0} 
    };
    printf("Number of Processes: %ld\n", length);
    shortest_job_algorithm(process_list, length);
    printTable(process_list, length);
}
