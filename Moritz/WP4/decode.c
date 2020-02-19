#include <stdio.h>
#include <stdlib.h>

int getnum(char c) {
    switch (c) {
    case 'A':
    case 'a':
        return 10;
    case 'B':
    case 'b':
        return 11;
    case 'C':
    case 'c':
        return 12;
    case 'D':
    case 'd':
        return 13;
    case 'E':
    case 'e':
        return 14;
    case 'F':
    case 'f':
        return 15;
    default:
        return atoi(&c);
    }
}

int main (int argc, char *argv[]) {
    if (argc != 2) {
        printf("Type : exerc_4_1.exe engine_on parameter, gear_pos parameter, key_pos parameter, brake 2 parameter and brake1 parameter\n");
    } else {
        int left = getnum(argv[1][0]);
        int right = getnum(argv[1][1]);
        unsigned char final = (unsigned char)((left << 4) ^ right);
        
        printf("\n");
        for (int i = 7; 0 <= i; i--) {
            printf("%c", (final & (1 << i)) ? '1' : '0');
        }
        return 0; 
    }
}
    