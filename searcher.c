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
 //scanf("%s", tmpWord);
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

/*
 fgets(tmpWord, 50, stdin);



 printf("word %s \n", tmpWord);
 tmpStr = strtok(tmpWord, delim);

 if(String_Compare(keyword,tmpStr) == 0)
  {
   printf("str %s \n", tmpStr);
   printf("word %s \n", tmpWord);
   tmpStr = strtok(NULL, delim);
   printf("Searching word %s \n", tmpStr);
   String_Copy(word, tmpStr, String_Get_Length(tmpStr));
   return 0;
  }

  else
  {
   printf("Unknown command! \n");
   return 1;
  }
*/

//scanf("%s", word);
//return 0;
}
