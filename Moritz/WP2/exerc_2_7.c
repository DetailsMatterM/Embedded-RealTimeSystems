#include <stdio.h>

#define LENGTH 11
void readPersnr(char *person);
int convert(char *person, int i, int span);
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

    printf("%d", year);
    printf("\n%d", month);
    printf("\n%d", day);
    printf("\n%d", number);
    const char *persnr = person;
    int checker = controlDigit(persnr);
}

int controlDigit(const char *persnr) {
    int part, part2, a, b, checksum;
    for (int i = 0; i < 10; i++) {
        int part = convert(persnr, i, 1);
        if (i % 2 == 0) {
            part = part * 2;
            if (part >= 10) {
                a = part % 10;
                b = part/10;
                part = a + b;
            }
            
        }
    }

//    year = convert(persnr, 0);
//    month = convert(persnr, 2);
//    day = convert(persnr,4);
//    number = convert(persnr,9);

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