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
        int final = ((left << 4) ^ right);

        int engine_on = (final >> 7) & 0x01;
        int gear_pos  = (final >> 4) & 0x07;
        int key_pos   = (final >> 2) & 0x03;
        int brake1    = (final >> 1) & 0x01;
        int brake2    = (final)      & 0x01;

        printf("Name          Value \n");
        printf("------------------- \n");
        printf("engine_on     %d \n", engine_on);
        printf("gear_pos      %d \n", gear_pos);
        printf("key_pos       %d \n", key_pos);
        printf("brake1        %d \n", brake1);
        printf("brake2        %d \n", brake2);
        // 0000 0001 = 1  = 0x01
        // 0000 0011 = 3  = 0x03
        // 0000 0111 = 7  = 0x07
        // 0000 1111 = 15 = 0x0F
        
        //printf("%d", engine_on);
        // unsigned char final = (unsigned char)((left << 4) ^ right);
    
        // printf("\n");
        // for (int i = 7; 0 <= i; i--) {
        //     printf("%c", (final & (1 << i)) ? '1' : '0');
        // }
        return 0; 
    }
}
    
    