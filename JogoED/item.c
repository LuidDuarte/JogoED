#include "item.h"
#include <allegro5\allegro.h>
#include "personagem.h"

void verificaPegouItem(personagem p, lista *pegar, lista *inventario) {
	no *aux = *pegar;
	bool pegou = false;
	printf("\nP = [%d][%d]\n", p.x, p.y);
	while ((aux != NULL) && (pegou == false)) {	
		printf("G = [%d][%d]\n", aux->objeto.mX, aux->objeto.mY);
		if ((aux->objeto.mX == p.x) && (aux->objeto.mY == p.y)) {
			no *aux2 = aux;
			removerNo(pegar, aux);
			adicionaNo(inventario, aux2);
			pegou = true;
		}
		else aux = aux->prox;
	}
}
void removerNo(lista *l, no *n) {
	no *aux = *l;
	if (n == *l) { //Primeiro da lista
	printf("irrul");
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
	aux->objeto.cX = posXInvetario;
	aux->objeto.cY = posYInvetario;
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
			al_draw_bitmap(aux->objeto.item, aux->objeto.cX, aux->objeto.cY, 0);
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