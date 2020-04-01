#include <stddef.h>

typedef struct q{
int data;
struct q *next;
struct q *prev;
} REGTYPE;
// ##### Declaration of functions #####
REGTYPE* create_list(int num);
void swop_record(REGTYPE *rec1, REGTYPE *rec2);
int main(int argc, char *argv[])
{
int status=0;
int nr;
REGTYPE *post1, *post2, *head=NULL;
…….
post1= …….;
post2= ………
// --- Generate the list --------
head=create_list(nr);
post1=….. ;
post2=…. ;
…..
swop_record(post1, post2); ……
……
}

void swop_record(REGTYPE *rec1, REGTYPE *rec2) {   
    rec1 -> prev -> next = rec2;
    rec1 -> next -> prev = rec2;

    rec2 -> prev -> next = rec1;
    rec2 -> next -> prev = rec1; 

    REGTYPE *recReferenceNext = rec1 -> next;
    REGTYPE *recReferencePrev = rec1 -> prev;
    
    rec1 -> prev = rec2 -> prev;
    rec1 -> next = rec2 -> next;
   
    rec2 -> next = recReferenceNext;
    rec2 -> prev = recReferencePrev;
}

void swop_record (REGTYPE *rec1, REGTYPE *rec2) {
    rec1 -> prev -> next = rec2;
    rec1 -> next -> prev = rec2;

    rec2 -> prev -> next = rec1;
    rec2 -> next -> prev = rec1;

    REGTYPE *recReferenceNext = rec1 -> next;
    REGTYPE *recReferencePrev = rec1 -> prev;

    rec1 -> prev = rec2 -> prev;
    rec1 -> next = rec2 -> next;

    rec2 -> next = recReferenceNext;
    rec2 -> prev = recReferencePrev;
