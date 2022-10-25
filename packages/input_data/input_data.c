#include <stdio.h>
#include <stdlib.h>
#include <fileapi.h>
#include "input_data.h"
#include "../filter/filter.h"
#include "../myTools/myTools.h"

void input(){
	char *command = (char*) malloc(sizeof(char) * 100);
	int i = 0, oldI, contSpaces = 0, contWords, wordSize;
	
	printf("[%s] -> ", getMaskPath());
	fgets(command, 100, stdin);
	
	if(strlen(command) == 0){
		interpretador(NULL, 0);
		return;
	}
	
	while(command[i] != '\n'){
		if(command[i] == ' ') contSpaces++;
		i++;
	}
	
	contWords = contSpaces + 1;
	
	char **words = (char**) malloc(sizeof(char*) * contWords);
	i = 0;
	for(int j = 0; j < contWords; j++){
		wordSize = 0;
		oldI = i;
		while(command[i] != ' ' && command[i] != '\n'){
			wordSize++;
			i++;
		}
		char *word = (char*) malloc(sizeof(char) * wordSize);	
		int k;
		int max = wordSize + oldI;
		for(k = 0; oldI < max; k++, oldI++){
			word[k] = j == 0 ? toupper(command[oldI]) : command[oldI];
		}
		word[wordSize] = '\0';
		words[j] = word;
		i++;		
	}
	
	interpretador(words, contWords);
}

char* upperString(char* word){
	char *newWord = (char*) malloc(sizeof(char) * strlen(word));
	int i = 0;
	while(word[i] != NULL){
		newWord[i] = toupper(word[i]);
		i++;
	}
	newWord[strlen(word)] = '\0';
	return newWord;
}
