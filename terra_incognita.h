#ifndef TERRA_INCOGNITA_H
#define TERRA_INCOGNITA_H

#define MAX_EXPLORADORES 1000

#define TERRA_INCOGNITA 0
#define TERRA_PLANICIE 1
#define TERRA_FLORESTA 2
#define TERRA_MONTANHA 3
#define TERRA_AGUA 4

typedef int cellulae_func(int, int);

// Realiza as inicializações necessárias para a comunicação com os exploradores.
// Os primeiros dois parâmetros (argc e argv) são os argumentos do programa,
// recebidos através da função main. É devolvido por referência o número de
// exploradores (nExplorator) e as coordenadas relativas de todos os exploradores
// (vetor bidimensional positio, onde positio[i][0] e positio[i][1] indicam
// respetivamente as coordenadas horizontal e vertical do explorator com
// identificador i).
void intro(int argc, char *argv[], int *nExplorator, int positio[][2]);


// Usada para efetuar comunicação com um explorador e deve ser chamada
// repetidamente, enquanto existirem movimentações. Retorna o movimento que
// foi realizado (de acordo com as 4 direções indicadas anteriormente). São ainda
// devolvidos por referência o identificador do explorador (id) que se movimentou
// e o tipo de terreno encontrado (typus). Quando não há mais movimentos a
// efetuar, é retornado o valor 'X'. Nota: não deve ser assumida qualquer ordem
// para os exploradores.
char explorator(int *id, int *typus);


// Imprime o mapa cartografado. O primeiro parâmetro é um apontador para uma
// função que tenha uma definição compatível com cellulae_func - ver explicação
// mais a baixo. Os outros dois parâmetros indicam a largura (lat) e altura (alt) do
// mapa cartografado.
void tabula(cellulae_func *cell, int lat, int alt);


// Verifica a veracidade do mapa cartografado, imprimindo o número de células
// certas e erradas. Os parâmetros são os mesmos da função tabula.
void veritas(cellulae_func *cell, int lat, int alt);


// Finaliza as comunicações com os exploradores.
void relinquo();

#endif