#include <allegro5\allegro.h>
#include "personagem.h"
#include "mapa.h"

#ifndef ITEM_H
#define ITEM_H

typedef struct obj { 
	int id;
	//Coordenada mapa;
	int cY;
	int cX;
	//posição na matriz
	int mY;
	int mX;
	//Coordenada x,y (em px) para borda
	int bY;
	int bX;
	char item[300];

}obj;

typedef struct elemento {
	obj objeto;
	struct elemento *prox;
}elemento;

// Globais.
static int posXPegar = 105;
static int posYPegar = 430;
static int posXInventario = 275;
static int posYInventario = 535;

obj criaObjeto(int num);
obj criaElevador();

/*
void inicializaLista(lista *l);
void inicializaGame(lista*, lista*, lista*, mapa*,  personagem*);
*/
#endif // !ITEM_H
