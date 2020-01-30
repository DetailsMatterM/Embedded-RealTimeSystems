#include <stdio.h>

#define LENGTH 11
void readPersnr(char *person);
int convert(char *person, int i, int span);
int controlDigit(const char *persnr);
int flag = 0;

int main() {
    char number [LENGTH];
    char *person = number;

    while (flag != 1) {
        printf("\n%s", "Please enter a 10-digit person number or q to end the program\n");
        fgets(number, LENGTH, stdin);
        if(*person == 'q'){
            flag = 1;
        }
        getchar();
        readPersnr(person);
    }

    return 0;
}


void readPersnr(char *person) {
    int year, month, day, number;
    if (*person == 'q') {
        flag = 1;
        return;
    }
    year = convert(person, 0, 2);
    if (year <= 99){
        month = convert(person, 2, 2);
    } else {
        printf("\n%s", "Year invalid");
        return;
    }
    if (month >= 1 && month <= 12) {
        day = convert(person,4, 2);
    } else {
        printf("\n%s", "Month invalid");
        return;
    }
    if (day >= 1 && day <= 31) {
        number = convert(person,9,1);
    } else {
        printf("\n%s", "Day invalid");
        return;
    }
    const char *persnr = person;
    int checker = controlDigit(persnr);
    if (checker == number) {
        printf("\n%s", "The person number is valid");
    } else {
        printf("\n%s", "The person number is not valid");
    }
}

int controlDigit(const char *persnr) {
    int part, a, b;
    int checksum = 0;
    for (int i = 0; i < 9; i++) {
        part = convert(persnr, i, 1);
        if (i % 2 == 0) {
            part = part * 2;
            if (part >= 10) {
                a = part/10;
                b = part % 10;
                part = a + b;
            }
        }
        checksum += part;
    }
    a = checksum % 10;
    b = 10 - a;
    if (b != 10){
        checksum = b;
    } else {
        checksum = 0;
    }
    return checksum;
}

int convert(char *person, int in, int span) {
    int result = 0;
    char raw [span];
    int counter = 0;
    while(counter < in) {
        person++;
        counter++;
    }
    for (int i = 0; i < span; i++) {
        raw[i] = *person;
        person++;
    }
    sscanf(raw, "%d", &result);
    return result;
}