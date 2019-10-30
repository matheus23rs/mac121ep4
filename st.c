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

  st.c
  Pitao II

  Referências: Com exceção das rotinas fornecidas no esqueleto e em sala
  de aula, caso você tenha utilizado alguma refência, liste-as abaixo
  para que o seu programa não seja considerada plágio.
  Exemplo:
  - função mallocc retirada de: http://www.ime.usp.br/~pf/algoritmos/aulas/aloca.html

  \__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__\__
*/

/*
  NAO EDITE OU MODIFIQUE NADA QUE ESTA ESCRITO NESTE ESQUELETO
*/

/* interface para o uso da funcao deste módulo */
#include "st.h"      /* CelST */

#include <stdlib.h>  /* free(), NULL */
#include <string.h>  /* strcmp(), strlen(), strncpy() */
#include "util.h"    /* String, mallocSafe() */
#include "objetos.h" /* Valor, CelObjeto */

/*-----------------------------------------------------------
 * A tabela de simbolos dever ser implementada atraves de uma 
 * __lista ligada com cabeca__. 
 *
 * Todas as listas, filas e pilhas neste EP sao implementadas
 * atraves de listas ligadas com cabeca.
 */

/* ponteiro para a celula cabeca da lista que representa a tabela
   de simbolos */
static CelST *ini; 

/* funcao auxiliar */
static CelST *
endVarST(char *nomeVar);

/*-------------------------------------------------------------
 * initST()
 *
 * CRIA uma tabela de simbolos vazia.
 *  
 * Em outras palavras, cria uma lista ligada vazia.
 * A lista ligada e' com cabeca
 * Cada celula da lista e' do tipo CelST.
 */
void 
initST()
{
    ini = mallocSafe(sizeof(*ini));
    ini->proxVar = NULL;
    AVISO(st.c: Vixe! Ainda nao fiz a funcao iniST.);
}

/*-------------------------------------------------------------
 *  getValorST
 *
 *  RECEBE um string NOMEVAR que e' o nome de uma variavel.
 *  Procura essa variavel na tabela de simbolos.
 *  Se NOMEVAR esta na tabela de simbolos, entao a funcao CRIA uma
 *  celula do tipo CelObjeto que no campo:
 *
 *      - categoria contem  FLOAT;
 *      - valor.vFloat contem o valor atual da variavel; e
 *      - prox contem NULL.
 *   
 *  A funcao RETORNA o endereco dessa celula.  Se NOMEVAR nao
 *  estiver na tabela de simbolos a funcao RETORNA NULL.
 *
 *  Esta funcao deve utilizar a funcao endVarST().
 */
CelObjeto *
getValorST(char *nomeVar)
{
    /* O objetivo do return a seguir e evitar que 
       ocorra erro de sintaxe durante a fase de desenvolvimento 
       do EP. Esse return devera ser removido depois que
       a funcao estiver pronta.
    */
    CelObjeto *valor = NULL;
    CelST *aux = NULL;
    aux = endVarST(nomeVar);
    if(aux != NULL){
        valor = mallocSafe(sizeof(*valor));
        valor->categoria = 28;
        valor->val = aux->valorVar.vFloat;
        valor->prox = NULL;
    }
    return (valor);
}

/*-------------------------------------------------------------
 *  setValorST
 *
 * RECEBE um string NOMEVAR que e' o nome de uma variavel, e
 * um ponteiro PVALOR para uma CelObjeto que representa  um 
 * float, ou seja, na celula o campo 
 * 
 *     - categoria    contem FLOAT;  
 *     - valor.Vfloat contem um double, e
 *     - prox         contem um endereco irrelevante. 
 *
 * Se NOMEVAR nao faz parte da tabela de simbolos a funcao cria
 * uma nova celula do tipo CelST que deve ser inserida na tabela de 
 * simbolos. O campo 
 *
 *     - nomeVar dessa nova celula deve conter uma copia do 
 *       string NOMEVAR.
 * 
 * A funcao ATRIBUI os campos 
 * 
 *    categoria e vFloat 
 * 
 * de pVALOR aos campos 
 * 
 *    tipoVar e valorVar 
 *
 * da celula na tabela de simbolo responsavel por conter o valor
 * da variavel NOMEVAR.
 * 
 * Esta funcao deve utilizar a funcao endVarST().
 *
 * Esta funcao utiliza a funcao mallocSafe().
 *
 * Para copia de strings podem ser utilizadas quaisquer funcoes da 
 * biblioteca string.h: strcpy(), strncpy()...
 * 
 * A funcao _nao_ deve alterar a celula PVALOR.
 */
void
setValorST(char *nomeVar, CelObjeto *pValor)
{
    CelST *found = NULL, *aux;
    found = endVarST(nomeVar);
    if(found != NULL){
        found->tipoVar = pValor->categoria;
        found->valorVar.vFloat = pValor->val;
        strcpy(found->nomeVar, nomeVar);
    }
    aux = ini;
    while(aux->proxVar != NULL) aux = aux->proxVar;
    aux->proxVar = found;
    found->proxVar = NULL;
}

/*-------------------------------------------------------------
 * freeST()
 *
 * Funcao que libera toda a memoria alocada para a tabela
 * de simbolos.
 *
 * Funcao utiliza a funcao free().
 */
void 
freeST()
{
    CelST *aux;
    aux = ini;
    ini = ini->proxVar;
    free(aux);
    while(ini != NULL){
        aux = ini;
        ini = ini->proxVar;
        free(aux->nomeVar);
        free(aux);
    }
}

/*-------------------------------------------------------------
 * showST()
 *
 * Funcao que para cada variavel na tabela de simbolos exibe:
 *
 *      - seu nome; e
 *     - seu valor atual.
 *
 * Exemplo de saida que pode ser produzida por esta funcao.
 * 
 *     ==========================
 *     Tabela de simbolos
 *     'nome': valor
 *     . . . . . . . . . . . . . .
 *     'prova3': 4.5
 *     'prova2': 6.5
 *     'prova1': 7
 *     'soma': 18
 */
void
showST()
{
    CelST *aux;
    aux = ini->proxVar;
    printf("========================");
    printf("Tabela de simbolos\n");
    printf("'nome': valor\n");
    printf(". . . . . . . . . . . . .\n");
    while(aux != NULL){
        printf("'%s': %f\n", aux->nomeVar, aux->valorVar.vFloat);
        aux = aux->proxVar;
    }
}

/*-------------------------------------------------------------
 * endVarST
 *
 * RECEBE um string NOMEVAR com o nome de uma variavel e RETORNA
 * o endereco da celula na tabela de simbolos que representa a 
 * variavel. Se NOMEVAR nao esta na tabela de simbolos a funcao
 * RETORNA NULL.
 *
 * Considere a utilizacao de funcoes da biblioteca string.h, tais
 * como strcpy, strncpy, strcmp,....
 */
static CelST *
endVarST(char *nomeVar)
{
    /* O objetivo do return a seguir e evitar que 
       ocorra erro de sintaxe durante a fase de desenvolvimento 
       do EP. Esse return devera ser removido depois que
       a funcao estiver pronta.
    */
    CelST *celVar = ini->proxVar;
    int found = 0;
    while(celVar != NULL &&  found == 0){
        if(strcmp(nomeVar, celVar->valorVar.pStr) == 0) found = 1;
        celVar = celVar->proxVar;
    }
    return (celVar); 
}
