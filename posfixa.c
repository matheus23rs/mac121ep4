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

/* Funcao Auxiliar para a fila */

void queuePut(CelObjeto *fim, Item *x){
  CelObjeto *aux;
  aux = mallocSafe(sizeof(*aux));
  aux->valor.vInt = x->valor.vInt;
  aux->valor.vFloat = x->valor.vInt;
  if(x->categoria == 30){
    strcpy(aux->valor.pStr, x->valor.pStr);
  }
  aux->categoria = x->categoria;
  fim->prox = aux;
  fim = aux;
  fim->prox = NULL;
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
    CelObjeto *topoOpe, *iniPos, *fimPos, *auxOpe;  /* topoOpe = topo da pilha de operadores */
    Item *aux;                             /* iniPos  = inicio da fila posfixa     */
    int categoria;
    topoOpe = stackInit();
    iniPos  = stackInit(); 
    fimPos = iniPos;
    iniInfixa = iniInfixa->prox;
    while(iniInfixa != NULL){
      categoria = iniInfixa->categoria;
      aux = stackTop(topoOpe);  
      switch(categoria){
        case OPER_IGUAL:
        case OPER_DIFERENTE:
          while(!stackEmpty(topoOpe) && aux->valor.vInt <= 4){
            aux = stackpop(topoOpe);

          }
      }
    }
    AVISO(posfixa.c: Vixe! Ainda nao fiz a funcao infixaParaPosfixa.);
    return (iniPos); 
}
