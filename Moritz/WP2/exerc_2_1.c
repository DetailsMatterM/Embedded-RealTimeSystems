#include <stdio.h>
#include <string.h>

#define MAX 20

void copyString(char input [], char output []);

int main() {
    char textSource [MAX];
    char textCopy [MAX];
    scanf("%s", textSource);
    //strcpy(textCopy, textSource);
    copyString(textSource, textCopy);
    
    printf("\n%s", textCopy);
}

void copyString(char input [], char output []){
    int i = 0;
    while(i < MAX) {
        output[i] = input[i];
        i++;
    }
    i++;
}