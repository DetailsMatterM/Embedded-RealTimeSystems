#include <sys/time.h>
#include <stdio.h>

double getTimeMs();

int main() {
    double time = getTimeMs();
    printf("%f", time);
    for(int i = 0; i < 300; i++) {
        time = getTimeMs();
        printf("_______________________\n");
        printf("%f\n", time);
    }


}

double getTimeMs(){
struct timeval t;
gettimeofday(&t, NULL);

return t.tv_sec;
} 