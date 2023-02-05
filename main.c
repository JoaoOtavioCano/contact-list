#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "lista.h"


int main(){

  tipoContato contato;
  int operacao = 0;
  int contador = 0;

  FILE *contatos;

  while (1 > 0)
  {
    contatos = fopen("contatos.csv", "a+");

    rewind(contatos);

    if(contador == 0)
    {
      fprintf(contatos, "nome,celular,\n");
      fclose(contatos);
      contatos = fopen("contatos.csv", "a+");
      contador++;
    }


    printf("\nFuncionalidades:\n\n(0) para Inserir novo contato\n(1) para Remover um contato\n(2) para Editar um contato\n(3) para Buscar um contato\n(4) para Fechar o programa\n\nEscolha: ");
    scanf("%i", &operacao);

    if(operacao == 0)
    {
      printf("Nome: ");
      scanf("%s", contato.nome);
      printf("Celular: ");
      scanf("%s", contato.celular);
      inserirContato(contatos, contato);
    }else if(operacao == 1)
    {
      printf("Contato:");
      scanf("%s", contato.nome);
      removerContato(contatos, contato.nome);
    }else if(operacao == 4)
    {
      break;
    }else if(operacao == 2)
    {
      printf("Contato:");
      scanf("%s", contato.nome);
      alterarContato(contatos, contato.nome);
    }else if(operacao == 3)
    {
      printf("Contato:");
      scanf("%s", contato.nome);
      retornarInfo(contatos, contato.nome);
    }else
    {
      printf("Type a vaid operation!\n");
    }

    fclose(contatos); 

  }

  fclose(contatos); 

  return 0;

}



 