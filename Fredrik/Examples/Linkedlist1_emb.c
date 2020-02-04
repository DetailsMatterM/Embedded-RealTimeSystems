
/********************************************
      Demoprog  C-programming              **
      Course DIT165 Embedded                 **
      Fil: linkedlist1_emb.c               **
      Demo double linked list              **
      2017-11-17  / Peter Lundin           **
****************************************** **/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//#### Constants #####
#define MAX 20

// ##### Typdeklaretioner ####
typedef struct q{
        int data;
        struct q *prev;
        struct q *next;
} REGTYPE;

// ##### Declaration of functions #####

REGTYPE* random_list();

//###### Main program #######
int main(int argc, char *argv[])
{
    int nr=0;
    REGTYPE *act_post, *temp, *head=NULL;
    srand(time(0));
    printf("Time for running. \n");
    head=random_list();
    act_post=head;
    while( act_post!=NULL){
           printf("\n Post nr %d : %d" , nr++, act_post->data);
           act_post=act_post->next;
    }  
  // --- Free all memory ----- 
  
  while((act_post=head)!=NULL){
     head=act_post->next;
     free(act_post);
  }	
  return 0;
}

REGTYPE* random_list(){
    int nr, i=0;
    REGTYPE *top, *old, *item;
    top=(REGTYPE*) malloc(sizeof(REGTYPE));
    nr=rand()%100;
    top->data=nr;
    top->prev=NULL;
    top->next=NULL;
    item=top;
    i++;  
    while(i<MAX){
                 old=item; 
                 item=(REGTYPE*) malloc(sizeof(REGTYPE));                         
                 nr=rand()%100;
                 item->data=nr;
                 item->prev=old;
                 item->next=NULL;
                 old->next=item; 
                 i++;          
    }
    return(top);
}
                 
