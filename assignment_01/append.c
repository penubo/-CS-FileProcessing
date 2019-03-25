#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[]) {

    if (argc != 3) {

        return -1;
    }

    if (strlen(argv[2]) != 10) {
        fprintf(stderr, "data should be 10bytes long.\n");
        return -1;
    }

    char* des_file = argv[1];
    char* data = argv[2];
    int fd = 0;

    if ((fd = open(des_file, O_WRONLY | O_APPEND)) < 0) {
        fprintf(stderr, "<des_file> error.\n");
        return -1;
    }

    lseek(fd, -1, SEEK_END);

    if ((write(fd, data, 10)) != 10) {
        fprintf(stderr, "append error. \n");
        return -1;
    }

    close(fd);

    return 0;
}
