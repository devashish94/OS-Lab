#include <stdio.h>

int calculate_avg_waiting_time(processes, burst_time);
int calculate_avg_turn_around_time(processes, burst_time);

int main() {
    int processes[] = {1, 2, 3};
    int burst_time[] = {3, 2, 1};
    int average_waiting_time = calculate_avg_waiting_time(processes, burst_time);
    int average_turn_around_time = calculate_avg_turn_around_time(processes, burst_time);
    printf("Average Waiting Time: %d", average_waiting_time);
    printf("Average Turn Around Time: %d", average_turn_around_time);
}
