//41214
/* ====================================
File name: exerc_3_3.c (or cpp)
Date: 2019-02-13
Group Number:07
Members that contributed:
Fredrik Ullman
Mikael Köse Jansson
Moritz Denke
Demonstration code: [41214] Important !
====================================== */
//
/********************************************
DIT1165 Program file exerc_3_3.c **
2018-01-04 **
********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#### Konstanter #####
#define MAX 5

// ##### Typedefs ####
typedef struct q {
    int number;
    struct q *next;
    struct q *prev;
} REGTYPE;

// ##### Funcion declarations #####
REGTYPE* random_list(void);
REGTYPE* add_first(REGTYPE* temp, int data);

//###### Main program #######
int main (int argc, char *argv[]) {
    int nr = 0;
    REGTYPE *akt_post , *head = NULL;
    srand( time(0)); // Random seed
    head = random_list();
    akt_post = head;
    printf("New List:");
    while ( akt_post != NULL) {
        printf ("\n Post nr %d : %d" , nr++, akt_post -> number);
        akt_post = akt_post->next;
    }

    head = add_first(head, 5);
    akt_post = head;
    nr = 0;
    printf("\n\nList after addition of first record:");
    while ( akt_post != NULL) {
        printf ("\n Post nr %d : %d" , nr++, akt_post -> number);
        akt_post = akt_post->next;
    }
   
    // --- Free of allocated memory ---
    while ((akt_post=head) != NULL) {
        head = akt_post->next;
        free (akt_post);
    }

    return 0;
}

// ==== End of main ======================================
REGTYPE* random_list (void) {
    int nr, i = 0;
    REGTYPE *top, *old, *item;
    top = (REGTYPE *) malloc(sizeof(REGTYPE));
    nr = rand() % 100;
    top->number = nr;
    top->prev = NULL;
    top->next = NULL;
    item = top;
    i++;
    while (i < MAX) {
        old = item;
        item = (REGTYPE *) malloc(sizeof(REGTYPE));
        nr = rand() % 100;
        item->number = nr;
        item->prev = old;
        item->next = NULL;
        old->next = item;
        i++;
    }
    return (top);
}

//==========================================================
REGTYPE* add_first (REGTYPE* temp, int data) {
    REGTYPE *new;
    new = (REGTYPE*) malloc (sizeof(REGTYPE));
    new -> number = data;
    new -> next = temp;
    new -> prev = NULL;
    temp -> prev = new;
    return new;
// Adds a record first i list and set the field tal to data
}