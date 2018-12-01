#include "games.h"

enum GameStatus playCraps() {
    enum GameStatus gameStatus;
    int firstRoll, currentRoll;
    
    gameStatus = PLAYING;
    firstRoll = doubleDiceRoll();

    switch (firstRoll) {
        case 7: case 11:
            gameStatus = WON;
            break;
        case 2: case 3: case 12:
            gameStatus = LOST;
            break;
        default:
            printf("Player's point is %d.\n", firstRoll);
            break;
    }

    while (gameStatus == PLAYING) {
        currentRoll = doubleDiceRoll();

        if (currentRoll == firstRoll) {
            printf("Player made their point.\n");
            gameStatus = WON;
        } else if (currentRoll == 7) {
            gameStatus = LOST;
        }
    }

    if (gameStatus == WON) {
        printf("Game over. You won!\n");
    } else {
        printf("Game over. The house won.\n");
    }

    return gameStatus;
}
