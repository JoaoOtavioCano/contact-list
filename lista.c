#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int criar(t_lista *lista) {
  lista->primeiro = NULL;
  return SUCESSO;
}//cria a lista

int inserir(t_lista *lista, t_elemento elemento){

  t_apontador novo = (t_apontador)malloc(sizeof(t_no));
  novo->elemento.chave = (t_chave)malloc(10*sizeof(t_chave));
  novo->elemento.numero = (t_chave)malloc(9*sizeof(t_chave));
  
  if (novo == NULL) //caso de lista cheia 
    return ERRO_CHEIA;


  if (pesquisa_pos(lista, elemento.chave) != NULL) { //teste se o contato já foi inserido
    printf("Contatinho ja inserido\n");
    return JA_EXISTE;
  }

  //inserção no começo da lista
  strcpy(novo->elemento.chave, elemento.chave);
  strcpy(novo->elemento.numero, elemento.numero);
  novo->proximo = lista->primeiro;
  lista->primeiro = novo;
  return SUCESSO;
}

int pesquisar(t_lista *lista, t_chave chave) {
  t_apontador P = pesquisa_pos(lista, chave);

  if (P == NULL) { // caso contato pesquisado não exista
    printf("Contatinho nao encontrado\n");
    return NAO_ENCONTROU;
  }

  //caso o contato seja encontrado
  printf("Contatinho encontrado: telefone %s\n", P->elemento.numero);
  return SUCESSO;
}

 static t_apontador pesquisa_pos(t_lista *lista, t_chave chave) {

  t_apontador P = lista->primeiro;
   
  if (P == NULL)
    return NULL;

  while (P != NULL) {
    if (strcmp(P->elemento.chave, chave) == 0)
      return P;
    P = P->proximo;
  }

  return NULL;
}

int remover(t_lista *lista, t_chave chave) {
  t_apontador P = pesquisa_pos(lista, chave);

  if (P == NULL) { // contato que tentou remover não existe
    printf("Operacao invalida: contatinho nao encontrado\n");
    return NAO_ENCONTROU;
  }

  if (strcmp(lista->primeiro->elemento.chave, chave) == 0) { //caso o nó a ser removido seja o primeiro da lista
    lista->primeiro = lista->primeiro->proximo;
    free(P);
  } else if (P->proximo == NULL) { // caso o nó a ser removido seja o último nó da lista
    t_apontador aux = lista->primeiro;
    while (aux->proximo->proximo != NULL) {
      aux = aux->proximo;
    }
    aux->proximo = NULL;
    free(P);
  } else { // caso o nó esteja no meio da lista
    t_apontador aux = lista->primeiro;
    while (aux->proximo != P) {
      aux = aux->proximo;
    }
    aux->proximo = P->proximo;
    free(P);
  }
}

int alterar(t_lista *lista, t_elemento novo_elemento) {
  t_apontador P = pesquisa_pos(lista, novo_elemento.chave);

  if (P == NULL) {
    printf("Operacao invalida: contatinho nao encontrado\n");
    return NAO_ENCONTROU;
    }
  
  remover(lista, novo_elemento.chave);
  inserir(lista, novo_elemento);

  return SUCESSO;
}