#include <stdio.h>

#ifndef MYSTRINGS_H
#define MYSTRINGS_H


void String_Flush(char * array, int size);

void String_Copy(char *src, char *dst, int length);

void String_Merge(char *dst, char *src);

int String_Compare(char *src, char *dst);

int String_Get_Length(char *src);

int String_Find_Character(char *array, char key);

char * String_Tokenize(char *src, char *dst, char *delimiter);

#endif


