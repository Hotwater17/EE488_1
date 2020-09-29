#include "searcher.h"



int Searcher_Get_Word(char * word)
{
 char keyword[] = "search";
 char delim[] = " ";
 char *tmpStr;
 char tmpWord[128];
 printf("Searcher> ");
 scanf("%s", tmpWord);
/*
 tmpStr = strtok(tmpWord, delim);
  if(strcmp(keyword,tmpStr) == 0)
  {
   tmpStr = strtok(NULL, delim);
   printf("Searching word %s \n", tmpStr);
   strncpy(word, tmpStr, CELL_SIZE);
   return 0;
  }
  else
  {
   printf("Unknown command! \n");
   return 1;
  }
*/
 strncpy(word, tmpWord, CELL_SIZE);
 return 0;
}
