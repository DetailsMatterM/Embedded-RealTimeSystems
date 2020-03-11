#include <stddef.h>
typedef struct q {
    int a;
    struct q* next;
} REGTYPE;

int main() {
    REGTYPE *temp;
    REGTYPE *old;
    REGTYPE *head = (REGTYPE*) malloc(sizeof(REGTYPE));
    head -> next = NULL;
    head -> a = 0;
    temp = head;
    for(int i = 1; i < 10; i++) {
        old = temp;
        temp = (REGTYPE*) malloc(sizeof(REGTYPE));
        old -> next = temp;
        temp -> a = i;
        temp -> next = NULL;
    }

}
