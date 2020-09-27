#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>

#define RECORD_SIZE 5000
#define CELL_SIZE 30



char parseLine(char * array, char * linePtr);
void File_Words_Print(char * fileName, char * path, int documentNumber);
int Search_TXT(char array[20][CELL_SIZE], char * dir);
void Flush(char * array, int size);
void Search_Extention(char * extention, char * fileName);


typedef struct
{
 char wordRecord[RECORD_SIZE][CELL_SIZE];
 int lineRecord[RECORD_SIZE][CELL_SIZE];
 int docRecord[RECORD_SIZE][CELL_SIZE];
 int frequencyRecord[RECORD_SIZE];
 int index;
}record_t;


void Record_Display(record_t *record);
void Record_Scan_File(char * fileName, char * path, record_t *record, int doc);
void Record_Add_New(record_t *record, char * word, int line, int doc);
void Record_Update_Existing(record_t *record, int matchIndex, int line, int doc);
int Record_Search(record_t *record, char * word, int *matchIndex);


int main(int argc, char *argv[])
{

int textFileNumber = 0;
char path[100];
char textFiles[20][CELL_SIZE];
//char wordList[RECORD_SIZE][CELL_SIZE];

record_t mainRecord;
mainRecord.index = 0;

printf("Path: %s \n", argv[1]);
strncpy(path, argv[1], sizeof(argv[1]));

textFileNumber = Search_TXT(textFiles, path);

for(int cnt = 0; cnt < textFileNumber; cnt++)
{
 printf("Opened file: %s \n", textFiles[cnt]);
 Record_Scan_File(textFiles[cnt], path, &mainRecord, cnt+1);
}

//TODO: also try to display file name in Record_Display. That is, create a typedef array.
//The array will hold file names under specific indexes
//Record_Scan_File("Friends.txt", path, &mainRecord, 1);
Record_Display(&mainRecord);

return 0;

}

void Record_Display(record_t *record)
{
 int cnt = 0;
 int subCnt = 0;
 char lineStr[128];
 char docStr[128];
 for(cnt = 0; cnt < record->index; cnt++)
 {
  //printf("%s in lines %s in docs %s \n", record->wordRecord[cnt],
  printf("%s occured %d times ", record->wordRecord[cnt], record->frequencyRecord[cnt]); //Need to correct by 1 to display frequency of occurence correctly
  for(subCnt = 0; subCnt < record->frequencyRecord[cnt]; subCnt++)
  {
   printf("(L:%d, D:%d)", record->lineRecord[cnt][subCnt]+1, record->docRecord[cnt][subCnt]);
  }
  printf("\n");
 }
}

void Record_Scan_File(char * fileName, char * path, record_t *record, int doc)
{

//char wordMap[5000][30];
//int lineNumber[5000];
char delim[] = " ,.-?!;:'\n";
char * tempStr;
char tmpLine[128];
int wordCnt = 0;
int lineCnt = 0;
int matchIndex = 0;

char targetPathName[50];

strncpy(targetPathName, path, sizeof(path));
strcat(targetPathName, fileName);

FILE *targetFile = fopen(targetPathName, "r");
if(targetFile == NULL)
{
 printf("Error opening the file \n");
 exit(1);
}

while(fgets(tmpLine, 128, targetFile) != NULL)
{

 tempStr = strtok(tmpLine, delim);
 while(tempStr != NULL)
 {
  if(Record_Search(record, tempStr, &matchIndex) == 0)
  {
   Record_Add_New(record, tempStr, lineCnt, doc);
  }
  else
  {
   Record_Update_Existing(record, matchIndex, lineCnt, doc);
  }
  tempStr = strtok(NULL, delim); //Continue searching from last delimiter
  wordCnt++;
 }

 lineCnt++;
}

/*
int cnt = 0;
while(cnt < wordCnt)
{
 printf("Word number %d, %s \n", cnt, record->wordRecord[cnt]);
 cnt++;
}
*/
printf("End of file %s \n", targetPathName);

fclose(targetFile);

}

void Record_Add_New(record_t *record, char * word, int line, int doc)
{
 record->frequencyRecord[record->index] = 1;
 strncpy(record->wordRecord[record->index], word, CELL_SIZE);
 record->lineRecord[record->index][record->frequencyRecord[record->index]-1] = line;
 record->docRecord[record->index][record->frequencyRecord[record->index]-1] = doc;
 record->index++;
}

void Record_Update_Existing(record_t *record, int matchIndex, int line, int doc)
{
 record->frequencyRecord[matchIndex]++;
 record->lineRecord[matchIndex][record->frequencyRecord[matchIndex]-1] = line;
 record->docRecord[matchIndex][record->frequencyRecord[matchIndex]-1] = doc;
}

int Record_Search(record_t *record, char * word, int *matchIndex)
{
 int cnt = 0;
 for(cnt = 0; cnt < record->index; cnt++)
 {
  if(strcmp(word, record->wordRecord[cnt]) == 0)
  {
   *matchIndex = cnt;
   return 1;
  }
 }
 return 0;
}

void File_Words_Print(char * fileName, char * path, int documentNumber)
{
char wordMap[5000][30];
int lineNumber[5000];
char delim[] = " ,.-?!;:\n";
char * tempStr;
char tmpLine[128];
int wordCnt = 0;
int lineCnt = 0;

char targetPathName[50];

strncpy(targetPathName, path, sizeof(path));
strcat(targetPathName, fileName);

FILE *targetFile = fopen(targetPathName, "r");
if(targetFile == NULL)
{
 printf("Error opening the file \n");
 exit(1);
}

while(fgets(tmpLine, 128, targetFile) != NULL)
{
 //printf("Line %d : %s \n", lineCnt, tmpLine);
 tempStr = strtok(tmpLine, delim);
 while(tempStr != NULL)
 {
  //printf("%s \n", tempStr);
  strncpy(wordMap[wordCnt], tempStr, 30);
  lineNumber[wordCnt] = lineCnt;
  tempStr = strtok(NULL, delim); //Continue searching from last delimiter
  wordCnt++;
 }

 lineCnt++;
}

int cnt = 0;
while(cnt < wordCnt)
{
 printf("Word number %d, '%s' ", cnt, wordMap[cnt]);
 printf(" in line %d in document %d \n", lineNumber[cnt], documentNumber);
 cnt++;
}
printf("End of file \n");

fclose(targetFile);

}

int Search_TXT(char txtFiles[20][CELL_SIZE], char * dir)
{
 char dirStr[128];
 //char txtFiles[20][20];
 /*printf("Enter directory path \n");
 scanf("%s", dirStr);*/
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
  printf("%s \n", dirEntry->d_name);
  Flush(currentExt, sizeof(currentExt));
  Search_Extention(currentExt, dirEntry->d_name);
  printf("Current extention: %s \n", currentExt);
  if(strcmp(currentExt, ".txt") == 0)
  {
    strncpy(txtFiles[fileNumber], dirEntry->d_name, 20);
    fileNumber++;
  }

 }


 printf("Number of .txt files %d \n", fileNumber);

 for(int cnt = 0; cnt < fileNumber; cnt++)
 {
  printf("%s \n", txtFiles[cnt]);
 }

 return fileNumber;

}

void Search_Extention(char * extention, char * fileName)
{
 while(*fileName != '.')
 {
  fileName++;
 }
 while(*fileName)
 {
  *extention = *fileName;
  fileName++;
  extention++;
 }

}

void Flush(char * array, int size)
{
 for(int cnt = 0; cnt < size; cnt++)
 {
  array[cnt] = '\0';
  //array++;
 }
}


/*
char parseLine(char * array, char * linePtr)
{



while(*linePtr != 0)
{
 if((*linePtr == ' ') || (*linePtr == ',')) return linePtr;

 if(*linePtr != 0)
 {
   *array = *linePtr;
  array++;
 }

}

}
*/
