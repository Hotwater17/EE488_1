#include "mystrings.h"

void String_Flush(char * array, int size)
{
 for(int cnt = 0; cnt < size; cnt++)
 {
  array[cnt] = '\0';

 }
}

void String_Copy(char *dst, char *src, int length)
{
 int cnt = 0;
 for(cnt = 0; cnt < length; cnt++)
 {
  dst[cnt] = src[cnt];
 }
}

char * String_Tokenize(char *src, char *delimiter)
{
 
}

void String_Merge(char *dst, char *src)
{
 String_Copy(dst+String_Get_Length(dst), src, String_Get_Length(dst));
}

int String_Compare(char *str1, char *str2)
{
 int cnt = 0;
 while(str1[cnt] != '\0')
 {
  if(str1[cnt] != str2[cnt]) return 1;
  cnt++;
 }
 if(str2[cnt] != '\0') return 1;
 else return 0;
}

int String_Get_Length(char *str)
{
 int cnt = 0;
 do
 {
  cnt++;
 }while(str[cnt] != '\0');
 return cnt;
}
