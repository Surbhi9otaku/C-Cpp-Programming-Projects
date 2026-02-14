#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    int player, computer;
   /*
    0 --> Snake
    1 --> Water 
    2 --> Gun 
    */

   srand(time(0));
   computer = rand() % 3;

   printf("Choose 0 for Snake, 1 for Water, 2 for Gun:\n ");
   scanf("%d", &player);
   printf("%d", computer);

   if (player == 0 && computer == 0) {
       printf("It's a Draw!\n");
   }
   else if (player == 0 && computer == 1) {
       printf("You Win!\n");
   }
   else if (player == 0 && computer == 2) {
       printf("You Lose!\n");
   }
   else if (player == 1 && computer == 0) {
       printf("You Lose!\n");
   }
   else if (player == 1 && computer == 1) {
       printf("It's a Draw!\n");
   }
   else if (player == 1 && computer == 2) {
       printf("You Win!\n");
   }
   else if (player == 2 && computer == 0) {
       printf("You Win!\n");
   }
   else if (player == 2 && computer == 1) {
       printf("You Lose!\n");
   }
   else if (player == 2 && computer == 2) {
       printf("It's a Draw!\n");
   }
   else {
        printf("Invalid Input! Please choose 0, 1, or 2.\n");
   }
    return 0;
}
