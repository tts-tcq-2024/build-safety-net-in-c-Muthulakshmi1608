#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int case1() { return 1; }
int case2() { return 2; }
int case3() { return 3; }
int case5() { return 5; }
int case4() { return 4;}
int case6() { return 6;}
int defaultCase() { return 0; }

typedef struct {
    char value[10];
    int (*func)();
} CaseEntry;

int getSoundexCode(char letter) {
    static CaseEntry cases[] = {
        {{'B','F','P','V', '\0'}, case1},
        {{'C','G','J','K','Q','S','X','Z', '\0'}, case2},
        {{'D','T', '\0'}, case3},
        {{'M','N', '\0'}, case5},
        {{'A','E','I','O','U','H','W','Y', '\0'}, defaultCase},
        {{'L','\0'},case4},
        {{'R','\0'},case6}
    };

    for (int i = 0; i < 7; i++) {
        int j = 0;
        while (cases[i].value[j] != '\0') {
            if (cases[i].value[j] == letter) {
                return cases[i].func();
            }
            j++;
        }
    }

    return defaultCase();
}

void generateSoundex(const char *name, char *soundex) {
    int len = strlen(name);
    soundex[0] = toupper(name[0]);
    int sIndex = 1;

    for (int i = 1; i < len && sIndex < 4; i++) {
        int code = getSoundexCode(toupper(name[i]));
        if (code != 0 && code != soundex[sIndex - 1]) {
            soundex[sIndex++] = '0' + code;  // Convert int to char
        }
    }

    soundex[4] = '\0';
}

#endif // SOUNDEX_H
