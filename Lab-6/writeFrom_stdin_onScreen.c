/* Read from standard input and write it on screen using system calls */
#include <stdio.h>
#include <unistd.h>

int main() {
    char input_data[50];
    int fd_stdin = 0;
    int fd_screen = 1;
    int size_to_read = 11;
    read(fd_stdin, input_data, size_to_read);
    write(fd_screen, input_data, size_to_read);
    write(fd_screen, "\n", 1);
}
