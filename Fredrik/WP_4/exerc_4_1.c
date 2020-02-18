#include <stdio.h>
#include <stdlib.h>

//this is the byte that we add all our bits to
unsigned int byte = 0;

void displayBinary()
{
    for (int i = 7; 0 <= i; i--)
    {
        printf("%c", (byte & (1 << i)) ? '1' : '0');
    }
    printf("\n*******************\n ");
}
int main(int argc, char *argv[])

{
    if (argc != 6)
    {
        printf("Not enough args\n");
        return 0;
    }

    char engine_on = atoi(argv[1]);
    char gear_pos = atoi(argv[2]);
    char key_pos = atoi(argv[3]);
    char brake1 = atoi(argv[4]);
    char brake2 = atoi(argv[5]);

    //all these explanation are attempts to clarify the line of code underneath each comment section. so all this first text is for "byte |= brake2;"
    // first, we say that the variable "byte" which is 0000 0000 is = byte | brake2,
    //brake2 is assigned to an argument which in our example is the value 2, in binary thats 0000 0010
    // so we perform a comparison using truth tables to both numbers.
    // 0000 0000
    // 0000 0001
    //__________
    // 0000 0001 is the result of comparing both binary representations. hence, byte is now equal to 0000 0010.
    byte |= brake2;
    displayBinary();

    // byte = byte | (brake1 << 1) so in binary :  0000 0001 = 0000 0001 | (0000 0001 << 1)
    //where (0000 0001 << 1) == 0000 0010
    //so we can check the truth values
    // 0000 0001
    // 0000 0010
    //__________
    // 0000 0011 is now the current binary value of the variable byte
    byte |= (brake1 << 1);
    displayBinary();

    // var byte is now 0000 0011. so 0000 0011 = 0000 0011 | (key_pos <<2)
    // (key_pos << 2) in our specific test case evaluates to 0000 0010 (because we pass 2 in the argument, "file.c 1 2 2 1 1")
    // so moving two steps to the left 0000 0010 == 0000 1000
    // now we can compare them using our truth values (var byte and the binary value from key_pos)
    // 0000 0011 - variable byte
    // 0000 1000 - key_pos
    // ________________
    // 0000 1011
    byte |= (key_pos << 2);
    displayBinary();

    //so, our variable byte is now 0000 1011. and (gear_pos << 4 ) in the case where argv[] for gear_pos == 2,
    // it means that the binary representation is 0000 0010 << 4 so 0010 0000
    // 0000 1011 - variable byte
    // 0010 0000 - gear_pos
    // ____________________
    // 0010 1011 - current value of "byte"
    byte |= (gear_pos << 4);
    displayBinary();

    //puh, last one. hope you (and me ) are following okay. haha. im so silly. talking to myself in vs code (fuck im lonely)
    //the current binary value of the variable byte is now 0010 1011 , and (engine_on << 7) in the case the where its argv[] is 1
    // so : engine_on << 7 == 0000 0001 << 7 , which is equal to 1000 0000
    // 0010 1011 - variable byte
    // 1000 0000 - engine_on
    // _____________________
    // 1010 1011 please tell me that this is the correct answer.
    byte |= (engine_on << 7);

    for (int i = 7; 0 <= i; i--)
    {
        printf("%c", (byte & (1 << i)) ? '1' : '0');
    }
}
