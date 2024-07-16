#ifndef SOUNDEX_H
#define SOUNDEX_H


#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

int consonantcode1() { return 1; } 
int consonantcode2() { return 2; }
int consonantcode3() { return 3; }
int consonantcode5() { return 5; }
int consonantcode4() { return 4;}
int consonantcode6() { return 6;}
int vowelcode() { return 0; }

typedef struct {
    char value[10];
    int (*getcodefunc)();
} soundexcode;

//If the letter matches with the value array return 1 or else return 0
int getcode(const char *values, char letter) {
    for (int j = 0; values[j] != '\0'; j++) {
        if (values[j] == letter) {
            return 1;
        }
    }
    return 0;
}

int getSoundexCode(char letter) {
    static soundexcode code[] = {
        {{'B','F','P','V', '\0'}, consonantcode1},
        {{'C','G','J','K','Q','S','X','Z', '\0'}, consonantcode2},
        {{'D','T', '\0'}, consonantcode3},
        {{'M','N', '\0'}, consonantcode5},
        {{'A','E','I','O','U','H','W','Y', '\0'}, vowelcode},
        {{'L','\0'},consonantcode4},
        {{'R','\0'},consonantcode6}
    };

    for (int i = 0; i < 7; i++) {
        if(getcode(code[i].value, letter)){
            return code[i].getcodefunc();
        }
    }
}
bool isVowel(int code,char *soundex,int a,int i,const char *name)
{
    return((getSoundexCode(toupper(name[i]))==0) && name[i] != 'h' && name[i]!='w');
}

bool isVowelCode(int code,char *soundex,int a)
{

   return ( code != 0 && code == (soundex[a-1] - '0'));
}

bool vowelcalc(int code,char *soundex,int a,int i,const char *name)
{
    return (isVowel(code,soundex,a,i,name) && isVowelCode(code,soundex,a));
}

bool isConsonantCode(int code,char *soundex,int a)
{

   return ( code != 0 && code != (soundex[a-1] - '0'));
}

int shouldAddCode(int code, char *soundex, int a,int i,const char *name) {
    if(vowelcalc(code,soundex,a,(i-1),name) || (isConsonantCode(code,soundex,a)))
    {
        (soundex[a++] = '0' + code);
        return a;
    }
    return a;
}

bool istrue(int i,int sIndex,int len)
{
    return ((i < len) && (sIndex < 4));
}


void generateSoundex(const char *name, char *soundex) {
    int len = strlen(name);
    soundex[0] = toupper(name[0]);
    soundex[0] = '0' + getSoundexCode(toupper(name[0]));
    int sIndex = 1;
    //int conditon;

    for (int i = 1;(istrue(i,sIndex,len)); i++) {
        int code = getSoundexCode(toupper(name[i]));
        sIndex=(shouldAddCode(code, soundex, sIndex,i,name));  // Convert int to char
        
    }
    
    while (sIndex < 4) {
        soundex[sIndex++] = '0';
    }

    soundex[4] = '\0';
    soundex[0] = toupper(name[0]);
}

#endif // SOUNDEX_H
