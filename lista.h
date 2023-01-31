#include <stdio.h>

#ifndef LISTA_H
#define LISTA_H

#define JA_EXISTE -2
#define NAO_ENCONTROU -1
#define SUCESSO 1

typedef struct tipoContato{
  char nome[40];
  char celular[11];
  //char email[40];
} tipoContato;

int inserirContato(FILE *lista, tipoContato contato);
int buscarContato(FILE *lista, char *nome);
//int removerContato(FILE *lista, char *nome);
//int alterarContato(FILE *lista, char *nome);

#endif