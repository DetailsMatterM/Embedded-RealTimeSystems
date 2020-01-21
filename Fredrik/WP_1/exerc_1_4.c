#include <stdio.h>

int amountOfGuesses = 1;
char answer;

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
    int MAX_NUMBER = 3;
    while (MAX_NUMBER > amountOfGuesses)
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
    int flag = 1;
    guessing();

    while (flag == 1)
    {
        if (amountOfGuesses > 1)
        {
            printf("Guessed to many times ! \n type  y to try again or n to exit ");
        }
        scanf("%s", &answer);

        switch (answer)
        {
        case 'y':
            amountOfGuesses = 0;
            guessing();
            break;
        case 'n':
            flag = 0;
            printf("bye bye ! ");
            amountOfGuesses = 0;
        default:
            printf("Incorrect key entered ");
            amountOfGuesses = 0;

            break;
        }
    }
}