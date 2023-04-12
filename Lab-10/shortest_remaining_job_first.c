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
            "PID:\t%d\tAT:\t%d\tBT:\t%d\tCT:\t%d\tTAT:\t%d\tWT:\t%d\n", 
            process_list[i].pid, 
            process_list[i].arrival_time, 
            process_list[i].burst_time,
            process_list[i].completion_time,
            process_list[i].turn_around_time,
            process_list[i].waiting_time
        );       
    }
}

void fill_temp_burst(Process process_list[], size_t length) {
    for(int i = 0; i < length; i++) {
        process_list[i].temp_burst = process_list[i].burst_time;
    }
}

Process* shortest_job(Process process_list[], size_t length, int time) {
    // find out the number of processes  with arrival time <= time
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (process_list[i].arrival_time <= time) {
            count++;
        }
    }

    Process* arr[count];

    // put them inside an array
    int i = 0;
    for (int j = 0; j < length; j++) {
        if (process_list[j].arrival_time <= time) {
            arr[i] = &process_list[j]; 
            i++;
        }
    }

    // find the process with the least burst time from them
    Process* min = arr[0];
    for (int x = 0; x < count; x++) {
        if (arr[x]->temp_burst < min->temp_burst) {
            min = arr[x];
        }
    }
    return min;
}

void shortest_remaining_time(Process process_list[], size_t length) {
    fill_temp_burst(process_list, length); // fill the temp burst time variable with the burst time

    int jobs = 0;
    int time = 1;

    while (jobs <= length) {
        Process* shortest_process = shortest_job(process_list, length, time);
        
        shortest_process->temp_burst--;

        if (shortest_process->temp_burst == 0) {
            shortest_process->temp_burst = 999;
            shortest_process->completion_time = time;
            shortest_process->turn_around_time = time - shortest_process->arrival_time;
            shortest_process->waiting_time = shortest_process->turn_around_time - shortest_process->burst_time;
            jobs++;
        }
        time++;
    }
    printList(process_list, length);
}

int main() {
    size_t length = 3;
    Process process_list[] = {
        {.pid = 1, .arrival_time = 0, .burst_time = 7},
        {.pid = 2, .arrival_time = 1, .burst_time = 3},
        {.pid = 3, .arrival_time = 3, .burst_time = 4}
    }; 
    shortest_remaining_time(process_list, length);
}
