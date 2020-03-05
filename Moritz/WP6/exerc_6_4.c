#include <sys/time.h>
#include <stdio.h>
#include <pthread.h>

int program_time;

double getTimeS();

int main() {
    pthread_t time;
    pthread_t readOutput;
    pthread_attr_t attr;

    pthread_attr_init(&attr);
    pthread_create(&time, &attr, runner, NULL);
    pthread_create(&readOutput, &attr, )
    for (int i = 0; i < 300; i++) {
        double time = getTimeS();
        printf("_______________________\n");
        printf("%f\n", time);
    }
    

}

double getTimeS(){
struct timeval t;
gettimeofday(&t, NULL);

return t.tv_sec;
}

void *runner(void *param) {
    while (program_time < 50) {

    }
}