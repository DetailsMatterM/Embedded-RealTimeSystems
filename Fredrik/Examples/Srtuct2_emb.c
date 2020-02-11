

/********************************************
      Demo program  C-programming          **
      Kurs DIT165 Embedde                  **
      Fil: struct2.cpp                     **
      Demoexempel struct pointer           **
      2013-02-12  / Peter Lundin           **
********************************************/

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

//#### Constant #####
#define MAX 20

// ##### Typdeclaration ####

typedef struct{
        char lname[20];
        char fname[20];
        char street[20];
        int age;
} REGTYPE;

// ##### Function declarations #####

int mata_in( REGTYPE card[]);

//###### Main program #######
int main(int argc, char *argv[])
{
    int nr_of_records;
    REGTYPE records[MAX], post;
    REGTYPE *postP=&post;
    printf("Starts running. \n");
    nr_of_records=mata_in(records);
    printf(" \n You have now entered %d posts to the register \n", nr_of_records);
    *postP=records[1];   // post assigns values in all fields !!
    puts(postP->lname);
    printf("\n %s  is  %d  years.  ",postP->lname,  postP->age);
  system("PAUSE");	
  return 0;
}

int mata_in(REGTYPE card[]){
    int ar,i=0;
    char temp[20];
    while(i<MAX){
                 fflush(stdin);
                 printf("\n Enter first name, just 'a' aborts the entering : ");
                 gets(temp);
                 if(strlen(temp)==1 && temp[0]=='a') break;
                 puts(temp);
                 strcpy(card->fname,temp);
                 printf("\n Enter last name  : ");
                 gets(temp);
                 strcpy(card->lname,temp);
                 printf("\n Enter Street : ");
                 gets(temp);
                 strcpy(card->street,temp);
                 printf("\n Enter the age : ");
                 scanf("%d",&ar);
                 card->age=ar;
                 card++;
				 i++;
    }
    return(i);
}
