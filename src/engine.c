// Copyright 2024 Jamal K.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/geom.h"
#include "headers/nok.h"

char name[32];

char* GetName(void) {
    printf("Welcome to the Brain Games! May I have your name? ");
    fgets(name, sizeof(name), stdin);
    name[strlen(name) - 1] = 0;
    printf("Hello, %s!\n", name);
    return name;
}

char ask(char *question, char *correctAnswer) {
    printf("%s\nYour answer: ", question);
    char response[30];
    fgets(response, sizeof(response), stdin);
    response[strlen(response) - 1] = 0;
    if (!strcmp(response, correctAnswer)) {
        printf("Is correct!\n");
        return 0;
    } else {
        printf("Is wrong ;(. Correct answer was: %s. ", correctAnswer);
        printf("Let's try again, %s\n", name);
        return 20;
    }
}

char GetGameMode(char stopCode) {
    char input[32];
    input[0] = 0;
    while ((input[0] != '1') && (input[0] != '2') 
            && (input[0] != stopCode)) {
        printf("\nWhat should we play?\n1) NOK\n2) Progression\n>>>");
        fgets(input, sizeof(input), stdin);
    }
    return input[0];
}

int PlayGame(char gamemode) {
    if (gamemode == '1')
        NOKMeet();
    else
        GeomMeet();
    int i, response; 
    char question[512], answer[32];
    for (i = 0; i < 3; ++i) {
        if (gamemode == '1')
            NOK(question, answer);
        else
            Geom(question, answer);
        response = ask(question, answer);
        if (response == 20)
            break;
    }
    if (response != 20) {
        printf("Congratulations, %s!\n", name);
    }
    return response;
}

void GameOver(void) {
    printf("Bye!\n");
}

void Init(void) {
    InitNOK();
}