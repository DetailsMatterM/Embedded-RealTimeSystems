
/********************************************
      Demoprog  C-programming              **
      Corse DIT165 Embedded                 **
      File: linkedlist2_emb.c               **
      Demo-example listmanagement            **
      2017-11-17  / Peter Lundin           **
********************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//#### Constants #####
#define MAX 20

// ##### Type declaration ####

typedef struct q{
        int data;
        struct q *prev; // previus struct
        struct q *next; // next struct
}POSTTYPE ;


typedef struct  {
        POSTTYPE *head;
        POSTTYPE *current;
}LISTTYPE;
        

// ##### Function declarations #####

LISTTYPE* newque();
void add_new_element_last( LISTTYPE *Quetop );
void delete_list(LISTTYPE *quetop);
void clear_list(LISTTYPE *quetop);  // Not implemented in this file

//###### Main program #######
int main(int argc, char *argv[])
{   
    LISTTYPE *que1, *que2;
    int nr=0;
    printf("Time for start . \n");
    que1=newque();
    que2=newque();
    
    printf("\n Data is %d", que2->head->data );
    // Add 10 records to list.
    for ( nr=0; nr<10; nr++){
        add_new_element_last( que1);
        add_new_element_last( que2);
    }
    // Set curren pointer pointing to record nr 1
    que1->current=que1->head;
    que2->current=que2->head;
    
     // Print out all records of the list.
     while(!(que2->current->next==NULL)){
            printf("\n Data is %d", que1->current->data );
            que1->current=que1->current->next;
            printf("\n Data is %d", que2->current->data );
            que2->current=que2->current->next;
            
     }
     printf("\n Data is %d", que2->current->data );
  // ------- Free all memory ----------
  delete_list(que1);
  delete_list(que2);
  
  //------------------                 
  return 0;
}

LISTTYPE* newque(){
    int i=0;
    LISTTYPE *quetemp;
    quetemp=(LISTTYPE*) malloc(sizeof(LISTTYPE));
    
    quetemp->head=(POSTTYPE*) malloc(sizeof(POSTTYPE));
    quetemp->current=quetemp->head;                             
    quetemp->head->next=NULL;
    quetemp->head->prev=NULL;
    quetemp->head->data=1;
    
    return(quetemp);
}

void add_new_element_last( LISTTYPE *quetop ){
     static int nr=2;
     POSTTYPE *newelement;
     // Set current pointer pointing to record nr 1
     quetop->current=quetop->head;
     // Find last record
     while( !(quetop->current->next==NULL)){
            quetop->current=quetop->current->next;
     }
     // Create a new record        
     newelement=(POSTTYPE*) malloc(sizeof(POSTTYPE));
     quetop->current->next=newelement;
     newelement->next=NULL;
     newelement->prev=quetop->current;
     newelement->data=nr;
     nr++;
}

void delete_list(LISTTYPE *quetop) {
     POSTTYPE *tempelement;
    // Set curren pointer pointing to record nr 1
     quetop->current=quetop->head;
     // Find last record.
     while( !(quetop->current->next==NULL)){
            quetop->current=quetop->current->next;
     }
	
     
    while( !( quetop->current==NULL  )){
           
           tempelement=quetop->current;
           quetop->current=tempelement->prev;
           free(tempelement);
    }   
           free(quetop);   
           
}         
