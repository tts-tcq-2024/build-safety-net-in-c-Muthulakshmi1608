#ifndef SOUNDEX_H
#define SOUNDEX_H


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

int findInCase(const char *values, char letter) {
    for (int j = 0; values[j] != '\0'; j++) {
        if (values[j] == letter) {
            return 1;
        }
    }
    return 0;
}

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

    for (int i = 0; i < 5; i++) {
        if(findInCase(cases[i].value, letter)){
            return cases[i].func();
        }
    }
}

int shouldAddCode(int code, char *soundex, int a) {
    if( code != 0 && code != soundex[a-1])
    {
        (soundex[a++] = '0' + code);
        return a;
    }
    return a;
}

void generateSoundex(const char *name, char *soundex) {
    int len = strlen(name);
    soundex[0] = toupper(name[0]);
    int sIndex = 1;

    for (int i = 1; i < len && sIndex < 4; i++) {
        int code = getSoundexCode(toupper(name[i]));
        sIndex=(shouldAddCode(code, soundex, sIndex));  // Convert int to char
        
    }

    soundex[4] = '\0';
}

#endif // SOUNDEX_H
