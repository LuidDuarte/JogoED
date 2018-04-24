#include <allegro5\allegro.h>
#include "personagem.h"
#ifndef ITEM_H
#define ITEM_H

typedef struct obj { // cY e cX s�o em PX's 
	int cY;
	int cX;
	//posi��o na matriz
	int mY;
	int mX;
	ALLEGRO_BITMAP *item;
}obj;

typedef struct no {
	obj objeto;
	struct no* prox;
}no;

typedef no* lista;

void verificaPegouItem(personagem p, lista *pegar, lista *inventario);
void remover(lista *l, no *n);
void adicionaNo(lista *l, no *n);
void moveItens(lista *pegar, int x, int y);


#endif // !ITEM_H
