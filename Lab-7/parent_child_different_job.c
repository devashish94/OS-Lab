/* Program to assign different tasks to parent and child processes */
#include <stdio.h>
#include <unistd.h>

int main() {
    int child = fork();
    if (child == 0) {
        /* first 10 multiples of 5 in child process */
        for (int i = 1; i <= 10; i++) {
            printf("%d ", i * 5);
        }
        printf("\n");
    } else {
        sleep(0.5);
        /* first 10 multiples of 2 in child process */
        for (int i = 1; i <= 10; i++) {
            printf("%d ", i * 2);
        }
        printf("\n");
    }
}
