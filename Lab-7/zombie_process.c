/* Program to implement zombie process */
#include <stdio.h>
#include <unistd.h>

int main() {
    int child = fork();
    if (child == 0) {
        printf("i am child\n");
        return 0;
    } else {
        sleep(5);
        execl("/bin/ps", "ps", NULL);
        printf("i am parent\n");
    }
}
