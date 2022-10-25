#ifndef COMMANDS_H
#define COMMANDS_H

int criar(char*, char*, char*);
int inserir(char*, char*, char*);
int ler(char*);
int listar();
int renomear(char*, char*);
void privateRenomear(char*, char*, char*);
int mover(char*, char*);
int deletar(char*);
int ajuda(char**, int);
int ver();
int verM1000();
int data();
int hora();
int limpar();
void sair();
void abrirDir(char*);
void sairDir();
void voltarRaiz();
void erroDeComando();


#endif
