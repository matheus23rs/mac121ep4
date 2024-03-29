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

  posfixa.c
  Pitao II

  Referências: Com exceção das rotinas fornecidas no esqueleto e em sala
  de aula, caso você tenha utilizado alguma refência, liste-as abaixo
  para que o seu programa não seja considerada plágio.
  Exemplo:

  - função mallocc retirada de:

  http://www.ime.usp.br/~pf/algoritmos/aulas/aloca.html

  \__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__
*/

/*
  NAO EDITE OU MODIFIQUE NADA QUE ESTA ESCRITO NESTE ESQUELETO
*/

/*------------------------------------------------------------*/
/* iterface para o uso da funcao deste módulo */
#include "posfixa.h"

/*------------------------------------------------------------*/
#include "categorias.h" /* Categoria, MAX_OPERADORES, INDEFINIDA,
                          ABRE_PARENTESES, ... */
#include "objetos.h" /* tipo CelObjeto, freeObjeto(), freeListaObjetos() */
#include "stack.h"   /* stackInit(), stackFree(), stackPop()
                        stackPush(), stackTop() */
#include <string.h>
#include <stdlib.h>

/* Funcao Auxiliar para a fila */

static CelObjeto *fimPos;

void queuePut(Item *x){
  CelObjeto *auxCel;
  auxCel = mallocSafe(sizeof(*auxCel));
  auxCel->valor.vFloat = x->valor.vFloat;
  auxCel->valor.vInt   = x->valor.vInt;
  auxCel->categoria    = x->categoria;
  if(x->categoria == 30){
    strcpy(auxCel->valor.pStr, x->valor.pStr);
  }
  fimPos->prox = auxCel;
  fimPos = auxCel;
  auxCel->prox = NULL;
}

/*-------------------------------------------------------------
 *  infixaParaPosfixa
 *
 *  Recebe uma lista ligada com cabeca INIINFIXA representando uma
 *  fila de itens de uma expressao infixa e RETORNA uma lista ligada
 *  com cabeca contendo a fila com a representacao da correspondente
 *  expressao em notacao posfixa.
 */
 /*  As celulas da notacao infixa que nao forem utilizadas na notacao
  *  posfixa (abre e fecha parenteses) devem ser liberadas
  *  (freeObjeto()).
  */
CelObjeto *
infixaParaPosfixa(CelObjeto *iniInfixa)
{
    /* O objetivo do return a seguir e evitar que
       ocorra erro de sintaxe durante a fase de desenvolvimento
       do EP. Esse return devera ser removido depois que
       a funcao estiver pronta.
    */
    CelObjeto *iniPos, *aux_cel;
    Item *aux;                           /* iniPos  = inicio da fila posfixa      */
    int categoria;
    stackInit();
    iniPos  = mallocSafe(sizeof(*iniPos));
    iniPos->prox = NULL;
    fimPos = iniPos;
    iniInfixa = iniInfixa->prox;
    while(iniInfixa != NULL){
      categoria = iniInfixa->categoria;
      aux = stackTop();
      switch(categoria){
        case OPER_IGUAL:
        case OPER_DIFERENTE:
          while(!stackEmpty() && aux->valor.vInt >= 4 && aux->categoria != ABRE_PARENTESES){
            aux = stackpop();
            queuePut(aux);
            aux = stackTop();
          }
          aux = mallocSafe(sizeof(*aux));
          aux->valor.vFloat = iniInfixa->valor.vFloat;
          aux->valor.vInt   = iniInfixa->valor.vInt;
          aux->categoria = iniInfixa->categoria;
          stackPush(*aux);
          free(aux);
        break;

        case OPER_MAIOR_IGUAL:
        case OPER_MENOR_IGUAL:
        case OPER_MAIOR:
        case OPER_MENOR:
          while(!stackEmpty() && aux->valor.vInt >= 5 && aux->categoria != ABRE_PARENTESES){
            aux = stackpop();
            queuePut(aux);
            aux = stackTop();
          }
          aux = mallocSafe(sizeof(*aux));
          aux->valor.vFloat = iniInfixa->valor.vFloat;
          aux->valor.vInt   = iniInfixa->valor.vInt;
          aux->categoria = iniInfixa->categoria;
          stackPush(*aux);
          free(aux);
        break;

        case OPER_EXPONENCIACAO:
        case OPER_LOGICO_NOT:
        case OPER_MENOS_UNARIO:
          while(!stackEmpty() && aux->valor.vInt > 8 && aux->categoria != ABRE_PARENTESES){
            aux = stackpop();
            queuePut(aux);
            aux = stackTop();
          }
          aux = mallocSafe(sizeof(*aux));
          aux->valor.vFloat = iniInfixa->valor.vFloat;
          aux->valor.vInt   = iniInfixa->valor.vInt;
          aux->categoria = iniInfixa->categoria;
          stackPush(*aux);
          free(aux);
        break;

        case OPER_RESTO_DIVISAO:
        case OPER_MULTIPLICACAO:
        case OPER_DIVISAO:
        case OPER_DIVISAO_INT:
          while(!stackEmpty() && aux->valor.vInt >= 7 && aux->categoria != ABRE_PARENTESES){
            aux = stackpop();
            queuePut(aux);
            aux = stackTop();
          }
          aux = mallocSafe(sizeof(*aux));
          aux->valor.vFloat = iniInfixa->valor.vFloat;
          aux->valor.vInt   = iniInfixa->valor.vInt;
          aux->categoria = iniInfixa->categoria;
          stackPush(*aux);
          free(aux);
        break;

        case OPER_ADICAO:
        case OPER_SUBTRACAO:
          while(!stackEmpty() && aux->valor.vInt >= 6 && aux->categoria != ABRE_PARENTESES){
            aux = stackpop();
            queuePut(aux);
            aux = stackTop();
          }
          aux = mallocSafe(sizeof(*aux));
          aux->valor.vFloat = iniInfixa->valor.vFloat;
          aux->valor.vInt   = iniInfixa->valor.vInt;
          aux->categoria = iniInfixa->categoria;
          stackPush(*aux);
          free(aux);
        break;

        case OPER_LOGICO_AND:
          while(!stackEmpty() && aux->valor.vInt >= 3 && aux->categoria != ABRE_PARENTESES){
            aux = stackpop();
            queuePut(aux);
            aux = stackTop();
          }
          aux = mallocSafe(sizeof(*aux));
          aux->valor.vFloat = iniInfixa->valor.vFloat;
          aux->valor.vInt   = iniInfixa->valor.vInt;
          aux->categoria = iniInfixa->categoria;
          stackPush(*aux);
          free(aux);
        break;

        case OPER_LOGICO_OR:
          while(!stackEmpty() && aux->valor.vInt >= 2 && aux->categoria != ABRE_PARENTESES){
            aux = stackpop();
            queuePut(aux);
            aux = stackTop();
          }
          aux = mallocSafe(sizeof(*aux));
          aux->valor.vFloat = iniInfixa->valor.vFloat;
          aux->valor.vInt   = iniInfixa->valor.vInt;
          aux->categoria = iniInfixa->categoria;
          stackPush(*aux);
          free(aux);
        break;

        case OPER_ATRIBUICAO:
          while(!stackEmpty() && aux->valor.vInt > 8 && aux->categoria != ABRE_PARENTESES){
            aux = stackpop();
            queuePut(aux);
            aux = stackTop();
          }
          aux = mallocSafe(sizeof(*aux));
          aux->valor.vFloat = iniInfixa->valor.vFloat;
          aux->valor.vInt   = iniInfixa->valor.vInt;
          aux->categoria = iniInfixa->categoria;
          stackPush(*aux);
          free(aux);
        break;

        case ABRE_PARENTESES:
          aux = mallocSafe(sizeof(*aux));
          aux->valor.vFloat = iniInfixa->valor.vFloat;
          aux->valor.vInt   = iniInfixa->valor.vInt;
          aux->categoria = iniInfixa->categoria;
          stackPush(*aux);
          free(aux);
        break;

        case FECHA_PARENTESES:
          while(aux->categoria != ABRE_PARENTESES){
            aux = stackpop();
            queuePut(aux);
            aux = stackTop();
          }
        break;

        default:
          aux = mallocSafe(sizeof(*aux));
          aux->valor.vFloat = iniInfixa->valor.vFloat;
          aux->valor.vInt   = iniInfixa->valor.vInt;
          aux->categoria = iniInfixa->categoria;
          if(categoria == 30){
              strcpy(aux->valor.pStr, iniInfixa->valor.pStr);
          }
          queuePut(aux);
          free(aux);
      }
      aux_cel = iniInfixa;
      iniInfixa = iniInfixa->prox;
      free(aux_cel);
    }
    while(!stackEmpty()){
      aux = stackTop();
      aux = stackpop();
      if(aux->categoria != ABRE_PARENTESES)
        queuePut(aux);
    }
    stackFree();
    return(iniPos);
}
