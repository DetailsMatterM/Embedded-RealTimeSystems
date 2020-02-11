#include <stdlib.h>
#include <stdio.h>
// -----Typedefs -------
typedef struct
{
    char firstname[20];
    char famnamne[20];
    char pers_number[13];              // yyyymmddnnnc
} PERSON;                              // Function declaration (to be extend)
PERSON input_record(void);             // Reads in a person record.
void write_new_file(PERSON *inrecord); //Creates a file and write a first record
void printfile(void);                  // print out all persons in the file
void search_by_firstname(char *name);  // print out person if in list
void append_file(PERSON *inrecord);    // appends a new person to the file
int main(void)
{
    PERSON ppost;
    PERSON *personPtr = &ppost;
    write_new_file(personPtr);
    return (0);
}

void write_new_file(PERSON *inrecord)
{
    PERSON person;
    PERSON *structPtr = &person;
    // printf("Enter family name ");
    // scanf("%s", structPtr->famnamne);
    FILE *fp = NULL;
    fp = fopen("textFile.txt", "wb");
    fputs("John\nJohnsson\n9304055156\n", fp);
}
