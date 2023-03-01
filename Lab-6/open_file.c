/* Implement a simple system call. Here Used the open() system call */
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    char* filename = "new_file.txt";
    int fd = open(filename, O_RDONLY | O_CREAT);
}
