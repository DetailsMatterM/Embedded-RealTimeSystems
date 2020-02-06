#include <stdio.h>
#include <string.h>

#define MAX 20

int main() {
    char palStr[MAX];
    char revPalStr[MAX];

    printf("Please input a word: \n");
    gets(palStr);

    strcpy(revPalStr, palStr);          //Copy string
    strrev(revPalStr);                  //Reverse string

    if (strcmp(palStr, revPalStr) != 0) {
        printf("\n%s : This word is no palindrome", palStr);
    } else
    {
        printf("\n%s : This word is a palindrome", palStr);
    }
    
    return 0;
}