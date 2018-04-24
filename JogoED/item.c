#include "item.h"
#include <allegro5\allegro.h>
#include "personagem.h"

void verificaPegouItem(personagem p, lista *pegar, lista *inventario) {
	system("cls");
	printf("\nP = [%d][%d]\n", p.x, p.y);
	no *aux = *pegar;
	bool pegou = false;
	while ((aux != NULL) && (pegou == false)) {		
		printf("I = [%d][%d]\n", (aux->objeto.mX), (aux->objeto.mY));
		if ((aux->objeto.mX == p.x) && (aux->objeto.mY == p.y)) {
			remover(pegar, aux);
			pegou = true;			
		}
		else aux = aux->prox;
	}
}
void remover(lista *l, no *n) {
	no *aux = *l;
	printf("[%d][%d]", n->objeto.mX, n->objeto.mX);
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

}