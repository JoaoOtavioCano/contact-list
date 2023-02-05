#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char escolha_de_operacao(void){
  char c;
  printf("Digite: ");
  c = getchar();
  return c;
}


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
          return SUCESSO;
      }
      else if (feof(lista)){
          break;
      }
  }
  return NAO_ENCONTROU;
}

int removerContato(FILE *lista, char *nome){
  char linha[55];
  char *token;
  FILE *oldfile;
  
  if( buscarContato(lista, nome) == NAO_ENCONTROU)
  {
    printf("Esse contato não existe!\n");
    return NAO_ENCONTROU;
  }

  rename("contatos.csv", "oldfile.csv");
  oldfile = lista;
  lista = fopen("contatos.csv", "a");
  fprintf(lista, "nome,celular,\n");
  rewind(oldfile);

  while(1 > 0)
  {
    fscanf(oldfile, "%s", linha);
    if(feof(oldfile))
      break;
    token = strtok(linha, ",");
    if (strcmp(token,nome) != 0 && strcmp(token, "nome") != 0)
    {
      fprintf(lista, "%s,", token);
      token = strtok(NULL, ",");
      fprintf(lista, "%s,\n", token);
    }
  }

  remove("oldfile.csv");
  fclose(oldfile);
  fclose(lista);
  return SUCESSO;
}

int alterarContato(FILE *lista, char *nome){

  if( buscarContato(lista, nome) == NAO_ENCONTROU)
  {
    printf("Esse contato não existe!\n");
    return NAO_ENCONTROU;
  }

  removerContato(lista, nome);

  fclose(lista);

  lista = fopen("contatos.csv", "a+");

  tipoContato alteracao;
  strcpy(alteracao.nome, nome);
  printf("Novo celular: ");
  scanf("%s", alteracao.celular);

  inserirContato(lista, alteracao);

  return SUCESSO;
}