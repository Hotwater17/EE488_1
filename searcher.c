#include "searcher.h"



int Searcher_Get_Word(char * word)
{
 char keyword[] = "search";
 char delim[] = " ,-.\n\r";
 char *tmpStr;
 char tmpWord[128];
 char tmpKeyword[128];
 printf("Searcher> ");

 scanf("%s %[^\n]s", tmpKeyword, tmpWord);
  if(String_Compare(keyword, tmpKeyword)==0)
 {
  String_Copy(word, tmpWord, String_Get_Length(tmpStr));
  return 0;
 }
 else
 {
  printf("Unknown command! \n");
  return 1;
 }

}
