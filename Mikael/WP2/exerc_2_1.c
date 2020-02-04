#include <stdio.h>
#include <string.h>

#define MAX 20

int main(){
   
    char str[MAX];
    char *ptr = str;

    puts("Enter a string of max 20 char: \n");
    gets(str);
    printf("Your string:  %s\n", str);

    libraryCopy(str); // Copy string through library
    
    copyString(str); //Copy string with my own function

    readTextFile(); // Read from text file



    return 0;
}

// Own function to copy string
void copyString(char *str){

    int i = 0;
    char tempStr[MAX];
    while (str[i] != '\0') {
        tempStr[i] = str[i];
        i++;
    }
    tempStr [i] = '\0';

    printf("My own copy:  %s \n", tempStr);
}

// Library function to copy string
void libraryCopy(str){

    char copiedStr[MAX];
    strcpy(copiedStr, str);

    printf("Libary Copy:  %s\n", copiedStr );
}

// Function to read a string from a file
int readTextFile(){
    FILE *fp;

    char fileStr[MAX];
    char* filename = "C:\\Users\\michi\\Embedded-RealTimeSystems\\Mikael\\WP2\\cheekytext.txt";

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Could not open file %s", filename);
        return 1;
    }
    while (fgets(fileStr, MAX, fp) != NULL)
    {
        printf("Text read from file:  %s \n", fileStr);
        fclose(fp);
    }
}