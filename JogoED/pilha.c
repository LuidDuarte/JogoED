#include <allegro5\allegro5.h>
#include <allegro5\allegro_image.h>
#include "item.h"
#include "mapa.h"
#include "personagem.h"
#include "pilha.h"

Pilha criaPilha() {
	Pilha *pi = (Pilha*)malloc(sizeof(Pilha));
	if (pi != NULL) {
		*pi = NULL;
	}
	return (*pi);
}

void destroiPilha(Pilha *pi) {
	if (pi != NULL) {
		while ((*pi) != NULL) {
			removePilha(pi);
		}
		pi = NULL;
	}
}

int inserePilha(Pilha *pi, obj objeto) {
	if (pi == NULL) return 0;
	elemento *no = (elemento*)malloc(sizeof(elemento));
	if (no == NULL) return 0;
	no->objeto = objeto;
	no->prox = (*pi);
	*pi = no;
	return 1;
}

int removePilha(Pilha *pi) {
	if (pi == NULL) return 0;
	if ((*pi) == NULL) return 0;
	elemento *no = *pi;
	*pi = no->prox;
	free(no);
	return 1;
}

int pilhaVazia(Pilha *pi) { //Para verificar se pilha vazia (ou pilha não existe), para evitar bugs.
	if ((*pi) == NULL || pi == NULL) return 1;
	else return 0;
}

obj topoPilha(Pilha *pi) { //Apenas para para retornar o objeto, como não há verificação, sempre certificar que a pilha contém elemento
	return (*pi)->objeto;
}

void mostraInventario(Pilha *inventario) {
	elemento *aux = *inventario;
	if (inventario != NULL) {
		while (aux != NULL) {
			al_draw_bitmap(al_load_bitmap(aux->objeto.item), aux->objeto.bX, aux->objeto.bY, 0);
			aux = aux->prox;
		}
	}
}