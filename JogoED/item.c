#include "item.h"
#include <allegro5\allegro.h>
#include "personagem.h"

void verificaPegouItem(personagem p, lista *pegar, lista *inventario) {
	no *aux = *pegar;
	bool pegou = false;
	while ((aux != NULL) && (pegou == false)) {		
		if ((aux->objeto.mX == p.x) && (aux->objeto.mY == p.y)) {
			adicionaNo(inventario, aux);
			removerNo(pegar, aux);
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