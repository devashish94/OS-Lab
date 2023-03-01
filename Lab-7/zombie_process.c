/* Program to implement zombie process */
#include <stdio.h>
#include <unistd.h>

int main() {
    int child = fork();
    if (child == 0) {
        printf("i am child");
        return 0;
    } else {
        sleep(50);
        printf("i am parent\n");
    }
}
