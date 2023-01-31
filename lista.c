#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int inserirContato(FILE *lista, tipoContato contato){

  if( buscarContato(lista, contato.nome) == SUCESSO){
    printf("Esse contato já existe!\n");
    return JA_EXISTE;
  }
  fprintf(lista, "%s,%s,\n", contato.nome, contato.celular);
  return SUCESSO;
}

int buscarContato(FILE *lista, char *nome){
  char linha[55];
  char *token;

  rewind(lista);
  
  while(1 > 0){
      fscanf(lista, "%s", linha);
      token = strtok(linha, ",");
      if (strcmp(token,nome) == 0){
          printf("Sucesso\n");
          return SUCESSO;
      }
      else if (feof(lista)){
          break;
      }
  }
  printf("Não encontrou\n");
  return NAO_ENCONTROU;
}
//int removerContato(FILE *lista, char *nome){}
//int alterarContato(FILE *lista, char *nome){}