// Struct1.cpp 

/********************************************
      Demoprogram            C-programming **
      Kurs DIT165 Embedded                 **
      Fil: struct1_emb.cpp                     **
      Demoex 1      structs                **
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
    printf("Starts running. \n");
    nr_of_records=mata_in(records);
    printf(" \n You have now entered %d posts to the register \n", nr_of_records);
    post=records[1];   // post assigns values in all fields !!
    puts(post.lname);
    printf("\n %s  is  %d  years.  ",post.lname,  post.age);
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
                 //puts(temp);
                 strcpy(card[i].fname,temp);
                 printf("\n Enter last name  : ");
                 gets(temp);
                 strcpy(card[i].lname,temp);
                 printf("\n Enter Street : ");
                 gets(temp);
                 strcpy(card[i].street,temp);
                 printf("\n Enter the age : ");
                 scanf("%d",&ar);
                 card[i].age=ar;
                 i++;
    }
    return(i);
}
                 
