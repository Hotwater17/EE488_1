#include "files.h"


int Files_Search_TXT(char files[FILES_MAX][FILE_NAME_SIZE], char * dir)
{
 char dirStr[128];
 struct dirent *dirEntry;
 char currentExt[10];
 DIR *dirStruct = opendir(dir);
 int fileNumber = 0;
 if(dirStruct == NULL)
 {
  printf("Could not open directory \n");
  exit(1);
 }

 while((dirEntry = readdir(dirStruct)) != NULL)
 {
  //printf("%s \n", dirEntry->d_name);
  String_Flush(currentExt, sizeof(currentExt));
  Files_Search_Extension(currentExt, dirEntry->d_name);
  //printf("Current extension: %s \n", currentExt);
  if(String_Compare(currentExt, ".txt") == 0)
  {
    String_Copy(files[fileNumber], dirEntry->d_name, 20);
    fileNumber++;
  }

 }

/*
 printf("Number of .txt files %d \n", fileNumber);

 for(int cnt = 0; cnt < fileNumber; cnt++)
 {
  printf("%s \n", files[cnt]);
 }
*/
 return fileNumber;

}

void Files_Search_Extension(char * extension, char * fileName)
{
 while(*fileName != '.')
 {
  fileName++;
 }
 while(*fileName)
 {
  *extension = *fileName;
  fileName++;
  extension++;
 }

}

