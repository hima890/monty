#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdio.h>
#define MAX_LINE_LENGTH 1000

/* Function prototype */
/* FILE *openThefiles(char *filePath); */

char *readFiles(FILE *filePointer);
char **tokenizeInput(char *lineBuffer);
char **duplicateStringArray(char **array);
void printInstructions(char **instructions);
void freeInstructions(char **instructions);

#endif
