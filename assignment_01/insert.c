#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {

    if (argc != 4) {
        fprintf(stderr, "you must comment <exe_file> <des_file> <offset> <data>\n");
        return -1;
    }

    if (strlen(argv[3]) != 10) {
        fprintf(stderr, "data must be 10bytes long.\n");
        return -1;
    }

    char* des_file = argv[1];
    int offset = atoi(argv[2]);
    char* data = argv[3];
    char buf_1[255];
    int fd = 0;
    int pivot = 0;
    int final = 0;

    memset(buf_1, '\0', sizeof(buf_1));

    if ((fd = open(des_file, O_RDWR)) < 0) {
        fprintf(stderr, "<des_file> open error.\n");
        return -1;
    }

    if ((pivot = lseek(fd, offset, SEEK_SET)) < 0) {
        fprintf(stderr, "seeking error.\n");
        return -1;
    }

    if (read(fd, buf_1, offset) < 0) {
        fprintf(stderr, "seeking error.\n");
        return -1;
    }

    lseek(fd, pivot, SEEK_SET);
    write(fd, data, 10);
    write(fd, buf_1, strlen(buf_1));

    close(fd);
        
    return 0;

}
