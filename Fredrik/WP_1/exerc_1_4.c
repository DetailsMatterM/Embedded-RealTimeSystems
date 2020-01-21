#define MAX 4
#include <stdio.h>

int amountOfGuesses = 0;

int randomNum()
{
    int correctNumber;
    int correctNumberArray[] = {14,
                                26,
                                76,
                                37};
    for (int i = 0; i < 4; i++)
    {
        correctNumber = correctNumberArray[i];
    }
    return correctNumber;
}

int guessing()
{
    int flag = 1;
    while (flag == 1)
    {

        int guessedNumber;
        int correctNum = randomNum();
        printf("Guess a number\n");
        //  fgets(guessedNumber, MAX, stdin);
        scanf("%d", &guessedNumber);
        printf("The guessed number is %d\n", guessedNumber);
        printf("The correct number is %d\n", correctNum);
        printf("Times guessed : %d\n ", amountOfGuesses);

        if (guessedNumber == correctNum)
        {
            printf("**************************\n");
            printf("Congratulations, you won ! \n");
            printf("**************************\n");
            flag = 0;
            amountOfGuesses++;
        }
        else
        {
            printf("Incorrect, try again ! \n");
            amountOfGuesses++;
        }
    }
}

int main()
{

    guessing();
}