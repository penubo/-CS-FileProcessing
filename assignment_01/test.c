#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {

    int fd = open(argv[1], O_RDWR);
    int cnt = 0;

    char buf[10];

    int final = lseek(fd, 0, SEEK_END);
    int start = lseek(fd, 0, SEEK_SET);

    printf("%d\n", final);
    printf("%d\n", start);

    while (1) {
        lseek(fd, 10, SEEK_CUR);
        read(fd, buf, 10);
        if(lseek(fd, 0, SEEK_CUR) == final)
            break;
        printf("%s\n", buf);
        printf("%ld\n", lseek(fd, -10, SEEK_CUR));
    }

    return 0;
}
