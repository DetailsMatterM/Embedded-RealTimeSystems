#include <string.h>
int str_addmaxnr(char *s1, const char *s2, int max) {
    int i = 1;
    while(*s2 != '\n'){
        strncat(s1, &s2,1);
        i++;
        if(i > max) {
            return 0;
        }
    }
    return 1;
}