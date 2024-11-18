#include "dump.h"

#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <fcntl.h>

int mycore_dump_main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "You have to specify numbers\n");
        return EXIT_FAILURE;
    }

    int fd = open(argv[1], O_CREAT | O_WRONLY, 0666);
    if (fd == -1) {
        perror("open()");
        return EXIT_FAILURE;
    }

    for (int i = 2; i < argc; i++) {
        char* error = NULL;
        int num = strtol(argv[i], &error, 10);
        if (*error != '\0') {
            fprintf(stderr, "Invalid Number\n");
            continue;
        }

        if (write(fd, &num, sizeof(num)) == -1) {
            perror("write()");
            return EXIT_FAILURE;
        }
    }

    close(fd);

    return EXIT_SUCCESS;
}