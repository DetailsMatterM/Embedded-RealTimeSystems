#include <stdio.h>
#define MAX 100

int main()
{
    char letters[MAX];
    int counter = 1;
    fgets(letters, MAX, stdin);
    printf("string is: %s\n", letters);

    for (int i = 0; i < MAX; i++)

    {
        if (letters[i] == ' ')
        {
            counter++;
        }
    }
    printf("Amount of words in the sentence :\n %d", counter);

    return 0;
}
