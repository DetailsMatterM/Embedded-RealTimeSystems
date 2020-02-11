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

struct my_struct
{
    int num;
};

typedef struct
{
    int xpos;
    int ypos;
    enum DIRECTION dir;
} ROBOT;

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
    printf("X pos is %d y pos is %d \n", robot.xpos, robot.ypos);
    //using a struct pointer
    ROBOT *structPointer = &robot;
    structPointer->dir = 'N';
    printf("X struct pos is %d y struct pos is %d  and the direction is %c, commands are : %s\n",
           structPointer->xpos, structPointer->ypos, structPointer->dir, command);

    return 0;
}

void move(struct my_struct *my_ptr)
{
    printf("\nPost Increment: %d", my_ptr->num++);
}