#include <stdio.h>
#include <string.h>
#include <files.h>

#ifndef RECORD_H
#define RECORD_H

#define RECORD_SIZE 3000
#define CELL_SIZE 200


typedef struct
{
 char wordRecord[RECORD_SIZE][CELL_SIZE];
 int lineRecord[RECORD_SIZE][CELL_SIZE];
 int docRecord[RECORD_SIZE][CELL_SIZE];
 int frequencyRecord[RECORD_SIZE];
 int index;
}record_t;



void Record_Display_All(record_t *record);
void Record_Display_Single(record_t *record, char files[FILES_MAX][FILE_NAME_SIZE], int index);
void Record_Scan_File(char * fileName, char * path, record_t *record, int doc);
void Record_Add_New(record_t *record, char * word, int line, int doc);
void Record_Update_Existing(record_t *record, int matchIndex, int line, int doc);
int Record_Search(record_t *record, char * word, int *matchIndex);

#endif
