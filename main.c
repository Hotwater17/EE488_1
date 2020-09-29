#include <main.h>

int main(int argc, char *argv[])
{

int textFileNumber = 0;
char path[100];
char textFiles[FILES_MAX][CELL_SIZE];
char searchedWord[128];
int wordMatchIndex;

record_t mainRecord;
mainRecord.index = 0;

printf("Path: %s \n", argv[1]);
strncpy(path, argv[1], sizeof(argv[1]));

textFileNumber = Files_Search_TXT(textFiles, path);

for(int cnt = 0; cnt < textFileNumber; cnt++)
{
 printf("Opened file: %s \n", textFiles[cnt]);
 Record_Scan_File(textFiles[cnt], path, &mainRecord, cnt);
}

Record_Display_All(&mainRecord);
while(Searcher_Get_Word(searchedWord)){};

if(Record_Search(&mainRecord, searchedWord, &wordMatchIndex) == 0) printf("Word not found! \n");
else Record_Display_Single(&mainRecord, textFiles, wordMatchIndex);

return 0;

}

