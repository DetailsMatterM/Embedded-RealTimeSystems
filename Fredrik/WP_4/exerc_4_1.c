#include <stdio.h>

typedef struct
{
    unsigned char engine_on : 1;
    unsigned char gear_pos : 3;
    unsigned char key_pos : 2;
    unsigned char brake1 : 1;
    unsigned char brake2 : 1;
} BYTE;

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        printf("Name of file  :  %s and arguments:\n", argv[0]);
        return 1;
    }
    BYTE byte;
    BYTE *structptr = &byte;
    byte.engine_on = 1;
    if (argv[1][0] == '0')
    {
        //this XOR operator toggles between values,
        //so if the user chooses "0" its swaps the last digit in the
        //bit pattern from 1 to 0
        printf("engine_on %d \n", byte.engine_on = byte.engine_on ^ 1);
    }
    else if (argv[1][0] == '1')
    {
        printf("engine_on : %d", byte.engine_on);
    }
}
