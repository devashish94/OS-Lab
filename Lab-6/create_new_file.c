#include <stdio.h>
#include <fcntl.h>

int main() {
    char* filename = "new_file.txt";
    int fd = open(filename, O_CREAT, S_IRWXU);
}
