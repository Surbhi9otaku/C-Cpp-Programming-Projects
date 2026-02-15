#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Initialize random number generator
    srand(time(0));

    // Generate random number between 1 and 100
    int randomNumber = (rand() % 100) + 1;
    int no_of_guesses = 0;
    int guessed_number;


    do {
        printf("Guess the number (between 1 and 100): ");
        scanf("%d", &guessed_number);
        no_of_guesses++;

        if (guessed_number > randomNumber) {
            printf("Lower number please!\n");
        } else if (guessed_number < randomNumber) {
            printf("Higher number please!\n");
        } else {
            printf("Congrats!!\n");
            printf("You guessed the number in %d attempts.\n", no_of_guesses);
        }
    } while (guessed_number != randomNumber);

    return 0;
}
