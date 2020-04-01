 
#include <stdio.h>
#include <string.h>
 
int removeCharInStr( char *str, char remove);
int main()
{
  	char string1 [] ={"some test xxx number one xx"}; 
    char ch1 = 'x';
  	

	removeCharInStr(string1, ch1);
	printf("\n%s", string1);
	
  	return 0;
}

int removeCharInStr( char *str, char remove) {
    int length = strlen(str);

	int *found = strchr(str, remove);
	while (found != NULL) {
		// Iterate through the array using a
		// pointer instead of numeric index, and
		// make changes starting at the position
		// *after* the one returned by strchr
		char *p = NULL;
		for (p = str; p < str + length; p++) {
			if (p > found) {
				char *prev = p-1;
				*prev = *p;
			}
		}
		// Decrement the length by 1 and put
		// in a null character at the end
		str[--length] = '\0';
		// Find a new character
		found = strchr(str, remove);
	}
	
	return 1;
}
int removeCharInStr( char *str, char remove) {
    int length = strlen(str);
    int *found = strchr (str, remove);
    while (found != NULL) {
        char *p = NULL;
        for (p=str; p< str + length; p++) {
            if(p > found) {
                char *prev = p – 1;
                *prev = *p;
             }
         }
         str[--length] = '\0';
         found = strchr(str, remove);
    }
    return 1;
}
