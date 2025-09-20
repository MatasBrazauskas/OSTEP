#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
    const int Cn = 10000000;
    const char *fileName = "./temp.txt"; 
    struct timeval startTime, endTime;

    int fd = open(fileName, O_RDONLY);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    char singleByte;
    
    gettimeofday(&startTime, NULL);

    for (size_t i = 0; i < Cn; i++) {
        int ret = read(fd, &singleByte, 0);
        if (ret < 0) {
            perror("read");
            close(fd);
            return 1;
        }
    }
    
    gettimeofday(&endTime, NULL);
    printf("%d\n", fd);
    close(fd);

    long seconds = endTime.tv_sec - startTime.tv_sec;
    long useconds = endTime.tv_usec - startTime.tv_usec;
    long totalMicro = seconds * 1000000 + useconds;

    printf("%ld microseconds passed for %d system calls.\n", totalMicro, Cn);
    printf("Average per syscall: %.2f ns\n",
           (double)totalMicro * 1000.0 / Cn);

    return 0;
}