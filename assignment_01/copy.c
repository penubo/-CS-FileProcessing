#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("you must indicate <exe_file> <src_file> <des_file>");
        return 0;
    }

    char* src_file = argv[1];
    char* des_file = argv[2];
    char data[101];
    memset(data, '\0', sizeof(data));

    int src_fd = 0; /* file descriptor */
    int des_fd = 0;

    src_fd = open(src_file, O_RDONLY);

    if (src_fd < 0) {
        printf("There is no <src_file>: %s\n", src_file);
        return 0;
    }

    des_fd = open(des_file, O_WRONLY | O_CREAT, 0751);

    while(read(src_fd, data, 100) > 0) {
        write(des_fd, data, 100);
    }
    
    close(src_fd);
    close(des_fd);

    return 0;
}