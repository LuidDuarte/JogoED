#include "item.h"
#include <allegro5\allegro.h>
//#include "personagem.h"

void verificaPegouItem(personagem p, lista *pegar, lista *inventario) {
	printf("\nP = [%d][%d]\n", p.x, p.y);
	no *aux = *pegar;
	bool pegou = false;
	while ((aux != NULL) && (pegou == false)) {		
		printf("I = [%d][%d]\n", (aux->objeto.mX), (aux->objeto.mY));
		if ((aux->objeto.mX == p.x) && (aux->objeto.mY== p.y)) {
			adicionaNo(&inventario, aux);
			remover(&pegar, aux);
			pegou = true;
		}
		else		aux = aux->prox;
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


void remover(lista *l, no *n) {
	if (n == *l) { 
		*l = n->prox;
		free(n);
	}
	else {
		no* aux = *l;
		while (aux->prox != NULL && aux->prox != n) {
			aux = aux->prox;
		}

		aux->prox = n->prox;
		free(n);
	}

}

void adicionaNo(lista *l, no *n) {
/*	else {
		no *aux = l;
		do{
			if (aux->prox == NULL) {
				aux->prox = n;
				n->prox = NULL;
			}
//		}while (aux->prox != NULL);
*/		printf("[%d][%d]\n", n->objeto.mX, n->objeto.mY);
//		}
}