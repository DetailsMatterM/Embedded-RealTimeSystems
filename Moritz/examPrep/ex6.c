// ---- Program exam_exerc_6.c----------------
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define num_elems 200
int array[200];
int max_value=200;
void *runner(void *param);
void *runner2(void *param);
int main() {
    pthread_t tid1, tid2;
    pthread_attr_t attr1, attr2;
    pthread_attr_init(&attr1);
    pthread_create(&tid1, &attr1, runner, NULL);
    pthread_join(tid1, NULL);
    pthread_attr_init(&attr2);
    pthread_create(&tid2, &attr2, runner2, NULL);
    pthread_join(tid2, NULL);
    for( int n=0; n<max_value; n++){
		printf("\n Number = %d is %d ", n,array[n]);
	}
	return 0;
}

void *runner(void *param) {
    printf("Executing runner 1\n");
    int c = 0;
    for (c = 0; c < num_elems; c++) {
        array[c] = rand() % max_value;
    }
    pthread_exit(0);
}
void *runner2(void *param) {
	int c, d, swap;
	for (c = 0; c < num_elems; c++) {
		for (d = 0; d < num_elems - c - 1; d++) {
			if (array[d] > array[d + 1]) {
                swap = array[d];
                array[d] = array[d + 1];
                array[d + 1] = swap;
            }
        }
    }
    pthread_exit(0);
}