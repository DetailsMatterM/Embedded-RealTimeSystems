 
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
    int i;
    int length;
    length = strlen(str);
	   	
	int *find = strchr(str, remove);
	while (find != NULL) {
		*find = find++;
		length--;
	}

	/*
	// "some test xxx number one xx" ->
	// "some test xx number one xxx"
	
	char a = str[i]
	if(strchr(a, remove) == NULL){
		copy character a in new array
		
	}
	i++
	// "some test xx number one xx"
	for(j = i; j < len; j++)
	{
		str[j] = str[j + 1];
	}
	*/
	
	return 1;	
}

/*
new array
copy 
*/