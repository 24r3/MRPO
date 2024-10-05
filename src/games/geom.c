// Copyright 2024 Jamal K.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../headers/nok.h"

void Geom(char question[], char answer[])
{
    unsigned int ctime = time(NULL);
    int b = rand_r(&ctime) % (5) + 2;
    int count = rand_r(&ctime) % (7-5) + 5;
    int hiddenI = rand_r(&ctime) % (count);
    char str[32];
    int i, j, cur;
    int qP = 0;
    int prev = rand_r(&ctime) % (5) + 2;
    for (i = 0; i < count; ++i) {
        cur = b * prev;
        if (hiddenI == i) {
            itoa(cur, answer);
            question[qP++] = '.';
            question[qP++] = '.';
            question[qP++] = ' ';
        } else {
            itoa(cur, str);
            for (j = 0; str[j]; ++j)
                question[qP++] = str[j];
            question[qP++] = ' ';
        }
        prev = cur;
    }
    question[qP] = 0;
}
