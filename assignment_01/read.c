#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {

    if (argc != 3) {
        printf("you must command <exe_file> <src_file> <offset>\n");
        return -1;
    }

    char buffer[10];
    char* src_file = argv[1];
    int offset = atoi(argv[2]);
   
    int fd = 0;

    memset(buffer, '\0', sizeof(buffer));

    if ((fd = open(src_file, O_RDONLY)) < 0) {
        fprintf(stderr, "<src_file> error\n");
        return -1;
    }

    if (lseek(fd, offset, SEEK_SET) < 0) {
        fprintf(stderr, "<offset> error\n");
        return -1;
    }

    if (read(fd, buffer, 10) != 10) {
        fprintf(stderr, "read error\n");
        return -1;
    }

    close(fd);

    printf("%s\n", buffer);

    return 0;
}
