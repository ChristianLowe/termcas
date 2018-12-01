#include <stdio.h>
#include <stdlib.h>

#include "games.h"

int main(int argc, char const *argv[]) {
    enum GameStatus gameStatus;
    int money, bet, inputLen;

    initDice();
    money = 500;
    
    printf("Welcome to Terminal Casino! Your goal is come out with $5,000, or go bust trying.\n");

    while (money > 0 && money < 5000) {
        printf("\nYou currently have $%d. What's your bet?\n", money);
        inputLen = scanf("%d", &bet);

        if (inputLen < 0) {
            printf("Invalid bet amount. Please type in numbers only.\n");
            continue;
        }

        gameStatus = playCraps();

        switch (gameStatus) {
            case WON:
                printf("You earned $%d!\n", bet);
                money += bet;
                continue;
            case LOST:
                printf("You lost $%d.\n", bet);
                money -= bet;
                continue;
        };
    }

    if (money >= 5000) {
        printf("You have made out like a bandit with $%d in your pockets. Congrats!\n", money);
    } else {
        printf("You have lost all of your money, and now you owe the casino $%d.\n", -money);
    }

    return 0;
}
