#include <stdio.h>

enum DIRECTION{N,O,S,W};

typedef struct {
        int xpos;
        int ypos;
        enum DIRECTION dir;
    } ROBOT;

void move(ROBOT *ptr);
void turn(ROBOT *ptr);

int main() {
    
    ROBOT robot1;
    ROBOT *ptr = &robot1;
    int x;
    int y;
    printf("Please define the roboters starting position\n");
    printf("Coordinate x (between 0 and 99)\n");
    scanf("%d", &robot1.xpos);
    printf("Coordinate y (between 0 and 99)\n");
    scanf("%d", &robot1.ypos);
    robot1.dir = N;
    
    printf("Please enter a string of m and t(maximal length 20), m standing for move and t for turn ");
    return 0;
}

void move(ROBOT *ptr) {
    if(ptr -> xpos != 99) {
        ptr -> xpos++;
    }
}