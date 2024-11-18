#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "cat.h"
#include "ls.h"
#include "dump.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <command>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (!strcmp(argv[1], "cat")) {
        return mycore_cat_main(argc - 1, argv + 1);
    }
    else if (strcmp(argv[1], "ls") == 0) {
        return mycore_ls_main(argc - 1, argv + 1);
    }
    else if (strcmp(argv[1], "dump") == 0) {
        return mycore_dump_main(argc - 1, argv + 1);
    }
    else {
        fprintf(stderr, "Unknown command: %s\n", argv[1]);
        return EXIT_FAILURE;
    }
}
