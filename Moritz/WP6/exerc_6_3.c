#include <stdio.h>
#include <stdlib.h>
#define ML13_Status 0x0B10
//00010000 or 
#define ML13_Control 0x0B00

void delay();
char control = ML13_Control;
char status = ML13_Status;
void main()
{

    // if (status == 0x10 || control == 0b00000010)
    // {
    //     printf("Door is closing slowly.....\n");
    //     status |= 0b100000000;
    //     delay();
    //     printf("Door is closed.\n");
    //     status |= 0b00010000;
    //     delay();
    // }

    //this checks if someone is approaching the sensor. if so, it changes status to
    // "Door is wide open".
    int proximity = 0;
    char shiftInOne = 1;
    char shiftInZero = 0;
    while (1)
    {
        if (((control & 0x01) == 1) || ((status >> 3) & 0x01) == 0x0B01)
        {
            status = shiftInOne << 6;
            delay(5000);
            status = shiftInOne << 4;
            delay(10000);
        }
        if (((control >> 1 & 0x01) == 1) || ((status >> 4) & 0x01) == 0x0B01)
        {
            status = shiftInZero << 6;
            status = shiftInZero << 4;
            status = shiftInOne << 7;
            delay(5000);
            status = shiftInOne << 5;
        }
    }

    // status = 0b0010100;
    // if (status == 0b00010100)
    // {
    //     printf("Door is slowly opening ....\n");
    //     status |= 0b100000000;
    //     delay();
    //     printf("Door is open\n");
    //     status = 0b00001000;
    //     delay();
    // }
}

void delay(int length)
{
    for (int i = 0; i < length * 100; i++)
    {
        if (((status >> 2) & 0x01) == 0x0B01)
        {
            break;
        }

        if (((control >> 1) & 0x01) == 0b00000010)
        {
            break;
        }

        if (((control >> 1) & 0x00) == 0b00000001)
        {
            break;
        }
    }
}
