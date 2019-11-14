/*
  \__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__

  AO PREENCHER ESSE CABEÇALHO COM O MEU NOME E O MEU NÚMERO USP,
  DECLARO QUE SOU O ÚNICO AUTOR E RESPONSÁVEL POR ESSE PROGRAMA.
  TODAS AS PARTES ORIGINAIS DESSE EXERCÍCIO PROGRAMA (EP) FORAM
  DESENVOLVIDAS E IMPLEMENTADAS POR MIM SEGUINDO AS INSTRUÇÕES DESSE EP
  E QUE PORTANTO NÃO CONSTITUEM PLÁGIO. DECLARO TAMBÉM QUE SOU RESPONSÁVEL
  POR TODAS AS CÓPIAS DESSE PROGRAMA E QUE EU NÃO DISTRIBUI OU FACILITEI A
  SUA DISTRIBUIÇÃO. ESTOU CIENTE QUE OS CASOS DE PLÁGIO SÃO PUNIDOS COM
  REPROVAÇÃO DIRETA NA DISCIPLINA.

  Nome:Matheus Ribeiro Silva

  stack.c
  Pitao II

  Referências: Com exceção das rotinas fornecidas no esqueleto e em sala
  de aula, caso você tenha utilizado alguma refência, liste-as abaixo
  para que o seu programa não seja considerada plágio.

  Exemplo:
  - função mallocc retirada de:

  http://www.ime.usp.br/~pf/algoritmos/aulas/aloca.html

  \__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__
*/

/* interface para o uso de uma pilha */
#include "stack.h"
#include <stdlib.h>
#include <string.h>

/*
 *
 * STACK.c: IMPLEMENTACAO DE UMA PILHA
 *
 * TAREFA EP3
 *
 * Faca aqui a implementacao de uma pilha atraves de uma
 * __lista encadeada com cabeca__.
 *
 * A implementacao deve respeitar a interface que voce declarar em
 * stack.h.
 *
 * TAREFA EP4: copiar a implementacao feira para o EP3.
 *     E possivel que sua implementacao para o EP3 deve ser
 *     adaptada, ja que agora a pilha de execucao pode conter
 *     nomes de variaveis e nao apenas valores double.
 *
 */
static CelObjeto *topo;

CelObjeto *stackInit(void){
   topo = mallocSafe(sizeof(*topo));
   topo->prox = NULL;
   return(topo);
}

int stackEmpty(void){
   return(topo->prox == NULL);
}

void stackPush(Item a){
  CelObjeto *nova = mallocSafe(sizeof(*nova));
  nova->valor.vFloat = a.valor.vFloat;
  nova->valor.vInt = a.valor.vInt;
  nova->categoria = a.categoria;
  if(a.categoria == 30)
    strcpy(nova->valor.pStr, a.valor.pStr);
  nova->prox = topo->prox;
  topo->prox = nova;
}

Item *stackpop(void){
   CelObjeto *p;
   Item *conteudo;
   p = topo->prox;
   conteudo = mallocSafe(sizeof(Item));
   if(!stackEmpty()){
     conteudo->valor.vFloat = p->valor.vFloat;
     conteudo->valor.vInt = p->valor.vInt;
     if(p->categoria == 30)
      strcpy(conteudo->valor.pStr, p->valor.pStr);
     conteudo->categoria = p->categoria;
     topo->prox = p->prox;
     free(p);
   }
   else{
     printf("AVISO: stackPop em stack.c: pilha vazia...\n");
     printf("ERRO: eval em eval.c: abortando o calculo da expressao\n");
     exit(1);
    }
   return(conteudo);
}

Item *stackTop(void){
  Item *conteudo = NULL;
  if(stackEmpty() == 1){
    return(conteudo);
  }
  conteudo = mallocSafe(sizeof(Item));
  conteudo->valor.vFloat = topo->prox->valor.vFloat;
  conteudo->valor.vInt = topo->prox->valor.vInt;
  conteudo->categoria = topo->prox->categoria;
  return(conteudo);
}

void stackFree(void){
  CelObjeto *p;
  p = topo;
  topo = topo->prox;
  free(p);
    while (topo != NULL){
      p = topo->prox;
      topo = topo->prox;
      freeObjeto(p);
    }
}

void stackPrint(void){
  CelObjeto *p;
  p = topo->prox;
  if(stackEmpty() == 1){
    printf("AVISO: stackPop em stack.c: pilha vazia...\n");
    printf("ERRO: eval em eval.c: abortando o calculo da expressao\n");
    exit(1);
  }
  printf("===================================\n");
  printf("Pilha de execucao\n");
  printf("Valor\n");
  printf(".....................\n");
  while(p != NULL){
      if(p->categoria == 30)
        printf("%s", p->valor.pStr);
      else
        printf("%f\n", p->valor.vFloat);
      p = p->prox;
  }
  printf("\n");
}
