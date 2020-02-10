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
int createNewFile();

int main (void) {
    printf("Welcome to the person register. How may we be of service?\nChose one of the following options"
           "by typing the according number:\n"
           "1 Create a new and delete the old file.\n"
           "2 Add a new person to the file.\n"
           "3 Search for a person in the file .\n"
           "4 Print out all in the file.\n"
           "5 Exit the program.\n");

    int input;
    scanf ("%d", &input);
    switch(input) {
        case 1:
            printf("Your file will be generated.\n");
            int check = createNewFile();
            if (check == 0) {
                printf("Your file has been created successfully.\n");
            } else {
                printf("Your file could not be created\n");
            }
            break;
        case 2:
            printf("Please enter a personnumer");
            PERSON person;
            PERSON *pers = &person;
            fgets(pers -> pers_number, 13, stdin);

            //write_new_file(pers);

    }
    PERSON ppost;
    return(0);
}

int createNewFile() {
    char filename[] = {"personfile.txt"};
    FILE* fileptr = NULL;
    fileptr = fopen(filename,"w");
    int result;
    if(fileptr != NULL) {
        fputs("dummyentry", fileptr);
        result = 0;
    } else {
        result = 1;
    }
    fclose(fileptr);
    return result;
}