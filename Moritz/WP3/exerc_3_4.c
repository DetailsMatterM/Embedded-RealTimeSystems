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
    
    int endCheck = 0;
    while (endCheck == 0) {
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
            PERSON dummyPerson;
            PERSON *dummy = &dummyPerson;
            write_new_file(dummy);
            break;
        case 2:
            fflush(stdin);
            printf("Please enter a first name (max length 19)\n");
            PERSON person;
            PERSON *pers = &person;
            fgets(pers -> firstname, 20, stdin);

            printf("Please enter a last name (max length 19)\n");
            fgets(pers-> famnamne, 20, stdin);
            printf("Please enter a personnumer\n");
            fgets(pers -> pers_number, 13, stdin);
            append_file(pers);
            break;
        case 5:
            endCheck = 1;
            break;
        }
    }
    
    //PERSON ppost;
    return(0);
}

void write_new_file (PERSON *inrecord){
    char filename[] = {"personfile.dat"};
    FILE *fileptr = fopen(filename,"wb");
    fwrite(inrecord, sizeof(PERSON), 1, fileptr);
    fclose(fileptr);
}

void append_file (PERSON *inrecord) {
    char filename[] = {"personfile.dat"};
    FILE *fileptr = fopen(filename,"ab+");
    fwrite(inrecord, sizeof(PERSON), 1, fileptr);
    fclose(fileptr);   
}