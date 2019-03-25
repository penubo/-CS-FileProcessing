#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char* argv[]) {

    if (argc != 4) {
        fprintf(stderr, "you must command <exe_file> <des_file> <offset> <data>\n");
        return -1;
    }

    if (strlen(argv[3]) != 10) {
        fprintf(stderr, "data must be 10 bytes long\n");
        return -1;
    }

    char* des_file = argv[1];
    int offset = atoi(argv[2]);
    char* data = argv[3];
    int fd = 0;

    if ((fd = open(des_file, O_WRONLY)) < 0) {
        fprintf(stderr, "<des_file> open error.\n");
        return -1;
    }

    if (lseek(fd, offset, SEEK_SET) < 0) {
        fprintf(stderr, "<des_file> open error.\n");
        return -1;
    }

    if (write(fd, data, 10) != 10) {
        fprintf(stderr, "<des_file> open error.\n");
        return -1;
    }

    close(fd);

    return 0;
}
