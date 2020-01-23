/* ====================================
File name: exerc_1_0.c
Date: 2020-01-21
Group nr 7
====================================== */

#include <stdio.h>

int main()
{

    int c;

    printf("Entero numbero betweeno 1 and 5:  ");

    scanf("%d", &c);

    switch (c)
    {
    case 1:
        printf("Arrriba! You entered numbero: 1");
        break;

    case 2:
        printf("Arrriba! You entered numbero: 2");
        break;

    case 3:
        printf("Arrriba! You entered numbero: 3");
        break;

    case 4:
        printf("Arrriba! You entered numbero: 4");
        break;

    case 5:
        printf("Arrriba! You entered numbero: 5");
        break;

    default:
        printf(" Ay Ay Ay, wrong numbero amigo!");
        break;
    }
    return 0;
}