/* Implement Shortest Job First CPU Scheduling Algorithm */
#include <stdio.h>

typedef struct {
    int pid;
    int arrival_time;
    int burst_time;
    int completion_time; 
    int turn_around_time;
    int waiting_time;
    int bt;
} Process;

void printTable(Process process_list[], size_t length) {
    printf("PID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < length; i++) {
        printf(
            "%d\t%d\t%d\t%d\t%d\t%d\n", 
            process_list[i].pid, 
            process_list[i].arrival_time,
            process_list[i].burst_time, 
            process_list[i].completion_time,
            process_list[i].turn_around_time,
            process_list[i].waiting_time
        );
    }
}

void sortByBurstTime(Process process_list[], size_t length) {
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            if (process_list[i].burst_time < process_list[j].burst_time) {
                Process temp = process_list[i];
                process_list[i] = process_list[j];
                process_list[j] = temp;
            }
        }
    }
}

void sortbyArrivalTime(Process process_list[], size_t length) {
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            if (process_list[i].arrival_time < process_list[j].arrival_time) {
                Process temp = process_list[i];
                process_list[i] = process_list[j];
                process_list[j] = temp;
            }
        }
    }
}

void sortbyPID(Process process_list[], size_t length) {
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            if (process_list[i].pid < process_list[j].pid) {
                Process temp = process_list[i];
                process_list[i] = process_list[j];
                process_list[j] = temp;
            }
        }
    }
}

int minTime(Process process_list[], size_t length) {
    int min = process_list[0].arrival_time;
    for (int i = 0; i < length; i++) {
        if (process_list[i].arrival_time < min) {
            min = process_list[i].arrival_time;
        }
    } 
    return min;
} 

/**
  bt member variable is just a copy of the burst time member variable.
  It is present so that calculations could be done on it and the orginal
  burst time values could be preserved. And in the end retrieved.
*/
void update_BT_variable(Process process_list[], size_t length) {
    for (int i = 0; i < length; i++) {
        process_list[i].bt = process_list[i].burst_time;
    }
}

void shortest_job_first_algorithm(Process process_list[], size_t length) {
    update_BT_variable(process_list, length); // update the bt member variable with the burst time of each Process

    int timeElapsed = 0;
    int jobs_done = 0;
    int total_turn_around_time = 0;
    int total_waiting_time = 0;

    // find the least arrival and set timeElapsed to it
    timeElapsed = minTime(process_list, length);

    // go through each process, and execute ONLY on meeting all the following conditions:
    //    -> arrival_time <= timeElapsed
    //    -> burst_time > 0
    // keep track of processes completed. once all done, stop the loop
    // keep on sorting the process_list after each execution

    sortbyArrivalTime(process_list, length);
    while (jobs_done != length) {
        for (int i = 0; i < length; i++) {
            if (process_list[i].bt > 0 && process_list[i].arrival_time <= timeElapsed) {
                process_list[i].bt = 0;
                timeElapsed += process_list[i].burst_time;
                process_list[i].completion_time = timeElapsed;
                process_list[i].turn_around_time = timeElapsed - process_list[i].arrival_time;
                process_list[i].waiting_time = process_list[i].turn_around_time - process_list[i].burst_time;
                total_turn_around_time += process_list[i].turn_around_time;
                total_waiting_time += process_list[i].waiting_time;
                jobs_done++;
                break;
            }
        }
        sortByBurstTime(process_list, length);
    }
    sortbyPID(process_list, length); // rearrange the PID to original order
    printTable(process_list, length); // print the table after all the calculations
    
    // calculating the average TAT and WT
    float average_TAT = (float) total_turn_around_time / length;
    float average_WT = (float) total_waiting_time / length;

    // setting the float precision value to 1
    printf("Average Turn Around Time: %1.f Units of Time\n", average_TAT);
    printf("Average Waiting Time: %1.f Units of Time\n", average_WT);
}

int main() {
    size_t length = 5;
    Process process_list[] = {
        {.pid = 1, .arrival_time = 1, .burst_time = 7},
        {.pid = 2, .arrival_time = 2, .burst_time = 5},
        {.pid = 3, .arrival_time = 3, .burst_time = 1},
        {.pid = 4, .arrival_time = 4, .burst_time = 2},
        {.pid = 5, .arrival_time = 5, .burst_time = 8}
    };
    printf("Number of Processes: %ld\n", length);
    shortest_job_first_algorithm(process_list, length);
}
