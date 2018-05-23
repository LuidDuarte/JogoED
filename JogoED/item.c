#include "item.h"
#include <allegro5\allegro.h>
#include "personagem.h"

void verificaPegouItem(personagem p, lista *pegar, lista *inventario) {
	no *aux = *pegar;
	bool pegou = false;
	while ((aux != NULL) && (pegou == false)) {	
		if ((aux->objeto.mX == p.x) && (aux->objeto.mY == p.y)) {
			no *aux2 = aux;
			removerNo(pegar, aux);
			mudaNo(inventario, aux2);
			pegou = true;
		}
		else aux = aux->prox;
	}
}
void removerNo(lista *l, no *n) {
	no *aux = *l;
	if (n == *l) { //Primeiro da lista
	*l = aux->prox;
	}
	else {
		bool removeu = false;
		no* aux = *l;
		while(aux != NULL && aux->prox != n){
			aux = aux->prox;
		}
		aux->prox = n->prox;
	}
	while (aux->prox != NULL) {
		aux->prox->objeto.bX -= 55;
		aux = aux->prox;
	}
}


void moveItens(lista *pegar, int x, int y) {
	no *aux = *pegar;
	while (aux != NULL) {
		aux->objeto.cX += x;
		aux->objeto.cY += y;
		aux = aux->prox;
	}
}

void adicionaNo(lista *l, no *n) {
	no *aux = n;
	aux->objeto.bX = posXPegar;
	aux->objeto.bY = posYPegar;
	posXPegar += 55;

	if (*l == NULL) {
		aux->prox = NULL;
		*l = aux;
	}
	else {
		aux = *l;
		while (aux->prox != NULL) 
			aux = aux->prox;
		
		n->prox = aux->prox;
		aux->prox = n;
	}

}

void mudaNo(lista *l, no *n) {
	no *aux = n;
	aux->objeto.bX = posXInvetario;
	aux->objeto.bY = posYInvetario;
	posXInvetario += 55;

	if (*l == NULL) {
		aux->prox = NULL;
		*l = aux;
	}
	else {
		aux = *l;
		while (aux->prox != NULL)
			aux = aux->prox;

		n->prox = aux->prox;
		aux->prox = n;
	}

}

void mostraListaInventario(lista *l) {
	no *aux = *l;
	if (l != NULL) {
		while (aux != NULL) {
			al_draw_bitmap(aux->objeto.item, aux->objeto.bX, aux->objeto.bY, 0);
			aux = aux->prox;
		}
	}
}

void mostraItemMapa(lista *l) {
	no *aux = *l;
	if (l != NULL) {
		while (aux != NULL) {
			al_draw_bitmap(aux->objeto.item, aux->objeto.cX, aux->objeto.cY, 0);
			aux = aux->prox;
		}
	}
}

void inicializaLista(lista *l) {
	*l = NULL;
}