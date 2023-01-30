#ifndef LISTA_H
#define LISTA_H

#define JA_EXISTE -2
#define NAO_ENCONTROU -1
#define ERRO_CHEIA 0
#define SUCESSO 1

typedef char *t_chave;

typedef struct t_elemento {
  t_chave chave;
  char *numero;
} t_elemento;

typedef struct t_no *t_apontador;

typedef struct t_no {
  t_elemento elemento;
  t_apontador proximo;
} t_no;

typedef struct t_list {
  t_apontador primeiro;
} t_lista;

int criar(t_lista *lista);
int inserir(t_lista *lista, t_elemento elemento);
int remover(t_lista *lista, t_chave chave);
int pesquisar(t_lista *lista, t_chave chave);
int alterar(t_lista *lista, t_elemento novo_elemento);
static t_apontador pesquisa_pos(t_lista *lista, t_chave chave);

#endif