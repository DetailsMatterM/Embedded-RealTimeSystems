#include <stddef.h>
typedef struct q{
    int data;
    struct q *next;
    struct q *prev;
} REGTYPE;

// ##### Declaration of functions #####
REGTYPE* create_list(int num);
int insert_record(REGTYPE *newrecord, REGTYPE *top);
//###### Main program #######
int main(int argc, char *argv[]) {
    int status = 0;
    int nr;
    REGTYPE *act_record, *head = NULL;
    
    // --- Generate the list --------
    head = create_list(nr);
    
    status = insert_list(act_record, head);
    
}

int insert_record(REGTYPE *newrecord, REGTYPE *top) {
    if(newrecord -> prev != NULL) {
        newrecord -> prev = top;
        newrecord -> next = top->next;
        top->next -> prev = newrecord;
        top->next = newrecord;
        return 1;
    }
    return 0;
    
}