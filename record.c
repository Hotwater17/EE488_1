#include "record.h"


void Record_Display_All(record_t *record)
{
 int cnt = 0;
 int subCnt = 0;
 char lineStr[128];
 char docStr[128];
 for(cnt = 0; cnt < record->index; cnt++)
 {
  //printf("%s in lines %s in docs %s \n", record->wordRecord[cnt],
  printf("%s occured %d times ", record->wordRecord[cnt], record->frequencyRecord[cnt]);
  for(subCnt = 0; subCnt < record->frequencyRecord[cnt]; subCnt++)
  {
   printf("(L:%d, D:%d, I:%d)", record->lineRecord[cnt][subCnt]+1, record->docRecord[cnt][subCnt], cnt);
  }
  printf("\n");
 }
}



void Record_Display_Single(record_t *record, char files[FILES_MAX][FILE_NAME_SIZE], int index)
{
 char lineStr[128];
 char docStr[128];
 int subCnt = 0;
 printf("Word %s found under index %d, occured %d times \n", record->wordRecord[index], index, record->frequencyRecord[index]);
 for(subCnt = 0; subCnt < record->frequencyRecord[index]; subCnt++)
 {
  printf("%s: line #%d \n", files[record->docRecord[index][subCnt]], record->lineRecord[index][subCnt]+1);
 }
}

void Record_Scan_File(char * fileName, char * path, record_t *record, int doc)
{

char delim[] = " ,.-?!;:'\n";
char * tempStr;
char tmpLine[128];
int wordCnt = 0;
int lineCnt = 0;
int matchIndex = 0;

char targetPathName[50];

String_Copy(targetPathName, path, /*sizeof(path)*/ String_Get_Length(path));
printf("%s %d \n", targetPathName, String_Get_Length(targetPathName));
printf("%s %d \n", fileName, String_Get_Length(fileName));
//String_Merge(targetPathName, fileName);
strcat(targetPathName, fileName);
printf("%s", targetPathName);
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



printf("End of file %s \n", targetPathName);

fclose(targetFile);

}



void Record_Add_New(record_t *record, char * word, int line, int doc)
{
 record->frequencyRecord[record->index] = 1;
 String_Copy(record->wordRecord[record->index], word, CELL_SIZE);
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
  if(String_Compare(word, record->wordRecord[cnt]) == 0)
  {
   *matchIndex = cnt;
   return 1;
  }
 }
 return 0;
}

