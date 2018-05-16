#include <stdio.h>
#include <stdlib.h>
#include "terra_incognita.h"
#include "vetor.h"

vetor *terrain;

int mapa_pos(int x, int y)
{
    for(int i=0; i<terrain->tamanho; i++){
        if(terrain->elementos[i].x == x && terrain->elementos[i].y == y){
            return terrain->elementos[i].type;
        }

   }
    return TERRA_INCOGNITA;
}

int main(int argc, char *argv[])
{
    int nExplorator, position[MAX_EXPLORADORES][2], typus, id, xmin = 0, ymin = 0, xmax = 0, ymax = 0;
    char move;
    int i;

    terrain = vetor_novo();
    
    intro(argc, argv, &nExplorator, position);

    move = explorator(&id, &typus);
    while(move != 'X'){
      if(move == 'N'){
         position[id][1]--;
         vetor_insere(terrain, position[id][0], position[id][1], typus, -1);

          if(position[id][1] < ymin){
            ymin = position[id][1];
          }
          if(position[id][1] > ymax){
            ymax = position[id][1]; 
          }
        }
      if(move == 'S'){
         position[id][1]++;
         vetor_insere(terrain, position[id][0], position[id][1], typus, -1);

         if(position[id][1] < ymin){
           ymin = position[id][1];
         }
         if(position[id][1] > ymax){
           ymax = position[id][1];
         }
       }
      if(move == 'E'){
         position[id][0]++;
         vetor_insere(terrain, position[id][0], position[id][1], typus, -1);

         if(position[id][0] < xmin){
           xmin = position[id][0];
         }
         if(position[id][0] > xmax){
           xmax = position[id][0];
         }
       }
      if(move == 'O'){
         position[id][0]--;
         vetor_insere(terrain, position[id][0], position[id][1], typus, -1);

         if(position[id][0] < xmin){
           xmin = position[id][0];
         }
         if(position[id][0] > xmax){
           xmax = position[id][0];
         }
       }
      move = explorator(&id, &typus);
    }
    printf("%d %d\n %d %d\n", xmin, ymin, xmax, ymax);

    xmax = abs(xmin)+abs(xmax) + 1;
    ymax = abs(ymin)+abs(ymax) + 1;

    printf("%d %d\n", xmax, ymax);

    
    for(i= 0; i< terrain->tamanho; i++)
    {
      terrain->elementos[i].x = terrain->elementos[i].x - xmin;
      terrain->elementos[i].y = terrain->elementos[i].y - ymin;
    }

    // for(i= 0; i< terrain->tamanho; i++)
    // {
    //     printf("type-> %d\n", terrain->elementos[i].type);
    //     printf("(x, y)--> (%d, %d) \n", terrain->elementos[i].x, terrain->elementos[i].y);
    //     printf("\n");
    // }

    /* 3) imprime e verifica o mapa
          NOTA: funcao mapa_pos e' o primeiro das funcoes */
    tabula(mapa_pos, xmax, ymax);
    veritas(mapa_pos, xmax, ymax);
    relinquo();


    /* 4) termina comunicacoes com os exploradores */


    return 0;
}
