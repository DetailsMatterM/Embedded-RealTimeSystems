#define MAX 4
#include <stdio.h>

int amountOfGuesses = 1;

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
        scanf("%d", &guessedNumber);

        if (guessedNumber == correctNum)
        {
            printf("*******************************************************\n");
            printf("You have guessed %d times and your guess %d is correct \n", amountOfGuesses, guessedNumber);
            printf("*******************************************************\n");
            flag = 0;
            amountOfGuesses++;
        }
        else if (guessedNumber > correctNum)
        {
            printf("Too high , try again ! \n");
            amountOfGuesses++;
        }
        else if (guessedNumber < correctNum)
        {
            printf("Too low! try again \n");
            amountOfGuesses++;
        }
    }
}

int main()
{

    guessing();
}