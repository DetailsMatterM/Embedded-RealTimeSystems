/*
 *  File    : nim.c 
 *  Program : Nim game
 *  Author  : 
 * Fredrik Ullman
 * Moritz Denke
 * Mikael Jansson
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define MAX_COINS 13

const int HUMAN = 0;
const int COMPUTER = 1;

/* ------------- IO --------------- */

/*
 * human_choice
 * Get human choce as an int from stdin.
 * Clears stdin.
 * in: pile
 * out: int-value in range 1-3 (and also less than pile)
 */
int human_choice(int pile);

/*
 * write_winner
 * Write winner as a string on stdout.
 * in: Values HUMAN or COMPUTER.
 * out:
 */
void write_winner(int player);

/*
 * play_again
 * Ask human if he/she wants to play
 * another round. If 'n' or 'N' selected
 * (single char) return false else true.
 * Clears stdin.
 * in: 
 * out: true or false
 */
int play_again();

/* ---------------- Logic ----------------*/

/*
 * computer_choice 
 * Get computers choice (including some AI,
 * if 4 coins or less left, function makes a 
 * smart choice else random).
 * in: pile
 * out: int-value in range 1-3 (and also less than pile)
 */
int computer_choice(int pile);

/*
 * toggle
 * Switches player, if HUMAN in COMPUTER out
 * etc.
 * in:  actual player
 * out: next player
 */
int toggle(int player);

/* --------------------- Utilities -------------*/
void clear_stdin();

/***************************************************
 *
 *    MAIN
 *
 ***************************************************/
int main()
{
    int pile,    /* This is how many coins we have */
            player,  /* Who is playing? */
            n_coins; /* Number of coins taken */

    srand(time(0)); /* Setup random */

    printf("V�lkommen till NIM by Fredrik, Moritz and Mike \n");

    pile = MAX_COINS; /* Set start values (= init) */
    player = HUMAN;

    /* 
   *  Program main loop 
   */
    while (true)
    {

        printf("Det ligger %d  mynt i h�gen\n", pile);

        if (player == HUMAN)
        {

            n_coins = human_choice(pile);
            printf(" Human took %d ... ", n_coins);
        }
        else
        {
            n_coins = computer_choice(pile);
            printf(" Computer took %d ... ", n_coins);
        }
        pile -= n_coins;
        if (pile == 0)
        {
            printf("Oops all remaining coins were taken \n");
            break;
        }

        player = toggle(player);
        if (pile <= 1)
        {

            break;
        }
    }
    /*
   * end main loop
   */

    write_winner(player);
    int checker = play_again();
    if (checker == 0) {
        main();
    } else {
        printf("Avslutat\n");
    }


    return 0;
}

/******************************************************
 *
 *  DEFINITIONS
 * 
 ******************************************************/

void clear_stdin()
{
    char temp;
    while ((temp = getchar()) != '\n');
}

//edge case that needs to be implemented: if you dont enter an integer but a character
int human_choice(int pile)
{
    int num;
    int flag = 0;
    printf("Take 1, 2 or 3 coins : \n");
    while (flag == 0)
    {
        scanf("%d", &num);
        if (num <= 3 && num > 0 && num <= pile)
        {
            flag = 1;
        }
        else
        {
            printf("Please enter a valid digit\n");
        }
        clear_stdin();
    }
    return num;
}

int computer_choice(int pile)
{
    int lower = 1;
    int upperLimit = 3;
    int counter;
    int num;

    for (int i = 0; i < counter; i++)
    {
        num = (rand() % (upperLimit - lower + 1)) + lower;
    }
    if (pile == 4)
    {
        num = 3;
    }
    else if (pile == 3)
    {
        num = 2;
    }
    else if (pile == 2)
    {
        num = 1;
    }
    return num;
}

void write_winner(int player)
{

    int num;
    if (player == 0)
    {
        num = 1;
        player = num;
        printf("WINNER IS COMPUTER !\n ");
    }
    else if (player == 1)
    {
        num = 0;
        player = num;
        printf("WINNER IS HUMAN !\n ");
    }
}
int play_again()
{
    printf("Do you want to play again? Type 'y' if you want to play again! ");
    char option;
    scanf("%c", &option);

    if (option == 'y')
    {
        printf("Welcome to next round! ");
        return 0;
    }
    else
    {
        printf("Byebye \n");
        return 1;
    }
}

int toggle(int player)
{
    int num;
    if (player == 0)
    {
        num = 1;
        player = num;
    }
    else if (player == 1)
    {
        num = 0;
        player = num;
    }
}
