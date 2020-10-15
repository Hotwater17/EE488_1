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


void String_Merge(char *dst, char *src)
{
 String_Copy(dst+String_Get_Length(dst), src, String_Get_Length(src)+1);
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
 while(*str != '\0')
 {
  str++;
  cnt++;
 }

 return cnt;
}

char * String_Tokenize(char *src, char *dst, char *delimiter)
{
 int cnt = 0;
 int subCnt = 0;
 int isFirstDelimDetected = 0;
 int isCurrentCharDelim = 0;
 char *startPtr;
 startPtr = src;


 //add an old pointer to the start and a new pointer to the place where you finished(where a delim was)
 while(*src != '\0')
 {
  isCurrentCharDelim = 0;
  for(subCnt = 0; subCnt < String_Get_Length(delimiter); subCnt++)
  {
   if(*src == delimiter[subCnt])
   {
    if(isFirstDelimDetected == 0) isFirstDelimDetected = 1;
    isCurrentCharDelim = 1;
    *src = '\0';
    //printf("%s \n", startPtr);
    printf("%d \n", String_Get_Length(startPtr));
    String_Copy(dst, startPtr, String_Get_Length(startPtr)+1);
    printf("%s \n", dst);
    return src+1;
   }
  }
 }

return NULL;

}

