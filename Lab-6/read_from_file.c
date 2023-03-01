/* Read the first 10 characters from a file */
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    char save_file_data_here[50];
    char* filename = "new_file.txt";
    int fd_file = open(filename, O_RDONLY | O_CREAT); // if the file does not exist then create it using O_CREAT()
    int fd_screen = 1;
    int size_to_read = 10;
    if (fd_file < 0) {
        printf("There was an error opening OR creating the file.");
        return 0;
    }
    read(fd_file, save_file_data_here, size_to_read);
    write(fd_screen, save_file_data_here, size_to_read);
    write(fd_screen, "\n", 1);
}
