#include <allegro5\allegro.h>
#include "personagem.h"
#include "mapa.h"
#ifndef ITEM_H
#define ITEM_H

typedef struct obj { 
	//Coordenada mapa;
	int cY;
	int cX;
	//posição na matriz
	int mY;
	int mX;
	//Coordenada x,y (em px) para borda
	int bY;
	int bX;
	ALLEGRO_BITMAP *item;

}obj;

static int posXPegar = 355;
static int posYPegar = 430;
static int posXInvetario = 475;
static int posYInvetario = 535;
typedef struct no {
	obj objeto;
	struct no* prox;
}no;

typedef no* lista;

void verificaPegouItem(personagem p, lista *pegar, lista *inventario);
void removerNo(lista *l, no *n);
void adicionaNo(lista *l, no *n);
void mudaNo(lista *l, no *n);
void moveItens(lista *pegar, int x, int y);
void mostraItemMapa(lista *l);
void mostraListaInventario(lista *l);
void inicializaLista(lista *l);
no *criaNo(int listaPegar);
void inicializaGame(lista*, lista*, lista*, mapa*,  personagem*);

#endif // !ITEM_H
