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
    char buf_1[10], buf_2[10];
    int fd = 0;

    int final = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);

    if ((fd = open(des_file, O_RDWR)) < 0) {
        fprintf(stderr, "<des_file> open error.\n");
        return -1;
    }

    if (lseek(fd, offset, SEEK_SET) < 0) {
        fprintf(stderr, "seeking error.\n");
        return -1;
    }

    read(fd, buf_1, 10);
    lseek(fd, -10, SEEK_CUR);
    write(fd, data, 10);
    lseek(fd, -1, SEEK_CUR);

    while(1) {

        strncpy(buf_2, buf_1, 10);
        read(fd, buf_1, 10);
        lseek(fd, -10, SEEK_CUR);
        write(fd, buf_2, 10);
        lseek(fd, -1, SEEK_CUR);
        if (lseek(fd, 0, SEEK_CUR) >= final)
            break;
        printf("%s\n", buf_2);
    }

    close(fd);
        
    return 0;

}
