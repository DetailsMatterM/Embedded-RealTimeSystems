#include <stdio.h>
#include <stdlib.h>
#define ML13_Status 0x0B10
//00001000
#define ML13_Control 0x0B00

void delay();

void main()
{
    char control = ML13_Control;
    char status = ML13_Status;

    if (status == 0x10 || control == 0b00000010)
    {
        printf("Door is closing slowly.....\n");
        status |= 0b100000000;
        delay();
        printf("Door is closed.\n");
        status |= 0b00010000;
        delay();
    }

    //this checks if someone is approaching the sensor. if so, it changes status to
    // "Door is wide open".
    status = 0b0010100;
    if (status == 0b00010100)
    {
        printf("Door is slowly opening ....\n");
        status |= 0b100000000;
        delay();
        printf("Door is open\n");
        status = 0b00001000;
        delay();
    }
}

void delay()
{
    for (int i = 0; i < 10000; i++)
    {
        for (int j = 0; j < 100000; j++)
        {
        }
    }
}