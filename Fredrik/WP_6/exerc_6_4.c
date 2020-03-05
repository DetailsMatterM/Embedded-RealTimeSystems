#include <sys/time.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
int program_time = 0; // The global time, start value 0

void *time_count(void *param);
void *read_inport(void *param);
double get_time_ms();

int main()
{

    pthread_t tid1;
    pthread_t tid2;

    pthread_attr_t attr;
    pthread_attr_init(&attr);

    // Start up the thread time_count.
    pthread_create(&tid1, &attr, time_count, NULL);
    pthread_join(tid1, NULL);

    // Start up the thread read_inport.
    pthread_create(&tid2, &attr, read_inport, NULL);
    pthread_join(tid2, NULL);

    while (program_time < 50)
    {
        //print system time every second
    }
}

void *time_count(void *param)
{
    double originTime = get_time_ms();

    while (program_time < 50)
    {

        printf(" origin time : %f time is : %f and program counter is at %d\n", originTime, get_time_ms(), program_time);

        program_time += 1;
        // Check system-time ( get_time_ms())
        // Increase program_time by one every second.
    }
    //  printf("%f time count \n", get_time_ms());

    pthread_exit(0);
}
void *read_inport(void *param)
{
    while (program_time < 50)
    {
        get_time_ms();
        program_time += 1;
        // Read Inport every 5 second.( Simulate
        //this just by print out a text : Reading Inport now)
    }
    //  printf("%f read inport\n", get_time_ms());
    pthread_exit(0);
}

// --------Function get_time_ms --------------------
double get_time_ms()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    double result = (t.tv_sec + (t.tv_usec / 1000000.0)) * 1000.0;
    return result;
}