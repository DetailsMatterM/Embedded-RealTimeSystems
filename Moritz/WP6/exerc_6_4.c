#include <sys/time.h>
#include <stdio.h>

double getTimeMs();

int main() {
    for(int i = 0; i < 300; i++) {
        double time = getTimeMs();
        printf("_______________________\n");
        printf("%f\n", time);
    }
    

}

double getTimeMs(){
struct timeval t;
gettimeofday(&t, NULL);

return (t.tv_sec + (t.tv_usec / 1000000.0)) * 1000.0;
}