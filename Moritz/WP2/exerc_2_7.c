#include <stdio.h>

#define LENGTH 11
void readPersnr(char *person);
int convert(char *person, int i);
int controlDigit(const char *persnr);

int main() {
    char number [LENGTH];
    char *person = number;

    fgets(number, LENGTH, stdin);
    readPersnr(person);
    return 0;
}


void readPersnr(char *person) {
    int year, month, day, number;
    year = convert(person, 0);
    month = convert(person, 2);
    day = convert(person,4);
    number = convert(person,9);

    printf("%d", year);
    printf("\n%d", month);
    printf("\n%d", day);
    printf("\n%d", number);
    const char *persnr = person;
    int checker = controlDigit(persnr);
}

int controlDigit(const char *persnr) {
    int year, month, day, number;
    year = convert(persnr, 0);
    month = convert(persnr, 2);
    day = convert(persnr,4);
    number = convert(persnr,9);
    
}

int convert(char *person, int in) {
    int result = 0;
    char raw [2];
    int counter = 0;
    while(counter < in) {
        person++;
        counter++;
    }
    for (int i = 0; i < 2; i++) {
        raw[i] = *person;
        person++;
    }

    sscanf(raw, "%d", &result);
    return result;
}