#include <stdio.h>

#define MAX 5

void initQue(int list[], int max);
int input(int list[], int number, int max);
int output(int list [], int max);
int main() {
    int que [MAX];
    initQue(que, MAX);
    int a = input(que, 2, MAX); //TEST
    printf("\n%d", a); //TEST
    a = input(que, 2, MAX); //TEST
    printf("\n%d", a); //TEST
    
    int b = output(que, MAX);
     for(int z = 0; z < MAX; z++) { //TEST
        printf("\n Frequency: %d", que[z]);
    }
    printf("\n%d", b); //TEST
    return 0;
}

void initQue(int list [], int max) {
    for(int i = 0; i < max; i++) {
        list [i] = -1;
    }
}

int input(int list [], int number, int max) {
    for(int i = 0; i < max; i++) {
        if(list[i] == -1) {
            list[i] = number;
            return 1;
        }
    }
    return 0;
}

int output(int list [], int max) {
    int i = 0;
    int result;
    if(list[i] != -1) {
        result = list[i];
        for(i; i < max; i++) {
            if(i != (max - 1)){
                list[i] = list [i + 1];
            } else {
                list[i] = -1;
            }
        }
        return result;
    } else {
        return 0;
    }
}