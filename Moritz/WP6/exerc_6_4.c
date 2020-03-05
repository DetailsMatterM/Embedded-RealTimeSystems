#include <sys/time.h>
#include <stdio.h>
#include <pthread.h>

int programTime;

double getTimeS();
void *runner(void *param);

int main() {
    pthread_t time;
    pthread_t readOutput;
    pthread_attr_t attr;

    pthread_attr_init(&attr);
    pthread_create(&time, &attr, runner, NULL);
    pthread_create(&readOutput, &attr, readInport, NULL); 

}

double getTimeS() {
struct timeval t;
gettimeofday(&t, NULL);

return t.tv_sec;
}

void *runner(void *param) {
    double startTime = getTimeS();
    while (programTime < 50) {
        double compTime = getTimeS();
        if (compTime == startTime + 1) {
            programTime++;
            startTime = compTime;
        }
    }
    pthread_exit(0);
}

void *readInport(void *param) {
    double starTime = programTime;
    while (programTime < 50) {
        if (programTime == starTime + 5) {
            printf("Reading Inport now");
        }
    }
    pthread_exit(0);
}