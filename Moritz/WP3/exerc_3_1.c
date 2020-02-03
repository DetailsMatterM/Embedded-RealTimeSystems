#include <stdio.h>
#define MAX 21
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
    char input [MAX];
    printf("Please define the roboters starting position\n");
    printf("Coordinate x (between 0 and 99)\n");
    scanf("%d", &robot1.xpos);
    printf("Coordinate y (between 0 and 99)\n");
    scanf("%d", &robot1.ypos);
    robot1.dir = N;
    printf("\nX coordinate is %d and y coordinate is %d", robot1.xpos, robot1.ypos);
    printf("\nPlease enter a string of m and t(maximal length 20), m standing for move and t for turn\n");
    fflush(stdin);
    fgets(input, MAX, stdin);
    for (int i = 0; i < MAX; i++){
        if(input[i] == 'm') {
             move(ptr);
        } else {
            turn(ptr);
        }
    }
    printf("\nX coordinate is %d and y coordinate is %d", robot1.xpos, robot1.ypos);
   
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