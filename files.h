
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#include "mystrings.h"

#ifndef FILES_H
#define FILES_H

#define FILES_MAX 30
#define FILE_NAME_SIZE 30

int Files_Search_TXT(char files[FILES_MAX][FILE_NAME_SIZE], char * dir);
void Files_Search_Extention(char * extention, char * fileName);

#endif

