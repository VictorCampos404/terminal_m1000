#include <stdio.h>
#include <stdlib.h>
#include <fileapi.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include "profiles.h"
#include "../myTools/myTools.h"
#include "../commands/commands.h"

void initProfiles(){
	allProfilePath = (char*)calloc(sizeof(char), 300);
	strcat(strcpy(allProfilePath, getPath()), "profiles\\allProfiles");
	nProfiles = 0;

	char **profiles = getAllProfiles();
	if(profiles == NULL){
		criarPerfil(profiles);
	}else{
		escolherPerfil(profiles);
	}
}

void criarPerfil(char **profiles){
	char *profile_id = (char*) malloc(sizeof(char) * 50);
	char *name = (char*) malloc(sizeof(char) * 50);
	char *password = (char*) malloc(sizeof(char) * 50);
	
	strcat(strcpy(profile_id, "profile_"), intToString(nProfiles+1));
	
	printf("Novo profile:\n");
	printf("Profile id: %s\n", profile_id);
	printf("Nome: ");
	fgets(name, 50, stdin);
	name[strlen(name)-1] = '\0';
	printf("Senha: ");
	fgets(password, 50, stdin);
	password[strlen(password)-1] = '\0';
	
	char* path = (char*)calloc(sizeof(char), 300);
	strcat(strcpy(path, getPath()), "profiles\\");
	
	criar("-d", profile_id, path);
	
	strcat(path, profile_id);
	strcat(path, "\\");
	
	criar("-a", "name", path);
	criar("-a", "password", path);
	
	
	printf("Perfil Criado!\n\n");
}

void escolherPerfil(char **profiles){
	printf("Escolher perfil!\n\n");
}

char** getAllProfiles(){
	FILE *fl;
	int contProfiles = 0, inc = 0;
    if((fl = openFile(allProfilePath, "r")) == NULL)
    {
        printf("Erro na abertura dos profiles!\n\n");
        return NULL;
    }else{
	    char *m = dataFromFile(fl);
	    if(strcmp(m, "") == 0){
	    	free(m);
	    	fclose(fl);
	    	return NULL;
		}else{
			for(int i = 0; i < strlen(m); i++){
				if(m[i] == ' ') contProfiles++;
			}
			contProfiles++;
			nProfiles = contProfiles;
			
			char **profiles = (char**) malloc(sizeof(char*) * contProfiles);
			for(int i = 0; i < contProfiles; i++){
				char *profile = (char*) malloc(sizeof(char) * 50);
				
				int k = 0;
				while(m[inc] != ' ' && m[inc] != '\0'){
					profile[k] = m[inc];
					k++;
					inc++;
				}
				inc++;
				profile[strlen(profile)-1] = '\0';
				
				profiles[i] = profile;
			}
			
			free(m);
	    	fclose(fl);
	   		return profiles;		
		}
		
	}
}
