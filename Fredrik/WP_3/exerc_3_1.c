#include <stdio.h>
#include <string.h>

char instructions[];

enum DIRECTION
{
    N,
    O,
    S,
    W
};

typedef struct
{
    int xpos;
    int ypos;
    enum DIRECTION dir;
} ROBOT;

void move(ROBOT *ptr);

int main()
{
    char command[20];
    int pos;
    ROBOT robot;
    printf("Enter x pos : ");
    scanf("%d", &robot.xpos);
    printf("Enter y pos : ");
    scanf("%d", &robot.ypos);
    getchar();
    printf("Enter a string of commands : \n");
    fgets(command, 20, stdin);
    //printf("X pos is %d y pos is %d \n", robot.xpos, robot.ypos);
    //using a struct pointer
    ROBOT *structPointer = &robot;
    structPointer->dir = N;

    printf("X struct pos is %d y struct pos is %d  and the direction is %c, commands are : %s\n",
           structPointer->xpos, structPointer->ypos, structPointer->dir, command);
    for (int i = 0; i < 20; i++)
    {
        if (command[i] == 'm')
        {
            move(structPointer);
        }
        else
        {
            turn(structPointer);
        }
    }
    printf("\n X coordinate is %d and y coordinate is %d", structPointer->xpos, structPointer->ypos);

    return 0;
}

void turn(ROBOT *ptr)
{
    ptr->dir++;
}
void move(ROBOT *ptr)
{
    if (ptr->dir == N && ptr->ypos != 99)
    {
        ptr->ypos++;
    }
    else if (ptr->dir == O && ptr->xpos != 99)
    {
        ptr->xpos++;
    }
    else if (ptr->dir == S && ptr->ypos != 0)
    {
        ptr->ypos--;
    }
    else if (ptr->dir == W && ptr->xpos != 0)
    {
        ptr->xpos--;
    }
}