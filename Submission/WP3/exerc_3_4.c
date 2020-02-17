/* ====================================
File name: exerc_3_4.c (or cpp)
Date: 2019-02-13
Group Number:07
Members that contributed:
Fredrik Ullman
Mikael Köse Jansson
Moritz Denke
Demonstration code: [22204] Important !
====================================== */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
void search_by_lastname (char *name);
void append_file (PERSON *inrecord);// appends a new person to the file

int main (void) {

    int endCheck = 0;
    while (endCheck == 0) {
        printf("Welcome to the person register. How may we be of service?\nChose one of the following options"
               "by typing the according number:\n"
               "1 Create a new and delete the old file.\n"
               "2 Add a new person to the file.\n"
               "3 Search for a person in the file.\n"
               "4 Print out all in the file.\n"
               "5 Exit the program.\n");

        int input = 0;
        scanf ("%d", &input);
        fflush(stdin);
        switch(input) {
            case 1:
                printf("Your file will be generated.\n");
                PERSON dummyPerson;
                strcpy(dummyPerson.famnamne, "assad");
                strcpy(dummyPerson.firstname, "khb");
                strcpy(dummyPerson.pers_number, "56758");
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
                fflush(stdin);
                append_file(pers);
                break;
            case 3:
                fflush(stdin);
                int choice = 0;
                printf("Enter 1 for firstname or 2 for lastname.\n");
                scanf("%d", &choice);
                if (choice == 1) {
                    fflush(stdin);
                    printf("Please enter the first name (max length 19) that you want to search for\n");
                    char firstname[20];
                    fgets(firstname, 20, stdin);
                    char *fname = firstname;
                    search_by_firstname(fname);
                } else if (choice == 2) {
                    fflush(stdin);
                    printf("Please enter the last name (max length 19) that you want to search for\n");
                    char lastname[20];
                    fgets(lastname, 20, stdin);
                    char *fname = lastname;
                    search_by_lastname(fname);
                }
            
                fflush(stdin);
                break;
            case 4:
                printfile();
                fflush(stdin);
                break;
            case 5:
                endCheck = 1;
                printf("Good Bye!");
                break;
            default:
                printf("Please enter valid input!\n");
                break;
        }
    }

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

void search_by_firstname (char *name) {
    char filename[] = {"personfile.dat"};
    FILE *fileptr = fopen(filename,"rb");
    PERSON person;
    PERSON *pers = &person;
    int n = 0;
    fseek (fileptr, 0 , SEEK_END);
    long size = ftell (fileptr) ;
    rewind (fileptr);
    double counter = 0;
    int flag = 0;
    while (counter < size) {
        fseek (fileptr, n * sizeof(PERSON), SEEK_SET);
        fread (&person, sizeof(PERSON), 1, fileptr);
        if ((strcmp(person.firstname, name)) == 0) {
            printf("\n%s%s%s\n", pers->firstname, pers->famnamne, pers->pers_number);
            flag = 1;
        }
        n++;
        counter = counter + sizeof(person);
    }
    if (flag == 0) {
        printf("Requested person not in database.\n");
    }
    fclose(fileptr);
}

void search_by_lastname (char *name) {
    char filename[] = {"personfile.dat"};
    FILE *fileptr = fopen(filename,"rb");
    PERSON person;
    PERSON *pers = &person;
    int n = 0;
    fseek (fileptr, 0 , SEEK_END);
    long size = ftell (fileptr) ;
    rewind (fileptr);
    double counter = 0;
    int flag = 0;
    while (counter < size) {
        fseek (fileptr, n * sizeof(PERSON), SEEK_SET);
        fread (&person, sizeof(PERSON), 1, fileptr);
        if ((strcmp(person.famnamne, name)) == 0) {
            printf("\n%s%s%s\n", pers->firstname, pers->famnamne, pers->pers_number);
            flag = 1;
        }
        n++;
        counter = counter + sizeof(person);
    }
    if (flag == 0) {
        printf("Requested person not in database.\n");
    }
    fclose(fileptr);
}

void printfile (void) {
    char filename[] = {"personfile.dat"};
    FILE *fileptr = fopen(filename,"rb");
    if (fileptr == NULL) {
        printf("The file has not been found.\n");
        return;
    } else {
        PERSON person;
        PERSON *pers = &person;
        int n = 1;
        printf("People in the register:\n");
        fseek (fileptr, 0 , SEEK_END);
        long size = ftell (fileptr) ;
        rewind (fileptr);
        double counter = 0;
        double personSize = sizeof(person);
        while (counter < (size-personSize)){
            fseek (fileptr, n * sizeof(PERSON), SEEK_SET);
            fread (&person, sizeof(PERSON), 1, fileptr);
            printf("\n%s%s%s\n", pers->firstname, pers->famnamne, pers->pers_number);
            counter = counter + personSize;
            n++;
        }
        fclose(fileptr);
    }
}