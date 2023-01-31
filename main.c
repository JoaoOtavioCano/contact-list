#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "lista.h"

int main(){

  tipoContato contato;
  char operacao;
  int rodando = 1;

  FILE *contatos;
  contatos = fopen("contatos.csv", "a+");

  while (rodando > 0){
    printf("oi\n");
    scanf("%c", &operacao);

    switch (operacao) {

      case 'I':
        printf("Nome: ");
        scanf("%s", contato.nome);
        printf("Celular: ");
        scanf("%s", contato.celular);
        inserirContato(contatos, contato);
        break;
      
      case 'R':
        break;
      
      case 'A':
        break;
      
      case 'B':
        scanf("%s", contato.nome);
        buscarContato(contatos, "joao");
        break;

      case '0':
        rodando = 0;
        break;
    }
  }

  fclose(contatos); 
  
  return 0;

}