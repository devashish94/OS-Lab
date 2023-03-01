/* Duplicate the fd of a file defined by the user */
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    char* filename = "new_file.txt";
    int file_fd = open(filename, O_RDONLY | O_CREAT);
    printf("fd of file is: %d\n", file_fd);
    int duplicate_fd = dup2(file_fd, 9);
    printf("duplicate fd of the given file: %d\n", duplicate_fd);
}
