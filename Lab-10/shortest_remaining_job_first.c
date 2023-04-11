#include <stdio.h>

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int temp_burst;
    int completion_time;
    int turn_around_time;
    int waiting_time;
} Process;

void printList(Process process_list[], size_t length) {
    for(int i = 0; i < length; i++) {
        printf(
            "PID:\t%d\tAT:\t%d\tBT:\t%d\n", 
            process_list[i].pid, 
            process_list[i].arrival_time, 
            process_list[i].burst_time
        );       
    }
}

void fill_temp_burst(Process process_list[], size_t length) {
    for(int i = 0; i < length; i++) {
        process_list[i].temp_burst = process_list[i].burst_time;
    }
}

int find_min_time(Process process_list[], size_t length) {
    int min = process_list[0].arrival_time;
    for (int i = 0; i < length; i++) {
        if (process_list[i].arrival_time < min) {
            min = process_list[i].arrival_time;
        }
    }
    return min;
}

Process shortest_job(Process process_list[], size_t length) {
    Process min = process_list[0];
    for (int i = 0; i < length; i++) {
        if (process_list[i].burst_time < min.burst_time) {
            min = process_list[i];
        }
    }
    return min;
}

void shortest_remaining_time(Process process_list[], size_t length) {
    fill_temp_burst(process_list, length); // fill the temp burst time variable with the burst time

    int jobs = 0;
    int time = 0;

    while (jobs != length) {
        Process shortest_process = shortest_job(process_list, length);
        if (shortest_process.arrival_time <= time) {
            shortest_process.burst_time--;
            if (shortest_process.burst_time == 0) {
                shortest_process.burst_time = 69; // FIGURE OUT THE INFITE LOOP
                jobs++;
                printf("jobs: %d\n", jobs);
            }
        }
        // printList(process_list, length);
        time++;
    }
}

int main() {
    size_t length = 3;
    Process process_list[] = {
        {.pid = 1, .arrival_time = 0, .burst_time = 0},
        {.pid = 2, .arrival_time = 1, .burst_time = 0},
        {.pid = 3, .arrival_time = 3, .burst_time = 0}
    }; 
    shortest_remaining_time(process_list, length);
}
