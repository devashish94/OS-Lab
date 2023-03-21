/* Write a program in C to implement First Come First Serve CPU Scheduling Algorithm */
#include <stdio.h>

void calculation(int* process_id, int* arrival_time, int* burst_time, int length) {
    printf("Number of Processes: %d\n", length);

    int total_turn_around_time = 0;
    int total_waiting_time = 0;
    int completion_time[length];
    int turn_around_time[length];
    int waiting_time[length];

    completion_time[0] = burst_time[0];
    turn_around_time[0] = burst_time[0];
    waiting_time[0] = 0;

    /* Filling all the three Arrays using a single loop. Could have not used even a single array. */
    for (int i = 0; i < length; i++) {
        if (i > 0) {
            completion_time[i] = burst_time[i] + completion_time[i - 1]; // prefix sum
            turn_around_time[i] = completion_time[i] - arrival_time[i];
            waiting_time[i] = turn_around_time[i] - burst_time[i];
        }
        total_turn_around_time += turn_around_time[i];
        total_waiting_time += waiting_time[i];

        /* Printing all the values in a tabular form */
        printf(
            "PID: %d\tAT:%d\tBT:%d\tCT:%d\tTAT:%d\tBT:%d\n",
            i,
            arrival_time[i], 
            burst_time[i], 
            completion_time[i],
            turn_around_time[i],
            waiting_time[i]
        );
    }

    /* Calculating the Averages of Both of TAT and WT */
    float average_TAT = (float) total_turn_around_time / length;
    float average_WT = (float) total_waiting_time / length;

    /* Setting the Float value precision to 1 */
    printf("Average Turn Around Time: %.1f Units of Time\n", average_TAT);
    printf("Average Waiting Time: %.1f Units of Time\n", average_WT);
}

int main() {
    int process_id[] = {0, 1, 2}; // this array should be in increasing order
    int arrival_time[] = {0, 1, 2};
    int burst_time[] = {3, 2, 1};
    int length = *(&burst_time + 1) - burst_time; // length of array using pointer arithmetic
    calculation(process_id, arrival_time, burst_time, length);
}
