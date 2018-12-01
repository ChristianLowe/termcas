#include "dice.h"

void initDice() {
    srand(time(NULL));
}

int diceRoll() {
    return 1 + rand() % 6;
}

int doubleDiceRoll() {
    int firstRoll = diceRoll();
    int secondRoll = diceRoll();
    int totalRoll = firstRoll + secondRoll;

    printf("Player rolled a %d (%d+%d).\n", totalRoll, firstRoll, secondRoll);
    return totalRoll;
}