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

#include <math.h>
#define MAX_COINS 13
#define MAX 3

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
            printf("- Human took %d\n", n_coins);
        }
        else
        {
            n_coins = computer_choice(pile);
            printf("- Computer took %d\n", n_coins);
        }
        pile -= n_coins;

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

    printf("Avslutat\n");

    return 0;
}

/******************************************************
 *
 *  DEFINITIONS
 * 
 ******************************************************/

void clear_stdin()
{
    while (getchar() != '\n')
    {
        ;
    }
}

//edge case that needs to be implemented: if you dont enter an integer but a character
int human_choice(int pile)
{
    int num;
    int flag = 1;
    scanf("%d", &num);

    while (flag == 1)
    {
        if (num >= 4 || num < 1)
        {

            printf("You can only take 1, 2 or 3 coins from the stack. \n ");
            scanf("%d", &num);
        }
        else
        {
            pile = num;
            flag = 0;
        }
    }
}

int computer_choice(int pile)
{
    int num = 1;
    pile = num;
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

    /*
 * write_winner
 * Write winner as a string on stdout.
 * in: Values HUMAN or COMPUTER.
 * out:
 */
}

int play_again()
{
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
