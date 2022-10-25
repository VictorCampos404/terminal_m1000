#include <stdio.h>
#include <stdlib.h>
#include <fileapi.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include "myTools.h"



void initMyTools(){
  	maskPath = (char*)calloc(sizeof(char), 150);
  	strcpy(maskPath, "M1000_OS");
  	
}

char* getPath(){
  int maxSize = 150;
  char* path = (char*)calloc(sizeof(char), 150);
  getcwd(path, maxSize);

  path = strcat(path, "\\");
  return path;
}

char* getMaskPath(){
	char* path = (char*)calloc(sizeof(char), 150);	
	strcpy(path, maskPath);
  	return path;
}

char* getAllPath(){
  char* allPath = (char*)calloc(sizeof(char), 300);
  strcat(strcpy(allPath, getPath()), maskPath);
  allPath = strcat(allPath, "\\");
  return allPath;
}

void setMaskPath(char *arg, char *dir){
	if(strcmp(arg, "-a") == 0){
		maskPath = strcat(maskPath, "\\");
		maskPath = strcat(maskPath, dir);
	}else{
		int size = strlen(maskPath);
		for(int i = size - 1; i >= 0; i--){
			if(maskPath[i] == '\\'){
				maskPath[i] = '\0';
				i = -1;
			}
		}
	}
}

void resetMaskPath(){
	int size = strlen(maskPath);
	for(int i = size - 1; i >= 0; i--){
		if(maskPath[i] == '\\'){
			maskPath[i] = '\0';
		}
	}	
}

int isValidDir() {
  char* fullPath = getAllPath();
  DWORD dwAttrib = GetFileAttributes(fullPath);

  free(fullPath);

  return (dwAttrib != INVALID_FILE_ATTRIBUTES &&
         (dwAttrib & FILE_ATTRIBUTE_DIRECTORY));
}

int isValidFile(char* name) {
  char* fullPath = strcat(getAllPath(), name);
  DWORD dwAttrib = GetFileAttributes(fullPath);

  free(fullPath);

  return (dwAttrib != INVALID_FILE_ATTRIBUTES &&
         (dwAttrib & FILE_ATTRIBUTE_ARCHIVE));
}

int isValidCustomDir(char* dir){
  DWORD dwAttrib = GetFileAttributes(dir);

  return (dwAttrib != INVALID_FILE_ATTRIBUTES &&
         (dwAttrib & FILE_ATTRIBUTE_DIRECTORY));
}

int isValidCustomFile(char* dir){
  DWORD dwAttrib = GetFileAttributes(dir);

  return (dwAttrib != INVALID_FILE_ATTRIBUTES &&
         (dwAttrib & FILE_ATTRIBUTE_ARCHIVE));
}

char* getMessage(char** command, int size){
	char* text = (char*)calloc(sizeof(char), 600);
	strcpy(text, "");
	
	for(int i = 2; i < size; i++){
		if(i == 2 || i == size-1) strcat(text, removeQuotes(command[i]));
		else strcat(text, command[i]);
		
		if(i != size-1){
			strcat(text, " ");
		}
	}
	
	
	
	return text;
}

char* removeQuotes(char* word){
	int size = strlen(word);
	
	char* newWord = (char*)calloc(sizeof(char), size);
	
	int i = 0, j = 0;
	while(word[i] != NULL){
		if(word[i] != '\"'){
			newWord[j] = word[i];
			j++;
		}
		i++;
	}
	newWord[size] = '\0';
	return newWord;
}

char* dataFromFile(FILE* fl){
	int c, i = 0;
	char* data = (char*)calloc(sizeof(char), 600);
	while((c = fgetc(fl)) != EOF){
		data[i] = c;
		i++;
	}
	data[strlen(data)] = '\0';
	
	return data;
}

FILE* openFile(char* path, char* type){
	FILE *fl;
	fl = fopen(path, type);
   	return fl;
}

char intToChar(int n){
	switch(n){
		case 1: return '1'; break;
		case 2: return '2'; break;
		case 3: return '3'; break;
		case 4: return '4'; break;
		case 5: return '5'; break;
		case 6: return '6'; break;
		case 7: return '7'; break;
		case 8: return '8'; break;
		case 9: return '9'; break;
		case 0: return '0'; break;
	}
}

char* intToString(int n){
	
	int x, cont = 0, copy = n;

    while (copy != 0) {
        x = copy % 10;
        copy  = copy / 10;
        cont++;
        
    }
    
	char* number = (char*)calloc(sizeof(char), cont);
	copy = n;
	
	while (copy != 0) {
        x = copy % 10;
        copy  = copy / 10;
        
        number[cont-1] = intToChar(x);
        cont--;
    }
    
    return number;
	
}
