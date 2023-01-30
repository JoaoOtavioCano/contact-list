#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "lista.h"

int main(){
  t_lista l;
  t_elemento contato;
  char operacao;
  int i = 0;
  t_chave nome[10], numero[9];
  

  criar(&l);

  contato.chave = (t_chave)malloc(10*sizeof(t_chave));
  contato.numero = (t_chave)malloc(9*sizeof(t_chave));

  
  while(i < 1000000000 ){
  scanf("%c", &operacao);


    switch (operacao) {
      case 'I':
      
        scanf("%s", &nome);
        scanf("%s", &numero);
        strcpy(contato.chave, nome);
        strcpy(contato.numero, numero);
        inserir(&l, contato);
        i++;
        break;
      
      case 'R':
        scanf("%s", &nome);
        strcpy(contato.chave, nome);
        scanf("%s", contato.chave);
        remover(&l, contato.chave);
        i++;
        break;
      
      case 'A':
        scanf("%s", &nome);
        scanf("%s", &numero);
        strcpy(contato.chave, nome);
        strcpy(contato.numero, numero);
        alterar(&l, contato);
        i++;
        break;
      
      case 'P':
        scanf("%s", &nome);
        strcpy(contato.chave, nome);
        pesquisar(&l, contato.chave);
        i++;
        break;

      case '0':
        exit(1);
        break;
    }
  }
    return 0;
}