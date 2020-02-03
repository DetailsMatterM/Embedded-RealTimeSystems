#include <stdio.h>

enum DIRECTION{N,O,S,W};
int main() {
    
    typedef struct {
        int xpos;
        int ypos;
        enum DIRECTION dir;
    } ROBOT;

    int x;
    int y;
    printf("Please define the roboters starting position\n");
    printf("Coordinate x (between 0 and 99)\n");
    scanf("%d", &x);
    printf("Coordinate y (between 0 and 99)\n");
    scanf("%d", &y);

    printf("\n%d", x+y);

    return 0;
}