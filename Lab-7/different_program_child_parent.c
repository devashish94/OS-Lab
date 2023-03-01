#include <stdio.h>
#include <unistd.h>

int main() {
    int child = fork();
    if (child == 0) {
        sleep(5);
        printf("i am child\n");
    } else {
        // sleep(1);
        printf("i am parent\n");
        return 0;
    }
}
