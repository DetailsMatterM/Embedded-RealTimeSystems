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

void turn(ROBOT *ptr) {
    ptr -> dir++;
}
void move(ROBOT *ptr) {
    //implement check for direction to decide on the right way to move
    if (ptr -> dir == N && ptr -> ypos != 99) {
        ptr -> ypos++;
    } else if (ptr -> dir == O && ptr -> xpos != 99) {
        ptr -> xpos++;
    } else if (ptr -> dir == S && ptr -> ypos != 0) {
        ptr -> ypos--;
    } else if(ptr -> dir == W && ptr -> xpos != 0) {
        ptr -> xpos--;
    }
}