#include "strings.h"

void Flush(char * array, int size)
{
 for(int cnt = 0; cnt < size; cnt++)
 {
  array[cnt] = '\0';

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

