#include <allegro5\allegro.h>
#ifndef MAPA_H
#define MAPA_H
typedef struct mapa {
	int x;
	int y;
	ALLEGRO_BITMAP *imagem;
}mapa;

extern int map1[16][30];

void mapaMatriz(int);
#endif