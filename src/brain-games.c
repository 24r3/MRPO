// Copyright 2024 Jamal K.
#include "headers/engine.h"

int main(void) {
    Init();
    GetName();
    char gameMode;
    while (1) {
        gameMode = GetGameMode('q');
        if (gameMode == 'q') {
            GameOver();
            break;
        }
        PlayGame(gameMode);
    }
    return 0;
}
