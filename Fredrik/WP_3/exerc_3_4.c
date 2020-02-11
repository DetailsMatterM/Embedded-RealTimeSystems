#include <stdlib.h>
#include <stdio.h>
#include <curses.h>
#include <string.h>
#include <ctype.h>
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
void search_by_firstname();            // print out person if in list
void append_file(PERSON *inrecord);    // appends a new person to the file
int main(void)
{

    PERSON ppost;
    PERSON *personPtr = &ppost;
    int option;
    append_file(personPtr);

    scanf("%d", &option);
    switch (option)
    {
    case 1:
        write_new_file(personPtr);
        break;

    case 2:
        append_file(personPtr);
        break;

    case 3:
        printfile();

    case 4:
        search_by_firstname_example();

    default:
        break;
    }

    return (0);
}

void write_new_file(PERSON *inrecord)
{
    PERSON person;
    PERSON *structPtr = &person;
    FILE *fp = NULL;
    //not sure how they want the dummy data input to the file. like this below ?
    // printf("Enter family name ");
    // scanf("%s", structPtr->famnamne);
    if ((fp = fopen("textFile.txt", "w")) == NULL)
    {
        printf("\n Can not create the file");
        exit(1);
    }
    else
    {
        fputs("John\nJohnsson\n9304055156\n", fp);
    }
    fclose(fp);
}

void append_file(PERSON *inrecord)
{
    PERSON person;
    PERSON *structPtr = &person;
    char tempFamName[20];
    char tempFirstName[20];
    printf("Enter family name ");
    gets(tempFamName);
    getchar();
    printf("Enter first name ");
    gets(tempFirstName);
    getchar();
    strcpy(structPtr->famnamne, tempFamName);
    strcpy(structPtr->firstname, tempFirstName);

    FILE *fp = NULL;
    fp = fopen("textFile.txt", "a");
    fputs(structPtr->famnamne, fp);
    fputs(structPtr->firstname, fp);

    fclose(fp);
    return 0;
}

void printfile(void)
{
    FILE *fp;

    char c;

    // Open file
    fp = fopen("textFile.txt", "r");
    if (fp == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }

    // Read contents from file
    c = fgetc(fp);
    while (c != EOF)
    {
        printf("%c", c);
        c = fgetc(fp);
    }

    fclose(fp);
    return 0;
}

void search_by_firstname_example()
{
    int num = 0;
    char word[2000];
    char string[50];
    char student[100] = {0};

    while (student[0] != '0')
    {
        FILE *in_file = fopen("textFile.txt", "r");
        if (in_file == NULL)
        {
            printf("Error file missing\n");
            exit(-1);
        }

        printf("please enter a word(enter 0 to end)\n");
        scanf("%s", student);
        while (fscanf(in_file, "%s", string) == 1)
        {
            //Add a for loop till strstr(string, student) does-not returns null.
            if (strstr(string, student) != 0)
            { //if match found
                num++;
            }
        }
        printf("we found the word %s in the file %d times\n", student, num);
        num = 0;
        fclose(in_file);
    }
    return 0;
}
