#include <stdio.h>

shortest_remaining_job(int*, int*, size_t);

int main() {
    int pid[] = {1, 2, 3};
    int arrival_time[] = {0, 1, 2};
    int burst_time[] = {4, 2, 1};
    size_t length = *(&burst_time + 1) - burst_time;
    printf("Number of Processes is: %ld\n", length);
    shortest_remaining_job(arrival_time, burst_time);
}

shortest_remaining_job(int arrival_time[], int burst_time[], size_t length) {
    int time = 0;
    int jobsDone = 0;
    while (time++ <= length) {
        int minBurstTimeIndex = findMinBurstTimeIndex(burst_time, length);
        burst_time[minBurstTimeIndex]--;
        if (burst_time[minBurstTimeIndex] <= 0) {
            jobsDone++;
        }
        
    }
}