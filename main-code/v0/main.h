#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdio.h>

/* Function prototype */
int checkArguments(int argc);
char **tokenizeInput(char *lineBuffer);
char **duplicateStringArray(char **array);
void printInstructions(char **instructions);
void freeInstructions(char **instructions);
FILE *openfiles(const char *filePath);
char *my_strdup(const char *original);

#endif
