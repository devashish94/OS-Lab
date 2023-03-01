/* Program to implement orphan process */
#include <stdio.h>
#include <unistd.h>

int main() {
    int child = fork();
    if (child == 0) {
        sleep(5);
        printf("i am child\n");
    } else {
        printf("i am parent\n");
        return 0;
    }
}
