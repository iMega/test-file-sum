#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char **argv)
{
    int f, i;
    ssize_t readed;

    unsigned char result = 0;
    unsigned char buf[BUF_SIZE] = {0};

    if (argc != 2) {
        fprintf(stderr, "Usage: %s \n", argv[0]);
        exit(-1);
    }

    f = open(argv[1], O_RDONLY);

    if (f == -1) {
        perror("Could not open a file");
    }

    while ((readed = read(f, buf, sizeof(buf))) > 0) {
        for (i=0; i < readed; i++) {
            result += buf[i];
        }
    }

    close(f);

    printf("Reading is done %u \n", result);

    return 0;
}