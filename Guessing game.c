#include <stdio.h>
#include <time.h>

int main(void)
{
    srand (time(0));
    int number;
    number = rand() % 100 + 1;
    int guess;
    /** Dapat dili nimo e include ang "counter" sa loop aron naga minus iyang value. **/
    int counter = 10 ; /** Lahi ang " = " from " == " Read.Read.Read **/
    int play;

    printf("I'm thinking of a number. Care to make a guess?");
    again:
    printf("\nEnter a guess between 1 and 100:");
    printf("\n>");
    scanf("%d", &guess); /** %d kay for integer.. since ang guess kay integer siya dapat %d not %i **/
    guess;
    number;
    do
    {
        while(counter != 0)
        {
            if(guess > number)
        {
            if(guess-number < 10)
            {
                printf("\nLower. %d guesses left.\n", counter); /** No need nakag "&"(&counter) para e-display ang isa ka number **/
            }

            else if(guess-number >= 20)
            {
                printf("\nWay too high. %d guesses left.\n", counter);
            }

            else if(guess-number > 9)
            {
                printf("\nToo high. %d guesses left.\n", counter);
            }

            else

               goto again;
        }

        else
        {
            if(number-guess < 10)
            {
                printf("\nHigher. %d guesses left.\n", counter);
            }

            else if(number-guess >= 20)
            {
                printf("\nWay too low. %d guesses left.\n", counter);
            }

            else if(number-guess > 9)
            {
                printf("\nToo low. %d guesses left.\n", counter);
            }

            else

            goto again;
        }
        counter--; /** DECREMENT equal ra gihapon na siya sa [counter = counter - 1 or pwede sad counter -= 1]**/
        goto again; /** Para mukuha na pwd siyag bag.o nga input **/
        }

    } while(guess!=number);

    printf("\n%d is the correct answer.", guess);

    printf("\nWould you like to play again?");
    printf("\nPress 1 for YES");
    printf("\nPress 2 for NO");
    printf("\nYou've selected: ");
    scanf("%i", &play);

    if(play==1)
    {
        goto again;
    }

    else
    {
        printf("You chose not to continue.");
    }

 return 0;
}
