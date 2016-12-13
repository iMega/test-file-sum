#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <tmmintrin.h>

#define BUF_SIZE 1024

int main(int argc, char **argv)
{
    int f, i;
    ssize_t readed;
    __m128i r  = _mm_set1_epi8(0);

    unsigned char result = 0;
    unsigned char buf[BUF_SIZE] __attribute__ ((aligned (16))) = {0};

    if (argc != 2) {
        fprintf(stderr, "Usage: %s \n", argv[0]);
        exit(-1);
    }

    f = open(argv[1], O_RDONLY);

    if (f == -1) {
        perror("Could not open a file");
    }

    while ((readed = read(f, buf, sizeof(buf))) > 0) {
        for (i=0; i < readed; i+=16) {
            __m128i a = _mm_load_si128((const __m128i *)(buf+i));
            r = _mm_add_epi8(a, r);
        }
        memset(buf, 0, sizeof(buf));
    }

    for (i=0; i<16; i++) {
        result += ((unsigned char *)&r)[i];
    }

    close(f);

    printf("Reading is done %u \n", result);

    return 0;
}
