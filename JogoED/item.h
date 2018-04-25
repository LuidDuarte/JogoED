#include <allegro5\allegro.h>
#include "personagem.h"
#ifndef ITEM_H
#define ITEM_H

typedef struct obj { // cY e cX são em PX's 
	int cY;
	int cX;
	//posição na matriz
	int mY;
	int mX;
	ALLEGRO_BITMAP *item;

}obj;

static int posXPegar = 300;
static int posYPegar = 640;
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
void moveItens(lista *pegar, int x, int y);
void mostraItemMapa(lista *l);
void mostraListaInventario(lista *l);


#endif // !ITEM_H
