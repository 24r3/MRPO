// Copyright 2024 Jamal K.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NOK_NUMBER 20
#define MULTS_SIZE 5  // round_down(log2(MAX_NOK_NUMBER)) + 1
#define MIN_NOK_COUNT 3
#define MAX_NOK_COUNT 3

int primeTable[MAX_NOK_NUMBER + 1];

void decompose(int n, int res[]) {
    int i = 0;
    int p = 0;
    res[0] = 0;
    while (n != 1) {
        for (i = 2; i <= n; ++i) {
            if (primeTable[i] && n % i == 0) {
                res[p++] = i;
                n /= i;
                break;
            }
        }
    }
    res[p] = 0;
}

void setPrimeTable(void) {
    primeTable[2] = 1;
    int i, j;
    for (i = 3; i <= MAX_NOK_NUMBER; ++i) {
        primeTable[i] = 1;
        for (j = 2; j < i; ++j) {
            if (primeTable[j] && i % j == 0) {
                primeTable[i] = 0;
                break;
            }
        }
    }
}

void mergeMults(int unitedMults[], int mults[]) {
    int uP, mP;
    uP = 0;
    mP = 0;
    int i, prev, temp;
    while (1) {
        if (mults[mP] == 0)
            break;
        if (unitedMults[uP] == 0) {
            unitedMults[uP++] = mults[mP++];
            unitedMults[uP] = 0;
            continue;
        }
        if (unitedMults[uP] == mults[mP]) {
            ++uP;
            ++mP;
            continue;
        }
        if (unitedMults[uP] < mults[mP]) {
            ++uP;
            continue;
        }
        prev = mults[mP];
        for (i = uP; unitedMults[i] != 0; ++i) {
            temp = unitedMults[i];
            unitedMults[i] = prev;
            prev = temp;
        }
        unitedMults[i] = prev;
        unitedMults[i + 1] = 0;
        ++uP;
        ++mP;
    }
}

void itoa(int val, char *buf) {
    int i;
    for (i = 31; val != 0; --i) {
        buf[i] = "0123456789"[val % 10];
        val /= 10;
    }
    ++i;
    int diff = i;
    for (; i < 32; ++i) {
        buf[i - diff] = buf[i];
    }
    buf[i - diff] = 0;
}

void InitNOK(void) {
    setPrimeTable();
}

void NOK(char question[], char answer[]) {
    unsigned int ctime = time(NULL);
    int unitedMults[MULTS_SIZE * MAX_NOK_COUNT];
    int mults[MULTS_SIZE + 1];
    char str[32];
    int count;
    int i, j, n;
    int qP = 0;
    unitedMults[0] = 0;
    count = rand_r(&ctime) % (MAX_NOK_COUNT + 1 - MIN_NOK_COUNT) + MIN_NOK_COUNT;
    for (i = 0; i < count; ++i) {
        n = rand_r(&ctime) % (MAX_NOK_NUMBER - 2) + 2;
        decompose(n, mults);
        mergeMults(unitedMults, mults);
        itoa(n, str);
        for (j = 0; str[j]; ++j)
            question[qP++] = str[j];
        question[qP++] = ' ';
    }
    question[qP - 1] = '.';
    question[qP] = 0;
    int result = 1;
    for (i = 0; unitedMults[i]; ++i)
        result *= unitedMults[i];
    itoa(result, answer);
}
