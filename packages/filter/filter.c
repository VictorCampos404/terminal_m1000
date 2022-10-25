#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filter.h"
#include "../myTools/myTools.h"
#include "../commands/commands.h"
#include "../myConsts/myConsts.h"

void interpretador(char **comando, int words){
		
	if(strcmp(comando[0], "CRIAR") == 0){
		if(words == 3){
			criar(comando[1], comando[2], NULL);
		}else{
			printf(erroSintaxeCriar);
		}
	}else if(strcmp(comando[0], "INSERIR") == 0){
		if(words > 2){
			inserir(comando[1], getMessage(comando, words), "w");
		}else{
			printf(erroSintaxeInserir);
		}
	}else if(strcmp(comando[0], "LER") == 0){
		if(words == 2){
			ler(comando[1]);
		}else{
			printf(erroSintaxeLer);
		}
	}else if(strcmp(comando[0], "LISTAR") == 0){
		if(words == 1){
			listar();
		}else{
			printf(erroSintaxeListar);
		}
	}else if(strcmp(comando[0], "APAGAR") == 0){
		if(words == 2){
			deletar(comando[1]);
		}else{
			printf(erroSintaxeApagar);
		}
	}else if(strcmp(comando[0], "RENOMEAR") == 0){
		if(words == 3){
			renomear(comando[1], comando[2]);
		}else{
			printf(erroSintaxeRenomear);
		}
	}else if(strcmp(comando[0], "MOVER") == 0){
		if(words == 3){
			mover(comando[1], comando[2]);
		}else{
			printf(erroSintaxeMover);
		}
	}else if(strcmp(comando[0], "DELETAR") == 0){
		if(words == 2){
			deletar(comando[1]);
		}else{
			printf(erroSintaxeDeletar);
		}
	}else if(strcmp(comando[0], "AJUDA") == 0){
		if(words <= 2){
			ajuda(comando, words);
		}else{
			printf(erroSintaxeAjuda);
		}
	}else if(strcmp(comando[0], "VER") == 0){
		if(words == 1){
			ver();
		}else{
			printf(erroSintaxeVer);
		}
	}else if(strcmp(comando[0], "VER_M") == 0){
		if(words == 1){
			verM1000();
		}else{
			printf(erroSintaxeVerM1000);
		}
	}else if(strcmp(comando[0], "DATA") == 0){
		if(words == 1){
			data();
		}else{
			printf(erroSintaxeData);
		}	
	}else if(strcmp(comando[0], "HORA") == 0){
		if(words == 1){
			hora();
		}else{
			printf(erroSintaxeHora);
		}	
	}else if(strcmp(comando[0], "LIMPAR") == 0){
		if(words == 1){
			limpar();
		}else{
			printf(erroSintaxeLimpar);
		}
	}else if(strcmp(comando[0], "SAIR") == 0){
		if(words == 1){
			sair();
		}else{
			printf(erroSintaxeSair);
		}
	}else if(strcmp(comando[0], "TD") == 0){
		if(words == 2){
			if(strcmp(comando[1], "..") == 0){
				sairDir();
			}else if(strcmp(comando[1], "...") == 0){
				voltarRaiz();
			}else{
				abrirDir(comando[1]);	
			}
			
		}else{
			printf(erroSintaxeTd);
		}
	}else{
		erroDeComando();
	}
	
}
