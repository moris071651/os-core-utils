#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>

int list_directory(const char* path) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        write(1, entry->d_name, strlen(entry->d_name));
        write(1, "\n", strlen("\n"));
    }

    closedir(dir);
    
    return EXIT_SUCCESS;
}

int mycore_ls_main(int argc, char *argv[]) {
    if (argc == 1) {
        return list_directory(".");
    } else {
        for (int i = 1; i < argc; i++) {
            int ret = list_directory(argv[i]);
            if (ret != EXIT_SUCCESS) {
                return ret;
            }
        }
    }

    return EXIT_SUCCESS;
}
