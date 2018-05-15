#include <stdio.h>
#include <stdlib.h>
#include "terra_incognita.h"

int mapa_pos(int x, int y)
{
    /* devolve tipo de terreno na posicao x,y */
    
    return TERRA_INCOGNITA;
}

int main(int argc, char *argv[])
{
    /* 1) iniciar comunicacao com exploradores
          NOTA: primeiros parametros deverao ser argc e argv */
      int nExplorator, id, type;
      int i;
      int position[10][2];

      intro(argc, argv, &nExplorator, position);
      
      printf("%d\n", nExplorator);

     
      for(i=0; i< nExplorator; i++) {
            printf("%d %d\n", position[i][0], position[i][1]);
      }
      
      printf("%c\n", explorator(&id, &type));
      printf("%d\n", type);
    /* 2) comunicar com os exploradores e receber informacoes, 
          enquanto existem movimentacoes a realizar */


    /* 3) imprime e verifica o mapa
          NOTA: funcao mapa_pos e' o primeiro das funcoes */


    /* 4) termina comunicacoes com os exploradores */


    return 0;
}