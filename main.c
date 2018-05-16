#include <stdio.h>
#include <stdlib.h>
#include "terra_incognita.h"
#include "vetor.h"

int mapa_pos(int x, int y)
{
    /* devolve tipo de terreno na posicao x,y */

    return TERRA_INCOGNITA;
}

int main(int argc, char *argv[])
{
    int nExplorator, position[MAX_EXPLORADORES][2], typus, id, x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    char move;
    int i;
    vetor *terrain;

    terrain = vetor_novo();
    
    intro(argc, argv, &nExplorator, position);

    move = explorator(&id, &typus);
    while(move != 'X'){
      if(move == 'N'){
         position[id][1]--;
         vetor_insere(terrain, position[id][0], position[id][1], typus, -1);

          if(position[id][1] < y1){
            y1 = position[id][1];
          }
          if(position[id][1] > y2){
            y2 = position[id][1]; 
          }
        }
      if(move == 'S'){
         position[id][1]++;
         vetor_insere(terrain, position[id][0], position[id][1], typus, -1);

         if(position[id][1] < y1){
           y1 = position[id][1];
         }
         if(position[id][1] > y2){
           y2 = position[id][1];
         }
       }
      if(move == 'E'){
         position[id][0]--;
         vetor_insere(terrain, position[id][0], position[id][1], typus, -1);

         if(position[id][0] < x1){
           x1 = position[id][0];
         }
         if(position[id][0] > x2){
           x2 = position[id][0];
         }
       }
      if(move == 'O'){
         position[id][0]++;
         vetor_insere(terrain, position[id][0], position[id][1], typus, -1);

         if(position[id][0] < x1){
           x1 = position[id][0];
         }
         if(position[id][0] > x2){
           x2 = position[id][0];
         }
       }
      move = explorator(&id, &typus);
    }
    printf("%d %d\n %d %d\n", x1, y1, x2, y2);

    x2 = abs(x1)+abs(x2) + 1;
    y2 = abs(y1)+abs(y2) + 1;

    printf("%d %d\n", x2, y2);

    
    for(i= 0; i< terrain->tamanho; i++)
    {
      terrain->elementos[i].x = terrain->elementos[i].x - x1;
      terrain->elementos[i].y = terrain->elementos[i].y - y1;
    }
    

    for(i= 0; i< terrain->tamanho; i++)
    {
        printf("type-> %d\n", terrain->elementos[i].type);
        printf("(x, y)--> (%d, %d) \n", terrain->elementos[i].x, terrain->elementos[i].y);
        printf("\n");
    }
    /* 2) comunicar com os exploradores e receber informacoes,
          enquanto existem movimentacoes a realizar */


    /* 3) imprime e verifica o mapa
          NOTA: funcao mapa_pos e' o primeiro das funcoes */


    /* 4) termina comunicacoes com os exploradores */


    return 0;
}
