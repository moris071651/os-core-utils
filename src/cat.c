#include "cat.h"

#include <string.h>

#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 1024

void print_error(const char *msg) {
    write(2, msg, strlen(msg));
}

int mycore_cat_main(int argc, char *argv[]) {
    if (argc < 2) {
        print_error("Usage: mycore cat <file1> <file2> ...\n");
        return 1;
    }

    char buf[BUF_SIZE];
    int fd;
    ssize_t bytes_read, bytes_written;

    for (int i = 1; i < argc; i++) {
        fd = open(argv[i], O_RDONLY);
        if (fd == -1) {
            print_error("Error opening file: ");
            print_error(argv[i]);
            print_error("\n");
            continue;
        }

        while ((bytes_read = read(fd, buf, BUF_SIZE)) > 0) {
            bytes_written = write(1, buf, bytes_read);
            if (bytes_written == -1) {
                print_error("Error writing to stdout\n");
                close(fd);
                return 1;
            }
        }

        if (bytes_read == -1) {
            print_error("Error reading file: ");
            print_error(argv[i]);
            print_error("\n");
        }

        close(fd);
    }

    return 0;
}
