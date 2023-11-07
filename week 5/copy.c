#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_file> <destination_file>\n", argv[0]);
        exit(1);
    }

    int source_fd, dest_fd;
    ssize_t nread;
    char buffer[BUFFER_SIZE];

    source_fd = open(argv[1], O_RDONLY);
    if (source_fd == -1) {
        perror("Failed to open source file");
        exit(2);
    }

    dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd == -1) {
        perror("Failed to open destination file");
        close(source_fd);
        exit(3);
    }

    while ((nread = read(source_fd, buffer, BUFFER_SIZE)) > 0) {
        if (write(dest_fd, buffer, nread) != nread) {
            perror("Write error");
            close(source_fd);
            close(dest_fd);
            exit(4);
        }
    }

    if (nread < 0) {
        perror("Read error");
        close(source_fd);
        close(dest_fd);
        exit(5);
    }

    close(source_fd);
    close(dest_fd);

    printf("File copied successfully from %s to %s\n", argv[1], argv[2]);

    return 0;
}
