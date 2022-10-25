#ifndef MYTOOLS_H
#define MYTOOLS_H
#include <stdio.h>

static char *maskPath;


void initMyTools();
char* getPath();
char* getMaskPath();
char* getAllPath();
void setMaskPath(char*, char*);
void resetMaskPath();
int isValidDir();
int isValidFile(char*);
int isValidCustomDir(char*);
int isValidCustomFile(char*);
char* getMessage(char**, int);
char* removeQuotes(char*);
char* dataFromFile(FILE*);
FILE* openFile(char*, char*);
char intToChar(int);
char* intToString(int);

#endif
