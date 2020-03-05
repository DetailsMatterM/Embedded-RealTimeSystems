#include <stdio.h>
#include <stdlib.h>
#define ML13_Status 0x0B10
//00010000 or
#define ML13_Control 0x0B00
//these might be just the address we sent the instructions to

int delay();
char control = ML13_Control; //that should just be a char value we can save stuff in
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

    char shiftInOne = 1;
    char shiftInZero = 0;
    //while loop runs continously keepig check on the door, we start with closed door
    while (1)
    {
        //if button for control is pressed or person approaches door
        if (((control & 0x01) == 1) || ((status >> 3) & 0x01) == 1)
        {
            //shift to opening slowly
            status = shiftInOne << 6;
            if (delay(5000) == 1) {
                //shift to wide open
                // time door stays open
                status = shiftInOne << 4;
                status = shiftInZero << 6;
                delay(10000); 
            } // time it takes to open door
            
        }
        //if button for closing is pressed or door is wide open
        if (((control >> 1 & 0x01) == 1) || ((status >> 4) & 0x01) == 1)
        {
            status = shiftInZero << 4;
            status = shiftInOne << 7;
            if (delay(5000) == 1) {
                status = shiftInOne << 5;
            }
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

//rename the function to make sure that it is clear
//that it does more than just waiting
int delay(int length)
{
    //use the gettimeofday and stire start time and when time has passed break
    for (int i = 0; i < length * 100; i++)
    {
        //if someone approaches the door
        if (((status >> 3) & 0x01) == 1)
        {
            return 0; //means it was broken
        }
        //if close button is pressed
        if (((control >> 1) & 0x01) == 1)
        {
            return 0; 
        }
        //if open button is pressed
        if ((control & 0x01) == 1)
        {
            return 0; 
        }
    }
    return 1; //means we waited successfully
}
