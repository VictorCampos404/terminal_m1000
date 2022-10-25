#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fileapi.h>
#include <windows.h>
#include "commands.h"
#include "myConsts.h"
#include "input_data.h"
#include "myTools.h"

int criar(char *arg, char *name, char* path){
	char *newPath = (char*)calloc(sizeof(char), 300);
	strcat(strcpy(newPath, path == NULL ? getAllPath() : path), name);
	
	if(strcmp(arg, "-d") == 0){
		int isSuccessful = CreateDirectoryA(newPath, NULL);
	    if (isSuccessful == error) {
	      printf(erroPastaRepitida);
	    } else {
	      abrirDir(name);
	    }
	}else if(strcmp(arg, "-a") == 0){
		HANDLE fileHandle = CreateFileA(
	      newPath,
	      GENERIC_READ | GENERIC_WRITE,
	      0,
	      NULL,
	      CREATE_NEW,
	      FILE_ATTRIBUTE_NORMAL,
	      NULL
	    );
	    if (fileHandle == INVALID_HANDLE_VALUE) {
	      printf(erroArquivoRepitido);
	    } else {
	      printf("O arquivo '%s' foi criado com sucesso!\n\n", name);
	    }
	    CloseHandle(fileHandle);
	}else{
		printf(erroSintaxeCriar);
	}
	return 0;
}

int inserir(char *arq, char *message, char* arg){	
	char* path = (char*)calloc(sizeof(char), 300);
  	strcat(strcpy(path, getAllPath()), arq);
  	
  	if (isValidCustomFile(path) == success) {
	    FILE* file = fopen(path, arg);
    	fputs(message, file);
    	fclose(file);
   	 	printf("Os dados foram inseridos no arquivo com sucesso!\n\n");
	} else {
		printf("O arquivo '%s' nao foi encontrado!\n\n", arq);
	}
  	
	return 0;
}

int ler(char* arq){
	char* path = (char*)calloc(sizeof(char), 300);
  	strcat(strcpy(path, getAllPath()), arq);
  	
  	if (isValidCustomFile(path) == success) {
	    FILE *fl;
		
		fl = fopen(path, "r");
	    if(fl == NULL)
	    {
	        printf("Erro na abertura do aquivo!\n\n");
	    }else{
		    char *m = dataFromFile(fl);
		    printf("Aquivo: %s\nData: %s\n\n", arq, m);
		    fclose(fl);
		}
	    
		
	} else {
		printf("O arquivo '%s' nao foi encontrado!\n\n", arq);
	}
  	
  	
}

int listar(){
	
  if (isValidDir() == success) {
    char* command = (char*)calloc(sizeof(char), 400);
    strcpy(command, "dir ");
    strcat(command, getAllPath());
    system(command);
    free(command);
    printf("\n");
  } else {
    printf(erroDir);
  }

	return 0;
}

int renomear(char *oldName, char *newName){
	
	char* oldPath = (char*)calloc(sizeof(char), 300);
  	strcat(strcpy(oldPath, getAllPath()), oldName);
  	
	char* fullCommand = (char*)calloc(sizeof(char), 400);
	
	if (isValidCustomDir(oldPath) == success) {
	   privateRenomear(oldPath, oldName, newName);
	} else if (isValidCustomFile(oldPath) == success) {
	    privateRenomear(oldPath, oldName, newName);
	} else {
		printf("O arquivo/pasta '%s' nao foi encontrado!\n\n", oldName);
	}
	
	free(fullCommand);
	return 0;
}

void privateRenomear(char* oldPath, char* oldName, char* newName){
	char* fullCommand = (char*)calloc(sizeof(char), 650);

    strcpy(fullCommand, "ren ");
    strcat(fullCommand, oldPath);
    strcat(fullCommand, " ");
    strcat(fullCommand, newName);

    system(fullCommand);

    free(fullCommand);
    printf("'%s' -> '%s'\n\n", oldName, newName);
}

int mover(char *arq, char *dir){
	
	char* firstPath = (char*)calloc(sizeof(char), 300);
  	strcat(strcpy(firstPath, getAllPath()), arq);
	
	char* secondPath = (char*)calloc(sizeof(char), 300);
  	strcat(strcpy(secondPath, getPath()), dir);
	
  	if ((isValidCustomDir(firstPath) || isValidCustomFile(firstPath)) &&
  	    (isValidCustomDir(secondPath))
  	) {
    	char* fullCommand = (char*)calloc(sizeof(char), 400);

   		strcpy(fullCommand, "move ");
   		strcat(fullCommand, firstPath);
   		strcat(fullCommand, " ");
   	 	strcat(fullCommand, secondPath);

  	  	system(fullCommand);

  	  	free(fullCommand);
   	 	printf("'%s' foi movido para dentro da pasta '%s'\n\n", arq, dir);
  	} else {
    	printf("O arquivo/pasta '%s' nao existe ou '%s' nao eh uma pasta!\n\n", arq, dir);
  	}

  free(firstPath);
  free(secondPath);
	
	return 0;
}

int deletar(char *name){
	char* allPath = (char*)calloc(sizeof(char), 300);
  	strcat(strcpy(allPath, getAllPath()), name);
	char* fullCommand = (char*)calloc(sizeof(char), 400);
	
	if (isValidCustomDir(allPath) == success) {
	    strcpy(fullCommand, "rmdir /Q /S ");
	    strcat(fullCommand, allPath);
	
	    system(fullCommand);
	    printf("A pasta '%s' foi deletada com sucesso!\n\n", name);
	} else if (isValidCustomFile(allPath) == success) {
	    strcpy(fullCommand, "del ");
	    strcat(fullCommand, allPath);
	
	    system(fullCommand);
	    printf("O arquivo '%s' foi deletado com sucesso!\n\n", name);
	} else {
		printf("O arquivo/pasta '%s' nao foi encontrado!\n\n", name);
	}
	
	free(fullCommand);
	return 0;
}

int ajuda(char** arqs, int words){
	int i = 1;
	printf("%s\n", ajudaTitulo);
	char *command = upperString(arqs[1]);
	if(words == 1 || strcmp(command, "CRIAR") == 0){
		printf("%d) %s\n", i, ajudaCriar);
		i++;
	}
	if(words == 1 || strcmp(command, "INSERIR") == 0){
		printf("%d) %s\n", i, ajudaInserir);
		i++;
	}
	if(words == 1 || strcmp(command, "LER") == 0){
		printf("%d) %s\n", i, ajudaLer);
		i++;
	}
	if(words == 1 || strcmp(command, "LISTAR") == 0){
		printf("%d) %s\n", i, ajudaListar);
		i++;
	}
	if(words == 1 || strcmp(command, "APAGAR") == 0){
		printf("%d) %s\n", i, ajudaApagar);
		i++;
	}
	if(words == 1 || strcmp(command, "RENOMEAR") == 0){
		printf("%d) %s\n", i, ajudaRenomear);
		i++;
	}
	if(words == 1 || strcmp(command, "MOVER") == 0){
		printf("%d) %s\n", i, ajudaMover);
		i++;
	}
	if(words == 1 || strcmp(command, "DELETAR") == 0){
		printf("%d) %s\n", i, ajudaDeletar);
		i++;
	}
	if(words == 1 || strcmp(command, "AJUDA") == 0){
		printf("%d) %s\n", i, ajudaAjuda);
		i++;
	}
	if(words == 1 || strcmp(arqs[1], "VER") == 0){
		printf("%d) %s\n", i, ajudaVer);
		i++;
	}
	if(words == 1 || strcmp(command, "VER_M") == 0){
		printf("%d) %s\n", i, ajudaVerM1000);
		i++;
	}
	if(words == 1 || strcmp(command, "DATA") == 0){
		printf("%d) %s\n", i, ajudaData);
		i++;
	}
	if(words == 1 || strcmp(command, "HORA") == 0){
		printf("%d) %s\n", i, ajudaHora);
		i++;
	}
	if(words == 1 || strcmp(command, "LIMPAR") == 0){
		printf("%d) %s\n", i, ajudaLimpar);
		i++;
	}
	if(words == 1 || strcmp(command, "SAIR") == 0){
		printf("%d) %s\n", i, ajudaSair);
		i++;
	}
	if(words == 1 || strcmp(command, "TD") == 0){
		printf("%d) %s\n", i, ajudaTd);
		i++;
	}
	if(i == 1){
		printf(ajuda404);
	}
	
	printf("===================================\n\n");
	return 0;
}

int ver(){
	system("ver");
	return 0;
}

int verM1000(){
	printf("M1000.O.S [versao 0.0.0.1 beta]\n");
	return 0;
}

int data(){
	printf("Data de hoje: ");
	system("powershell get-date -format 'dd/MM/yyyy'");
	return 0;
}

int hora(){
	printf("Horario: ");
	system("powershell get-date -format 'HH:mm:ss'");
	return 0;
}

int limpar(){
	system("cls");
	return 0;
}

void sair(){
	printf("\nObrigado por usar o M1000.O.S\n");
	exit(0);
}

void abrirDir(char* dir){
	setMaskPath("-a", dir);
	if(isValidDir() == error){
		sairDir();
		printf(erroDir);
	}
}

void sairDir(){
 	setMaskPath("-s", "");
}

void voltarRaiz(){
	resetMaskPath();
}

void erroDeComando(){
	printf(ajuda404);
}
