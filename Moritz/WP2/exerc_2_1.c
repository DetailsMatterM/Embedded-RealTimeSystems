#include <stdio.h>
#include <string.h>

#define MAX 21

void copyString(char * input, char * output);

int main(char textToCopy [20]) {
    fflush(stdin);
    char textSource [MAX];
    char textCopy [MAX];
    char textCopyCustom [MAX];
    char * dest = &textCopy;
    char * src = &textSource;
    char * dest2 = &textCopyCustom;
    fgets(textSource, MAX, stdin);
    strcpy(dest, src);

    puts("\nThis is the copied string using strcpy:");
    printf("\n%s", textCopy);
    puts("\n==========================================");


    puts("\nThis is the copied string using copyString:");
    copyString(src, dest2);
    printf("\n%s", textCopyCustom);

}

//improve (since int byte is bigger than char byte)
void copyString(char * input, char * output){
    while(*input != '\0'){
        *output++ = *input++;
    }
    *output = '\0';
}
