/* ====================================
File name: exerc_2_1.c 
Date: 2020-02-06
Group nr 7
Members that contribute to the solutions
Fredrik Ullman
Mikael Köse Jansson
Moritz Denke

Demonstration code: [40366] Important , No code no exercise points !
====================================== */
#include <stdio.h>
#include <string.h>

#define MAX 21

void copyString(char * input, char * output);

int main() {
    char textSource [MAX];
    char textCopy [MAX];
    char textCopyCustom [MAX];
    char *dest = textCopy;
    char *src = textSource;
    char *dest2 = textCopyCustom;
    fgets(textSource, MAX, stdin);
    strcpy(dest, src);

    puts("\nThis is the copied string using strcpy:");
    printf("\n%s", textCopy);
    puts("\n==========================================");

    puts("\nThis is the copied string using copyString:");
    copyString(src, dest2);
    printf("\n%s", textCopyCustom);
}

void copyString(char *input, char *output){
    while(*input != '\0'){
        *output++ = *input++;
    }
    *output = '\0';
}
