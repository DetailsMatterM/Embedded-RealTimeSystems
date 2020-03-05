#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>

int programTime = 0;

double getTimeS();
void *runner(void *param);
void *readInport(void *param);
int printCheck = 0;
int printCheckRead = 0;

int main() {
    pthread_t time;
    pthread_t readOutput;
    pthread_attr_t attr;

    pthread_attr_init(&attr);
    pthread_create(&time, &attr, runner, NULL);
    pthread_create(&readOutput, &attr, readInport, NULL); 

    double startTime = programTime;
  
    while (programTime < 50) {
        if (printCheck == 0 && programTime == startTime + 5) {
            startTime = programTime;
            printf("Time %d\n", programTime);
            printCheck = 1;
            printCheckRead = 0;
        }
    }
    return 0;
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
    while (programTime < 50) {
        if (programTime > 0 && printCheckRead == 0 && programTime % 5 == 0) {
            printf("Reading Inport now\n");
            printCheckRead = 1;
            printCheck = 0;
        }
    }
    pthread_exit(0);
}