#include <sys/time.h>
#include <stdio.h>

double getTimeMs();

int main() {
    double time = getTimeMs();
    printf("%f", time);

}

double getTimeMs(){
struct timeval t;
gettimeofday(&t, NULL);

return (t.tv_sec + (t.tv_usec / 1000000.0)) * 1000.0;
}