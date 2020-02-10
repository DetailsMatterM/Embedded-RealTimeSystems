/* ====================================
File name: exerc_3_4.c (or cpp)
Date: 2019-mm-dd
Group Number:xxxx
Members that contributed:

Demonstration code: [<Ass code 1-3> <abc>] Important !
====================================== */

#include <stdlib.h>
#include <stdio.h>

// -----Typedefs -------
typedef struct {
char firstname[20];
char famnamne[20];
char pers_number[13]; // yyyymmddnnnc
} PERSON;

// Function declaration (to be extend)
PERSON input_record (void); // Reads in a person record.
void write_new_file (PERSON *inrecord); //Creats a file and write a first record
void printfile (void); // print out all persons in the file
void search_by_firstname (char *name);// print out person if in list
void append_file (PERSON *inrecord);// appends a new person to the file

int main (void) {
    PERSON ppost;
    return(0);
}